package main

import (
	"fmt"
	"log"
)

func main() {
	_, err := fmt.Println("Hello, World!")
	if err != nil {
		log.Panic(err)
	}
}
