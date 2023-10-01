package knapsack

type Present struct {
	Value int
	Size int
}

type Presents []Present

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func GrabPresents(presents Presents, lenPres, capacity int) Present {
	m := make([][]int, lenPres+1)
	for i := range m {
		m[i] = make([]int, capacity+1)
	}
	for j := 0; j <= capacity; j++ {
		m[0][j] = 0
	}

	for i := 1; i <= lenPres; i++ {
		m[i][0] = 0
	}

	for i := 1; i <= lenPres; i++ {
		for j := 1; j <= capacity; j++ {
			if presents[i].Size > j {
				m[i][j] = m[i-1][j]
			} else {
				m[i][j] = max(m[i-1][j], m[i-1][j-presents[i].Size]+presents[i].Value)
			}
			// fmt.Printf("%3d ", m[i][j])
		}
		// fmt.Println()
	}
	return Present{m[lenPres][capacity], capacity}
}
