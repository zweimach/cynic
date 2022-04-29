fn main() {
    let t = LinkedList::new(12);
    println!("{}", t.value);
}

struct LinkedList<T> {
    value: T,
    next: Option<Box<Self>>,
}

impl<T> LinkedList<T> {
    fn new(val: T) -> Self {
        Self { value, next: None }
    }
}
