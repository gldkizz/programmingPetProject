package main

import (
 "fmt"
)

func findDet(matr [][]int, n int) int {
	if n == 1 {
		return matr[0][0]
	} else if n == 2 {
		return matr[0][0]*matr[1][1] - matr[0][1]*matr[1][0]
	} else {
		det := 0
		for k := 0; k < n; k++ {
			subMatr := make([][]int, n-1)
			for i := range subMatr {
				subMatr[i] = make([]int, n-1)
			}
			for i := 1; i < n; i++ {
				subCol := 0
				for j := 0; j < n; j++ {
					if j == k {
						continue
					}
					subMatr[i-1][subCol] = matr[i][j]
					subCol++
				}
			}
			sign := 1
			if k%2 != 0 {
				sign = -1
			}
			det += sign * matr[0][k] * findDet(subMatr, n-1)
		}
		return det
	}
}

func Kramer(matr [][]int, constants []int, n int) {
	det := findDet(matr, n)
	if det == 0 {
		fmt.Println("СЛАУ нельзя решить методом Крамера")
		return
	}

	res := make([]int, n)
	for i := 0; i < n; i++ {
		modMatr := make([][]int, n)
		for j := range modMatr {
			modMatr[j] = make([]int, n)
			copy(modMatr[j], matr[j])
			modMatr[j][i] = constants[j]
		}
		res[i] = findDet(modMatr, n) / det
	}

	for i := 0; i < n; i++ {
		fmt.Printf("x[%d]: %d\n", i, res[i])
	}
}

func main() {
	var n int
	fmt.Print("Введите кол-во неизвестных: ")
	fmt.Scan(&n)

	matr := make([][]int, n)
	for i := range matr {
		matr[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Printf("matr[%d][%d]: ", i+1, j+1)
			fmt.Scan(&matr[i][j])
		}
	}

	constants := make([]int, n)
	fmt.Println("Введите свободные члены")
	for i := 0; i < n; i++ {
		fmt.Printf("const[%d]: ", i+1)
		fmt.Scan(&constants[i])
	}

	Kramer(matr, constants, n)
}