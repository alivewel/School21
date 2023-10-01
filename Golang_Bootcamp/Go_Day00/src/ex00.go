package main

import (
	"fmt"
  "flag"
	"strconv"
  "math"
  "strings"
  "sort"
)

func inputNumbers() []float64 {
	var input string
	mySlice := make([]float64, 0)
	fmt.Println("Введите элементы (для завершения введите 'stop'):")
	for {
		_, err := fmt.Scan(&input)
		if err != nil {
			fmt.Println("Ошибка ввода:", err)
			break
		}
    input = strings.TrimSpace(input) // Удаление пробелов и символов новой строки
    if input == "stop" {
			break
		}
		num, err := strconv.ParseFloat(input, 64)
		if err != nil {
			fmt.Println("Ошибка преобразования в число:", err)
			continue
		}
    formattedNum, err := strconv.ParseFloat(fmt.Sprintf("%.2f", num), 64) // Округление до двух десятичных знаков
		if err != nil {
			fmt.Println("Ошибка форматирования числа:", err)
			continue
		}
    if formattedNum > 100000 || formattedNum < -100000 {
			fmt.Println("Число выходит за границы от -100 000 до 100 000")
			continue
		}
		mySlice = append(mySlice, formattedNum)
	}
  return mySlice
}

func calculateMean(numbers []float64) float64 {
  if len(numbers) == 0 {
		return 0.0
	}

	mean := 0.0
  var amount float64 = float64(len(numbers))
	// Нормализуем числа, деля каждое число на сумму всех чисел
	for _, num := range numbers {
		mean += num / amount
	}

  return math.Round(mean * 100) / 100
}

func calculateMedian(numbers []float64) float64 {
  n := len(numbers)
  if n == 0 {
		return 0.0 // Возвращаем нуль или другое значение в случае пустого слайса
	}

  sort.Slice(numbers, func(i, j int) bool { // сортировка
    return numbers[i] < numbers[j]
  })

  if n % 2 == 1 { // Нечетное количество элементов
   return math.Round(numbers[n / 2] * 100) / 100
  } else { // Четное количество элементов
   mid1 := numbers[n / 2 - 1]
   mid2 := numbers[n / 2]
   average := (mid1 + mid2) / 2
   return math.Round(average * 100) / 100
  }
}

// return true if a > b
func greaterThan(a, b float64) bool {
  return a - b > 1e-9
}

func calculateMode(numbers []float64) float64 {
	frequency := make(map[float64]float64) // карта для подсчета частоты чисел

	// Подсчет частоты встречаемости чисел
	for _, num := range numbers {
		frequency[num]++
	}

	// Поиск числа с наибольшей частотой
	maxFrequency := 0.0
	mode := 0.0

	for num, freq := range frequency {
    if greaterThan(freq, maxFrequency) {
			maxFrequency = freq
			mode = num
		}
	}
	return mode
}

func regularStandardDeviation(numbers []float64) float64 {
	n := len(numbers)
	if n <= 1 {
		return 0.0 // Возвращаем ноль для наборов данных с одним или менее элементами
	}

  mean := calculateMean(numbers)
	diffSquares := make([]float64, n) // Создаем слайс с нужной длиной

	for i, num := range numbers {
		diff := num - mean
		diffSquares[i] = diff * diff
	}

	variance := calculateMean(diffSquares)
	regularStandardDev := math.Sqrt(variance)
	return math.Round(regularStandardDev * 100) / 100
}

func main() {
  result := inputNumbers()

  meanFlag := flag.Bool("mean", false, "Print the mean")
	medianFlag := flag.Bool("median", false, "Print the median")
	modeFlag := flag.Bool("mode", false, "Print the mode")
	sdFlag := flag.Bool("sd", false, "Print the standard deviation")

	// Парсинг аргументов командной строки
	flag.Parse()

	// Вывод запрошенных метрик
	if *meanFlag {
    mean := calculateMean(result)
    fmt.Println("Mean:", mean)
	}
	if *medianFlag {
    median := calculateMedian(result)
    fmt.Println("Median:", median)
	}
	if *modeFlag {
    mode := calculateMode(result)
    fmt.Println("Mode:", mode)
	}
	if *sdFlag {
    sd := regularStandardDeviation(result)
    fmt.Println("SD:", sd)
	}
}

// go run ex00.go -mean -median -mode -sd
