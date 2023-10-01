package main

import (
	"ex02/xargs"
)

func main() {
	xargs.Xargs()
}

// echo -e "/Users/alivewel\n/Users/alivewel" | go run main.go ls -la
// go build -o myXargs main.go
// echo -e "/Users/alivewel\n/Users/alivewel" | ./myXargs ls -la
