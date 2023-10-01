package editheap

import (
	"container/heap"
	"fmt"
)

type Present struct {
	Value int
	Size int
}

type Presents []Present

// Len, Less, Swap для реализации интерфейса sort.Interface
func (h Presents) Len() int           { return len(h) }
func (h Presents) Less(i, j int) bool {
	if h[i].Value == h[j].Value {
		return h[i].Size < h[j].Size
	}
	return h[i].Value > h[j].Value
}
func (h Presents) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *Presents) Push(x interface{}) {
	// Push и Pop используют приемники указателей, 
	// потому что они изменяют длину среза,
	// не только его содержимое.
	*h = append(*h, x.(Present))
}

func (h *Presents) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func GetNCoolestPresents(h Presents, n int) []Present {
	if n > h.Len() || n <= 0 {
		fmt.Printf("Invalid value of n\n")
		return nil
	}
	var coolestPresents Presents
	for i := n; i > 0; i-- {
		present := heap.Pop(&h).(Present)
		coolestPresents = append(coolestPresents, present)
		// fmt.Printf("%d %d\n", present.Value, present.Size)
	}
	return coolestPresents
}
