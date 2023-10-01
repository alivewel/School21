package main

import (
	"flag"
	"ex00/Dbreader"
)

func main() {
	filename := flag.String("f", "", "Имя файла для чтения")
	flag.Parse()
	Dbreader.HandleErrorFilename(*filename)
	
	parserData, err := Dbreader.ReadFromFile(*filename)
	Dbreader.HandleError(err)
  
	parser := Dbreader.DetectFormat(parserData)
  
	recipes := new(Dbreader.Recipes)
	err2 := parser.Read(parserData, &recipes)
	Dbreader.HandleError(err2)
  
	// Dbreader.PrintJSON(recipes)
	Dbreader.PrintJSON(recipes)
}

// go run main.go -f original_database.xml
// go run main.go -f stolen_database.json
// go build -o readDB main.go
// ./readDB -f original_database.xml
// ./readDB -f stolen_database.json