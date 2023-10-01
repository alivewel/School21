package FSCompare

import (
	"fmt"
	"os"
	"strings"
	"io/ioutil"
)


func ReadDataFromFile(filename string) ([]string, error) {
	data, err := ioutil.ReadFile(filename)
	if err != nil {
		return nil, fmt.Errorf("Ошибка чтения файла: %v", err)
	}

	lines := strings.Split(string(data), "\n")
	return lines, nil
}

func CompareSnapshots(filePathsOld []string, filePathsNew []string) {
	addPathsMap := make(map[string]bool)
	removedPathsMap := make(map[string]bool)

	// Обрабатываем пути из filePathsOld и помечаем их как обработанные
	for _, filePath := range filePathsOld {
		addPathsMap[filePath] = true
	}
	// Обрабатываем пути из filePathsNew и помечаем их как обработанные
	for _, filePath := range filePathsNew {
		removedPathsMap[filePath] = true
	}

	for _, filePath := range filePathsNew {
		if !addPathsMap[filePath] {
			fmt.Printf("ADDED %s\n", filePath)
		}
	}
	for _, filePath := range filePathsOld {
		if !removedPathsMap[filePath] {
			fmt.Printf("REMOVED %s\n", filePath)
		}
	}
}

func HandleErrorFilename(filename string) {
  if filename == "" {
		fmt.Println("Необходимо указать имя файла через флаг --old и --new")
		os.Exit(1)
	}
}

func HandleError(err error) {
  if err != nil {
   fmt.Println(err)
   os.Exit(1)
  }
}