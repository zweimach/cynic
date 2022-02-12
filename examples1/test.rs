struct Point {
    x: i32,
    y: i32,
}

pub fn main() {
    let s = Some(8u8);
    let p = Point { x: 12, y: 12 };
    let a = [1, 2, 3, 4];
    let b = &a;
    let c = &a[1..];
}
