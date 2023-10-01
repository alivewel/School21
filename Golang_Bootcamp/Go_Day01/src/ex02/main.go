package main

import (
	"flag"
	"ex02/FSCompare"
)

func main() {
	filenameOld := flag.String("old", "", "Имя файла для чтения")
	filenameNew := flag.String("new", "", "Имя файла для чтения")
	flag.Parse()
  FSCompare.HandleErrorFilename(*filenameOld)
	FSCompare.HandleErrorFilename(*filenameNew)

	filePathsOld, errOld := FSCompare.ReadDataFromFile(*filenameOld)
	filePathsNew, errNew := FSCompare.ReadDataFromFile(*filenameNew)
	FSCompare.HandleError(errOld)
	FSCompare.HandleError(errNew)

	FSCompare.CompareSnapshots(filePathsOld, filePathsNew)
}

// go run main.go --old snapshot1.txt --new snapshot2.txt

// go build -o compareFS main.go

// ./compareFS --old snapshot1.txt --new snapshot2.txt
