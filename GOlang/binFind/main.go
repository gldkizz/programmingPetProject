package main

import (
	"fmt"
)

func binFind(arr []int, index int, num int, len int, c int) int {
	if len > index {
		if arr[index] == num {
			fmt.Println("\t\tКоличество проходов:", c)
			return index
		} else if num > index {
			c++
			return binFind(arr, index+1, num, len, c)
		} else {
			c++
			return binFind(arr, index-1, num, len, c)
		}
	}
	return -1
}

func bubbleSort(arr []int) []int {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr)-1; j++ {
			if arr[j] > arr[j+1] {
				per := arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = per
			}
		}
	}
	return arr
}

func main() {
	var num int
	arr := []int{2, 4, 6, 8, 1, 3, 5, 7}
	fmt.Println(bubbleSort(arr))
	fmt.Print("\t\tВведите искомое значение: ")
	fmt.Scan(&num)
	fmt.Println("\t\tИндекс искомого значения:", (binFind(bubbleSort(arr), len(arr)/2, num, len(arr), 0)))
}
