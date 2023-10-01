package rotate

import (
	"archive/zip"
	"flag"
	"fmt"
	"io"
	"os"
	"strings"
	"strconv"
	"sync"
	"time"
)

func HandleError(err error) {
  if err != nil {
   fmt.Println(err)
   os.Exit(1)
  }
}

func HandleErrorFilename(files []string) {
  if len(files) == 0 {
		fmt.Println("No files specified.")
		os.Exit(1)
	}
}

func ArchiveFiles(fileName string, directory string, wg *sync.WaitGroup) {
	defer wg.Done()
	fileNameWithoutLog := strings.TrimSuffix(fileName, ".log")
	
	currentTime := time.Now() // текущая даты и времени
	timestamp := currentTime.Unix() // временной метки UNIX (секунды с начала эпохи)
	timestampStr := strconv.FormatInt(timestamp, 10) // перевод в строку
	
	archiveName := directory + fileNameWithoutLog + "_" + timestampStr + ".tar.gz"
	// Создаем новый архив
	archiveFile, err := os.Create(archiveName)
	HandleError(err)
	defer archiveFile.Close()
	
	// Создаем новый писатель архива
	zipWriter := zip.NewWriter(archiveFile)
	defer zipWriter.Close()

	// Добавляем файлы в архив
	fileToAdd, err := os.Open(fileName)
	HandleError(err)
	defer fileToAdd.Close()

	// Создаем файл внутри архива
	fileInArchive, err := zipWriter.Create(fileName)
	HandleError(err)

	// Копируем содержимое файла в файл внутри архива
	_, err = io.Copy(fileInArchive, fileToAdd)
	HandleError(err)
}

func Rotate() {
	directory := flag.String("a", "", "Директория создания архива")
	flag.Parse()
	if *directory != "" {
		*directory = *directory + "/"
	}

	fileNames := flag.Args() // Получение списка файлов после флагов
	HandleErrorFilename(fileNames)

	var wg sync.WaitGroup
	for _, fileName := range fileNames {
		wg.Add(1)
		go ArchiveFiles(fileName, *directory, &wg)
	}
	wg.Wait()
}