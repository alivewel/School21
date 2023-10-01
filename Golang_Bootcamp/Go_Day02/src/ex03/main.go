package main

import (
	"ex03/rotate"
)

func main() {
	rotate.Rotate()
}

// go run main.go some_application.log other_application.log
// go run main.go -a /Users/alivewel/Go/Day02 some_application.log other_application.log
// go build -o myRotate main.go
// ./myRotate some_application.log other_application.log
