package main

import (
  "flag"
	"ex01/Dbreader"
	"ex01/DBCompare"
)

func main() {
  filenameOld := flag.String("old", "", "Имя файла для чтения")
	filenameNew := flag.String("new", "", "Имя файла для чтения")
	flag.Parse()
  Dbreader.HandleErrorFilename(*filenameOld)
	Dbreader.HandleErrorFilename(*filenameNew)

	parserDataOld, errOld := Dbreader.ReadFromFile(*filenameOld)
	parserDataNew, errNew := Dbreader.ReadFromFile(*filenameNew)
	Dbreader.HandleError(errOld)
	Dbreader.HandleError(errNew)

  parserOld := Dbreader.DetectFormat(parserDataOld)
  recipesOld := new(Dbreader.Recipes)
  errOld2 := parserOld.Read(parserDataOld, &recipesOld)
  Dbreader.HandleError(errOld2)

	parserNew := Dbreader.DetectFormat(parserDataNew)
  recipesNew := new(Dbreader.Recipes)
  errNew2 := parserNew.Read(parserDataNew, &recipesNew)
  Dbreader.HandleError(errNew2)

	CompareDB.CompareRecipesName(recipesOld, recipesNew)
	CompareDB.CompareRecipes(recipesOld, recipesNew)

}

// go run main.go --old original_database.xml --new stolen_database.json

// go build -o compareDB main.go

// ./compareDB --old original_database.xml --new stolen_database.json