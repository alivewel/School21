package main

import (
	"bytes"
	"encoding/csv"
	"encoding/json"
	"fmt"
	"github.com/elastic/go-elasticsearch/v7"
	"log"
	"net/http"
	"os"
	"strconv"
	"strings"
	"sync"
)

type DBReader interface {
	Read(filePath string) (Schema, error)
}

type JsonReader struct{}

type PropertiesType struct {
	Type string `json:"type"`
}

type Properties struct {
	Address  PropertiesType `json:"address"`
	Id       PropertiesType `json:"id"`
	Location PropertiesType `json:"location"`
	Name     PropertiesType `json:"name"`
	Phone    PropertiesType `json:"phone"`
}

type Schema struct {
	Properties Properties `json:"properties"`
}

type Location struct {
	Longitude float64 `json:"lon"`
	Latitude  float64 `json:"lat"`
}

type Place struct {
	Address  string   `json:"address"`
	Id       int      `json:"id"`
	Location Location `json:"location"`
	Name     string   `json:"name"`
	Phone    string   `json:"phone"`
}

func (j *JsonReader) Read(filePath string) (Schema, error) {
	b := getDataFromFile(filePath)
	var r Schema

	if !json.Valid(b) {
		err := fmt.Errorf("Not valid JSON")
		return Schema{}, err
	}
	err := json.Unmarshal(b, &r)
	if err != nil {
		return Schema{}, err
	}

	return r, nil
}

func readDB(filePath string, reader DBReader) Schema {
	res, err := reader.Read(filePath)
	if err != nil {
		log.Fatalln("Error reading file.", err)
	}
	return res
}

func getDataFromFile(path string) []byte {
	data, err := os.ReadFile(path)
	if err != nil {
		fmt.Println("File does not exists")
		os.Exit(1)
	}
	return data
}

func createIndex(indexName string, es *elasticsearch.Client) error {
	if _, err := es.Indices.Delete([]string{indexName}); err != nil {
		return err
	}

	res, err := es.Indices.Create(indexName)
	if err != nil {
		return err
	}
	if res.IsError() {
		// return errors.New("error")
		return fmt.Errorf("failed to create index: %s", res.String())
	}
	return nil
}

func mappingIndex(indexName string, es *elasticsearch.Client) error {
	// Marshal json file
	schema := readDB("schema.json", new(JsonReader))

	// // Вывести считанный объект в консоль для проверки
	// fmt.Printf("Считанный объект Schema: %+v\n", schema)

	schema.Properties.Id.Type = "long"
	schemaBytes, err := json.Marshal(schema)
	if err != nil {
		return err
	}

	url := "http://localhost:9200/"

	req, err := http.NewRequest(http.MethodPut, url+indexName+"/place/_mapping", bytes.NewBuffer(schemaBytes))
	if err != nil {
		return err
	}
	req.Header.Set("Content-Type", "application/json")
	q := req.URL.Query()
	q.Add("include type name", "true")
	req.URL.RawQuery = q.Encode()

	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		return err
	}
	defer resp.Body.Close()

	return nil
}

func getDataFromCSV(pathToCSV string) ([][]string, error) {
	file, err := os.Open(pathToCSV)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	reader := csv.NewReader(file)
	reader.Comma = '\t'

	lines, err := reader.ReadAll()
	if err != nil {
		return nil, err
	}
	return lines, nil
}

func pushIntoES(indexName string, line []string, es *elasticsearch.Client, idx int) error {
	id := strconv.Itoa(idx)

	longitude, err := strconv.ParseFloat(line[4], 64)
	if err != nil {
		return err
	}
	latitude, err := strconv.ParseFloat(line[5], 64)
	if err != nil {
		return err
	}
	place := Place{
		Id:      idx,
		Address: line[2],
		Location: Location{
			Longitude: longitude,
			Latitude:  latitude,
		},
		Name:  line[1],
		Phone: line[3],
	}

	data, err := json.Marshal(place)
	if err != nil {
		return err
	}
	resp, err := es.Index(indexName, strings.NewReader(string(data)), es.Index.WithDocumentID(id))
	if err != nil {
		return err
	}
	defer resp.Body.Close()

	return nil
}

func fillDataFromCSV(indexName, pathToCSV string, es *elasticsearch.Client) error {
	lines, err := getDataFromCSV(pathToCSV)

	// Вывести считанные строки в консоль для проверки
	// for _, line := range lines {
	// 	fmt.Printf("Считанная строка: %+v\n", line)
	// }

	if err != nil {
		return err
	}
	var wg sync.WaitGroup

	for idx, line := range lines[1:] { // 1: чтобы шапку файла не захватывать
		wg.Add(1)
		line := line
		idx := idx
		go func() {
			defer wg.Done()
			err = pushIntoES(indexName, line, es, idx)
			if err != nil {
				fmt.Println("Error push data inro elastic:", err)
			}
		}()
	}
	wg.Wait()

	return nil
}

func getClientConnection() *elasticsearch.Client {
	httpClient := &http.Client{
		Transport: &http.Transport{
			MaxIdleConnsPerHost: 100,
			MaxConnsPerHost:     100,
		},
	}

	// Create ES client
	es, err := elasticsearch.NewClient(elasticsearch.Config{
		Addresses: []string{"http://localhost:9200"},
		Transport: httpClient.Transport,
	})
	if err != nil {
		log.Fatalf("Error creating the client: #{err}\n")
	}
	return es
}

func main() {
	indexName := "places"

	es := getClientConnection()

	err := createIndex(indexName, es)
	if err != nil {
		log.Fatalf("Error creating the index: #{err}\n")
	}

	err2 := mappingIndex(indexName, es)
	if err2 != nil {
		log.Fatalf("Error mapping the index: #{err}\n")
	}

	// err3 := fillDataFromCSV(indexName, "dataTest.csv", es)
	err3 := fillDataFromCSV(indexName, "data.csv", es)
	if err3 != nil {
		log.Fatalf("Error fill data from CSV: %s\n", err)
	}
}
