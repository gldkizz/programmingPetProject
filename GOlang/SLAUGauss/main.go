package main

import (
 "fmt"
 "math"
)

func outData(numEq int, A [][]float64, Y []float64) {
	for i := 0; i < numEq; i++ {
  		for j := 0; j < numEq; j++ {
   			fmt.Printf("%.2f*x%d", A[i][j], j)
			if j < numEq-1 {
				fmt.Print(" + ")
			}
		}
		fmt.Printf(" = %.2f\n", Y[i])
 	}
}

func gauss(A [][]float64, Y []float64, numEq int) []float64 {
	X := make([]float64, numEq)

	for i := 0; i < numEq; i++ {
		maxEl := math.Abs(A[i][i])
		maxRow := i
		for j := i + 1; j < numEq; j++ {
			if math.Abs(A[j][i]) > maxEl {
				maxEl = math.Abs(A[j][i])
				maxRow = j
			}
		}

		// Перестановка строк
		A[maxRow], A[i] = A[i], A[maxRow]
		Y[maxRow], Y[i] = Y[i], Y[maxRow]

		// Приведение к треугольной форме
		for k := i + 1; k < numEq; k++ {
			coeff := A[k][i] / A[i][i]
			for j := i; j < numEq; j++ {
				A[k][j] -= coeff * A[i][j]
			}
			Y[k] -= coeff * Y[i]
		}
	}

	// Обратный ход
	for i := numEq - 1; i >= 0; i-- {
		X[i] = Y[i] / A[i][i]
		for k := i - 1; k >= 0; k-- {
			Y[k] -= A[k][i] * X[i]
		}
	}
	return X
	}

func main() {
	var numEq int
	fmt.Print("Введите количество уравнений: ")
	fmt.Scan(&numEq)

	A := make([][]float64, numEq)
	for i := range A {
		A[i] = make([]float64, numEq)
	}

	Y := make([]float64, numEq)

	for i := 0; i < numEq; i++ {
		for j := 0; j < numEq; j++ {
			fmt.Printf("A[%d][%d]: ", i, j)
			fmt.Scan(&A[i][j])
		}
	}

	for i := 0; i < numEq; i++ {
		fmt.Printf("y[%d]: ", i)
		fmt.Scan(&Y[i])
	}

	fmt.Println("Начальные данные:")
	outData(numEq, A, Y)

	X := gauss(A, Y, numEq)

	fmt.Println("Решения:")
	for i := 0; i < numEq; i++ {
	fmt.Printf("x[%d] = %.2f\n", i, X[i])
	}
}