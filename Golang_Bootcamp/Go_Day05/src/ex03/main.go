package main

import (
	"fmt"
	"ex03/knapsack"
)

func main() {
	var presents = knapsack.Presents{
    knapsack.Present{
			Value: 0,
			Size:  0,
    },
    knapsack.Present{
			Value: 60,
			Size:  10,
    },
    knapsack.Present{
			Value: 100,
			Size:  20,
    },
    knapsack.Present{
			Value: 120,
			Size:  30,
    },
	}

	lenPres := len(presents) - 1
	capacity := 50

	result := knapsack.GrabPresents(presents, lenPres, capacity)
	fmt.Println("GrabPresents: ", result)
}