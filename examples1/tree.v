module main

fn main() {
    t := new_linked_list(12)
    println('$t.value')
}

struct LinkedList<T> {
    value T
    next ?&LinkedList<T>
}

fn new_linked_list<T>(value T) LinkedList<T> {
    return LinkedList {value,  none}
}
