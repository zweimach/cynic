package main

func main() {
	t := NewLinkedList(12)
	println(t.value)
}

type LinkedList[T any] struct {
	value T
	next  *LinkedList[T]
}

func NewLinkedList[T any](value T) LinkedList[T] {
	return LinkedList[T]{value: value, next: nil}
}
