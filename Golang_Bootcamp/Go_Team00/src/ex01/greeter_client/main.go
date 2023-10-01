// Package main implements a client for Greeter service.
package main

import (
	"context"
	"flag"
	"fmt"
	"log"
	"strings"
	"time"
	"io"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
	pb "transmitter/transmitter"
	"github.com/golang/protobuf/ptypes/empty"
)

const (
	defaultName = "world"
)

var (
	addr = flag.String("addr", "localhost:50051", "the address to connect to")
	name = flag.String("name", defaultName, "Name to greet")
	k float64
)

func main() {
	flag.Float64Var(&k, "floatFlag", 1.2, "Deviation coefficient")
	flag.Parse()
	// Set up a connection to the server.
	conn, err := grpc.Dial(*addr, grpc.WithTransportCredentials(insecure.NewCredentials()))
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer conn.Close()
	c := pb.NewGreeterClient(conn)

	// Contact the server and print out its response.
	ctx, cancel := context.WithTimeout(context.Background(), 10 * time.Second)
	defer cancel()

	// Вызываем метод ResponseMethod для получения потока данных
	stream, err := c.ResponseMethod(ctx, &empty.Empty{})
	if err != nil {
		log.Fatalf("could not call ResponseMethod: %v", err)
	}
	
	
	for {
		// Получаем ответ из потока
		response, err := stream.Recv()
		if err == io.EOF {
			// Поток завершен
			break
		}
		if err != nil {
				log.Fatalf("failed to receive a response : %v", err)
		}

		// Используем ответ
		log.Printf("Session ID: %s", response.SessionId)
		log.Printf("Frequency: %f", response.Frequency)
		log.Printf("Timestamp: %v", response.Timestamp.AsTime())
		fmt.Println(strings.Repeat("-", 70))
	}
}
