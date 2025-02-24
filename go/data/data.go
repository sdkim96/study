package main

import "fmt"

type Data struct {
	Char string
	id   int
}

func main() {

	char := "Hello, World!"

	formattedChar := fmt.Sprintf("%s", char)
	data := Data{
		Char: formattedChar,
		id:   1,
	}
	fmt.Sprintf("%v", data)
	fmt.Println(data)
	fmt.Println(formattedChar)
	fmt.Println("Hello, World!")
}
