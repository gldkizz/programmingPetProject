package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func atbashEncoder(inputData string) {
	for _, ch := range inputData {
		if unicode.IsLetter(ch) {
			if unicode.IsUpper(ch) {
				fmt.Print(string(90 - (ch - 65)))
			} else {
				fmt.Print(string(122 - (ch - 97)))
			}
		} else if unicode.IsDigit(ch) == false {
			fmt.Print(string(ch))
		}
	}
}

func atbashDecoder(inputData string) {
	for _, ch := range inputData {
		if unicode.IsLetter(ch) {
			if unicode.IsUpper(ch) {
				fmt.Print(string(90 - (ch - 65)))
			} else {
				fmt.Print(string(122 - (ch - 97)))
			}
		} else if unicode.IsDigit(ch) == false {
			fmt.Print(string(ch))
		}
	}
}

func Scan() string {
	in := bufio.NewScanner(os.Stdin)
	in.Scan()
	if err := in.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "Ошибка ввода:", err)
	}
	return in.Text()
}

func main() {
	var choise int
	var inputData string
	fmt.Println("1.Шифратор 	2.Дешифратор")
	fmt.Print("Выберите цифру: ")
	fmt.Scan(&choise)
	switch choise {
	case 1:
		{
			fmt.Println("Введите данные для шифрования")
			inputData = Scan()
			atbashEncoder(inputData)
			fmt.Println()
		}
	case 2:
		{
			fmt.Println("Введите данные для дешифрования")
			inputData = Scan()
			atbashDecoder(inputData)
			fmt.Println()
		}
	}
}
