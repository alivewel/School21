package main

import (
	"fmt"
	"container/heap"
	"ex02/editheap"
)


func main() {
	h := &editheap.Presents{
    editheap.Present{
			Value: 5,
			Size:  2,
    },
    editheap.Present{
			Value: 4,
			Size:  5,
    },
    editheap.Present{
			Value: 3,
			Size:  1,
    },
    editheap.Present{
			Value: 5,
			Size:  1,
    },
	}

	heap.Init(h)
	n := 3
	result := editheap.GetNCoolestPresents(*h, n)
	if result != nil {
		fmt.Println(result)
	}
	// for h.Len() > 0 {
	// 	present := heap.Pop(h).(Present)
	// 	fmt.Printf("%d %d\n", present.Value, present.Size)
	// }
}
