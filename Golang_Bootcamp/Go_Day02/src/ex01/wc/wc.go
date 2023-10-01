package wc

import (
	"fmt"
	"os"
	"strings"
	"sync"
	"unicode/utf8"
	"flag"
)


func ProcessFile(fileName string, flagLineCount bool, flagTotalChars bool, flagTotalWords bool, wg *sync.WaitGroup, numberFiles int) {
	defer wg.Done()
	
	file, err := os.Open(fileName)
	HandleError(err)
	// defer сработает при выходе из функции (отложенное выполнение)
	defer file.Close()

	buf := make([]byte, 1024) // Буфер для чтения байтов

	lineCount, totalChars, totalWords := 0, 0, 0
	prevHasNewline := false // Переменная для отслеживания наличия символа перевода строки в предыдущей итерации

	for {
		n, err := file.Read(buf)
		if err != nil {
			break
		}

		data := string(buf[:n])
		lines := strings.Split(data, "\n")

		for i, line := range lines {
			if i == len(lines)-1 {
				// Если строка не заканчивается символом перевода строки, увеличиваем счетчик
				if prevHasNewline || len(line) > 0 {
					lineCount++
				}
			} else {
				lineCount++
				prevHasNewline = true
			}
			totalChars += utf8.RuneCountInString(line)
			words := strings.Fields(line)
			totalWords += len(words)
		}
	}
	if flagLineCount {
		fmt.Printf("%8d", lineCount - 1)
	}
	if flagTotalWords {
		fmt.Printf("%8d", totalWords)
	}
	if flagTotalChars {
		fmt.Printf("%8d", totalChars + lineCount - 1)
	}
	fmt.Printf(" %s\n", fileName)
}

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

func Wc() {
	flagLineCount := flag.Bool("l", false, "Подсчет строк")
	flagTotalChars := flag.Bool("m", false, "Подсчет символов")
	flagTotalWords := flag.Bool("w", false, "Подсчет слов")
	flag.Parse()

	files := flag.Args() // Получение списка файлов после флагов
	numberFiles := len(files)
	HandleErrorFilename(files)

	var wg sync.WaitGroup
	for _, fileName := range files {
		wg.Add(1)
		
		go ProcessFile(fileName, *flagLineCount, *flagTotalChars, *flagTotalWords, &wg, numberFiles)
	}
	wg.Wait()
}
