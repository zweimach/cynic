package main

import (
	"fmt"
	"os"
	"path"
)

func main() {
	homeDir, err := os.UserHomeDir()
	handleErr(err)
	filePath := path.Join(homeDir, ".bashrc")
	result, err := os.ReadFile(filePath)
	handleErr(err)
	_, err = fmt.Println(string(result))
	handleErr(err)
}

func handleErr(err error) {
	if err == nil {
		return
	}
	_, err_ := fmt.Println(err)
	if err_ == nil {
		os.Exit(1)
	}
	panic(err)
}
