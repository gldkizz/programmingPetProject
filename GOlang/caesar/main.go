package main

import (
	"fmt"
	"unicode"
)

func caesarROT(inputData string, rotNum int) {
	for _, ch := range inputData {
		if unicode.IsLetter((ch)) {
			fmt.Print(string(97 + ((int(ch) - 97 + rotNum) % 26)))
		} else if unicode.IsDigit(ch) {
			fmt.Print(string(48 + ((int(ch) - 48 + rotNum) % 10)))
		} else {
			fmt.Print(string(ch))
		}
	}
}

func main() {
	caesarROT("x123", 123564325)
	fmt.Println()
}
