// Package main implements a server for Greeter service.
package main

import (
	"context"
	"flag"
	"fmt"
	"log"
	"math/rand"
	"net"
	"os"
 
	"google.golang.org/grpc"
	pb "transmitter/transmitter"
	"google.golang.org/protobuf/types/known/timestamppb"
	"google.golang.org/protobuf/types/known/emptypb"
	"github.com/google/uuid"
	"gonum.org/v1/gonum/stat/distuv"
)

var (
	port = flag.Int("port", 50051, "The server port")
)

// server is used to implement helloworld.GreeterServer.
type server struct {
	pb.UnimplementedGreeterServer
	responseArray []*pb.Response
}

// SayHello implements helloworld.GreeterServer
func (s *server) SayHello(ctx context.Context, in *pb.HelloRequest) (*pb.HelloReply, error) {
	log.Printf("Received: %v", in.GetName())
	return &pb.HelloReply{Message: "Hello " + in.GetName()}, nil
}

func (s *server) ResponseMethod(empty *emptypb.Empty, srv pb.Greeter_ResponseMethodServer) error {
	// Логика обработки метода ResponseMethod
	newUUID := uuid.New()
	uuidString := newUUID.String()

	// Генерация среднего значения в интервале [-10, 10]
	mean := -10.0 + rand.Float64() * 20.0
	// Генерация стандартного отклонения в интервале [0.3, 1.5]
	stdDev := 0.3 + rand.Float64() * 1.2
	// Создание случайной величины с заданными параметрами
	rv := distuv.Normal{
			Mu:    mean,
			Sigma: stdDev,
	}
	// Генерация случайного значения
	frequency := rv.Rand()

	response := &pb.Response{
		SessionId: uuidString,
		Frequency: frequency,
		Timestamp:   timestamppb.Now(),
	}

	fmt.Printf("Session ID: %s\n", response.SessionId)
	fmt.Printf("Frequency: %f\n", response.Frequency)
	fmt.Printf("Timestamp: %s\n", response.Timestamp.AsTime())
	fmt.Println("-------------------------------------")

	s.responseArray = append(s.responseArray, response)

	outputPath := "server_log.txt"
	// Запись response в файл
	if err := writeResponseToFile(response, outputPath); err != nil {
		log.Printf("Error writing response to file: %v", err)
	}
	for _, response := range s.responseArray {
		if err := srv.Send(response); err != nil {
			return err
		}
	}
	return nil
}

// writeResponseToFile записывает данные из Response в файл по указанному пути.
func writeResponseToFile(response *pb.Response, filePath string) error {
	file, err := os.OpenFile(filePath, os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0644)
	if err != nil {
			log.Printf("Error opening file: %v", err)
			return err
	}
	defer file.Close()
	// Преобразование Response в строку
	responseStr := fmt.Sprintf("SessionID: %s\nFrequency: %f\nTimestamp: %s\n", response.SessionId, response.Frequency, response.Timestamp.AsTime())

	// Запись данных в файл
	_, err = file.WriteString(responseStr)
	return err
}

func main() {
	flag.Parse()
	lis, err := net.Listen("tcp", fmt.Sprintf(":%d", *port))
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	s := grpc.NewServer()
	pb.RegisterGreeterServer(s, &server{})
	log.Printf("server listening at %v", lis.Addr())
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}
