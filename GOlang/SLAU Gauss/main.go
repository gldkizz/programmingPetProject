package main

import (
	"fmt"
)

func outData(numEq int, A [][]int, Y []int ) {
	for i:= 0; i < numEq; i++ {
		for j:= 0; j < numEq; j++ {
			fmt.Print(A[i][j],"*x",j)
			if j < numEq - 1 {
				fmt.Print(" + ")
			}
		}
		fmt.Println(" =",Y[i])
	}
}

func main() {
	
}