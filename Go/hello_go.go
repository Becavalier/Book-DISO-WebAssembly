package main

import "fmt"

func add(a, b int) int {
  return a + b
}

func main() {
	fmt.Println("Hello, WebAssembly!")
	fmt.Println(add(10, 20))
}