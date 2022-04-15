package main

import (
	"fmt"
	"math"
)

func main() {
	var shape Shape
	shape = NewSquare(12.5)
	fmt.Printf("Square: area %.2f, perimeter %.2f\n", shape.Area(), shape.Perimeter())
	fmt.Printf("Total: %.2f\n", GetTotal(shape))
	shape = NewCircle(8.5)
	fmt.Printf("Circle: area %.2f, perimeter %.2f\n", shape.Area(), shape.Perimeter())
	fmt.Printf("Total: %.2f\n", GetTotal(shape))
}

func GetTotal(s Shape) float64 {
	return s.Area() + s.Perimeter()
}

type Shape interface {
	Area() float64
	Perimeter() float64
}

type Square struct {
	sides float64
}

func NewSquare(sides float64) Square {
	return Square{sides}
}

func (s Square) Area() float64 {
	return s.sides * s.sides
}

func (s Square) Perimeter() float64 {
	return s.sides * 4
}

type Circle struct {
	radius float64
}

func NewCircle(radius float64) Circle {
	return Circle{radius}
}

func (s Circle) Area() float64 {
	return s.radius * s.radius * math.Pi
}

func (s Circle) Perimeter() float64 {
	return 2 * math.Pi * s.radius
}
