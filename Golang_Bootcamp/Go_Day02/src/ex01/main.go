package main

import (
	"ex01/wc"
)

func main() {
	wc.Wc()
}

// go run main.go -l -m -w text1.txt text2.txt 
// go build -o myWc main.go
// ./myWc -w text1.txt text2.txt 