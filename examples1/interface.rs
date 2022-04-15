use std::f64;

pub fn main() {
    let mut shape: Box<dyn Shape>;
    shape = Box::new(Square::new(12.5));
    print!(
        "Square: area {:.2}, perimeter {:.2}\n",
        shape.area(),
        shape.perimeter()
    );
    print!("Total: {:.2}\n", get_total(shape.as_ref()));
    shape = Box::new(Circle::new(8.5));
    print!(
        "Circle: area {:.2}, perimeter {:.2}\n",
        shape.area(),
        shape.perimeter()
    );
    print!("Total: {:.2}\n", get_total(shape.as_ref()));
}

fn get_total<T>(s: &T) -> f64
where
    T: Shape + ?Sized,
{
    s.area() + s.perimeter()
}

trait Shape {
    fn area(&self) -> f64;
    fn perimeter(&self) -> f64;
}

struct Square {
    sides: f64,
}

impl Square {
    fn new(sides: f64) -> Self {
        Self { sides }
    }
}

impl Shape for Square {
    fn area(&self) -> f64 {
        self.sides * self.sides
    }

    fn perimeter(&self) -> f64 {
        self.sides * 4f64
    }
}

struct Circle {
    radius: f64,
}

impl Circle {
    fn new(radius: f64) -> Self {
        Self { radius }
    }
}

impl Shape for Circle {
    fn area(&self) -> f64 {
        self.radius * self.radius * f64::consts::PI
    }

    fn perimeter(&self) -> f64 {
        self.radius * 2f64 * f64::consts::PI
    }
}
