package xargs

import (
	"bufio"
	"fmt"
	"os"
	"os/exec"
	"strings"
)

func Xargs() {
	if len(os.Args) < 3 {
		fmt.Println("Usage: ./myXargs <command> <args...>")
		return
	}

	command := os.Args[1]
	args := os.Args[2:]

	scanner := bufio.NewScanner(os.Stdin)
	// считываем директории из командной строки
	var directories []string
	for scanner.Scan() {
		dir := scanner.Text() // разбиваем строку по разделителю \n
		directories = append(directories, dir) // записываем в слайс
	}

	for _, directory := range directories {
		directory := strings.ReplaceAll(directory, " ", "") // убираем пробелы из строки
		cmd := exec.Command(command, append(args, directory)...)

		// fmt.Println("cmd", cmd) // итоговая команда
		output, err := cmd.CombinedOutput()
		if err != nil {
			fmt.Printf("Error running %s: %s\n", command, err)
			return
		}
		fmt.Println(string(output))
	}
}
