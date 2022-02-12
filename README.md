# Cynic

Cynic is a systems programming language that compiles to C99, it is designed for
creating concise, high performance cross-platform applications. Cynic is highly
portable, it can be used in addition to or as an alternative to C.

Cynic is like C: it has pointers and pointer arithmetic, structs, arrays, manual memory management, and C-like syntax.

Cynic adds features such as pattern matching, defers, algebraic data types, region-based memory management, and type classes.

Cynic also removes features from C such as C's preprocessor and goto.

```cynic
use cynic/prelude::*
use doubt/assert
use doubt/test
use miscalc/prelude::*
use miscalc/basic
use skeptic/prelude::*
use skeptic/io
use skeptic/mem

implicit mem::cAllocator;

pub fun main()
    s ::= Shape[Int8]::Square::new(12)

    // perimeter
    io::println({
        switch s.*
            Square{} => "Square"
            Circle{} => "Circle",
        " has a perimeter of ",
        s |> Shape::perimeter(_) |> Show::toString(_),
    })

    name: CString =
        switch s.*
            Square{} => "Square"
            Circle{} => "Circle"
    io::printf("{} has a perimeter of {}\n", {name, s |> Shape::perimeter(_)})

    // area
    io::println({
        name,
        " is ",
        if s |> Shape::area(_)
            | _ < 5 => "small"
            | _ < 10 => "medium"
            | _ < 20 => "large"
            | else => "huge",
        " with an area of ",
        s |> Shape::area(_) |> Show::toString(_),
    })

    size: CString =
        if s |> Shape::area(_)
            | _ < 5 => "small"
            | _ < 10 => "medium"
            | _ < 20 => "large"
            | else => "huge"
    io::printf("{} is {} with an area of {}", {name, area, s |> Shape::area(_)})

pub union Shape[T] with Numeric[T]
    Square[T]
    Circle[T]

extend Shape[T]
    pub fun area(&s) T
        switch s.*
            Square{} as s => s |> Square::sides(_)
            Circle{} as c => c |> Circle::sides(_)

    pub fun perimeter(&s) T
        switch s
            Square{} as s => s |> Square::perimeter(_)
            Circle{} as c => c |> Circle::perimeter(_)

struct Square[T] with Numeric[T]
    T sides

extend Square[T]
    pub fun new(sides: T) T
        Self{ .sides = sides }

    pub fun area(&s) T
        s.sides * s.sides

    pub fun perimeter(&s) T
        s.sides * 4

struct Circle[T] with Numeric[T]
    T radius

extend Circle[T]
    pub fun new(radius: T) Self
        Self{.radius = radius}

    pub fun area(&c) T
        c.radius |> basic::pow(_) |> (_ * 2)

    pub fun perimeter(&c) T
        c.radius * PI * 2

[[test]]
fun testIsValid()
    implicit test::testingAllocator

    "{}[]()"
        |> isValid(_&_, _).?
        |> assert::isTrue(_)

    ")(}{]["
        |> isValid(_&_, _).?
        |> assert::isFalse(_)

fun isValid(Allocator alc, String xs) AllocError!Bool
    f ::= (c) ->
        switch c
            '}' => '{'
            ']' => '['
            ')' => '('
            _ => '\0'
    s ::= Stack[Char8]::new(alc).?
    defer s |> Stack::delete(_)
    for c := xs |> Iterable::iter(_)
        switch Stack::last(s.&)
            Just{n} if n == f(c.*) => Stack::pop(s.&)
            Nothing => Stack::push(s.&, c.*).?
    s |> Stack::isEmpty(_)

fun f(c: Char) Char
    switch c
        '}' => '{'
        ']' => '['
        ')' => '('
        _ => '\0'
```

```cynic
use skeptic/io;

Unit main() {
    const square = Square::new(16);
    io::printf("%d\n", square.perimeter());
    io::printf("%d\n", square.area());
}

struct Square {
    Int32 side;
}

extend Square {
    pub Self new(Int32 side) {
        return Self { .side = side };
    }

    pub Int32 perimeter(Self this) {
        return this.side * 4;
    }

    pub Int32 area(Self this) {
        return this.side * this.side;
    }
}
```

At a glance:

-   Cynic has a strong, static type system to catch errors at compile-time.
-   Cynic is a procedural language, not object-oriented or functional; however, type classes, boxes and abstracts can simulate object-oriented interfaces and polymorphism.
-   Cynic compiles to standard C99, which then compiles to native libraries or executables.
-   Memory management in Cynic is manual (no automatic garbage collection), with some convenience features to make this easier.

TODO:

-   Syntax
    -   Types
    -   Functions
-   Module system
-   Strings
-   Class hierarchies
-   Standard library

Naming convention

| Item             | Convention             |
| ---------------- | ---------------------- |
| Packages         | `snake_case`           |
| Modules          | `snake_case`           |
| Attributes       | `snake_case`           |
| Types            | `PascalCase`           |
| Type parameters  | `PascalCase`           |
| Type classes     | `PascalCase`           |
| Enum variants    | `PascalCase`           |
| Functions        | `camelCase`            |
| Methods          | `camelCase`            |
| Local variables  | `camelCase`            |
| Statics          | `SCREAMING_SNAKE_CASE` |
| Global constants | `SCREAMING_SNAKE_CASE` |

General type shorthand notations

| Type               | Shorthand  |
| ------------------ | ---------- |
| `CArray[T, USize]` | `T[USize]` |
| `Slice[T]`         | `T[&]`     |
| `Array[T]`         | `T[@]`     |
| `Maybe[T]`         | `T?`       |
| `Ref[T]`           | `T&`       |
| `Box[T]`           | `T@`       |
| `CRef[T]`          | `T*`       |
| `Result[E, T]`     | `E!T`      |

## Basic Types

### Integers

Fixed-length integers

| Signed Types | Unsigned Types | Width |
| ------------ | -------------- | ----- |
| `Int8`       | `UInt8`        | 8     |
| `Int16`      | `UInt16`       | 16    |
| `Int32`      | `UInt32`       | 32    |
| `Int64`      | `UInt64`       | 64    |

Mapped C integers

| Signed Types                     | Unsigned Types                     | Width       |
| -------------------------------- | ---------------------------------- | ----------- |
| `IChar` (`signed char`)          | `UChar` (`unsigned char`)          | 8           |
| `IShort` (`signed short`)        | `UShort` (`unsigned short`)        | at least 16 |
| `Int` (`signed int`)             | `UInt` (`unsigned int`)            | at least 16 |
| `ILong` (`signed long`)          | `ULong` (`unsigned long`)          | at least 32 |
| `ILongLong` (`signed long long`) | `ULongLong` (`unsigned long long`) | at least 64 |
| `ISize` (`size_t`)               | `USize` (`ssize_t`)                | at least 32 |

Integer literals

```
75 // decimal
0o113 // octal
0x4b // hexadecimal
0b1001011 // binary
```

Use `_` to separate digits

```
3_000_000
0o123_345
0xff_aa_00
0b1001_0001
```

### Floats

Fixed-length floats

| Types     | Width |
| --------- | ----- |
| `Float32` | 32    |
| `Float64` | 64    |

Mapped C floats

| Types                        | Width                   |
| ---------------------------- | ----------------------- |
| `Float` (`float`)            | 32                      |
| `Double` (`double`)          | 64                      |
| `LongDouble` (`long double`) | at least 64 (80/96/128) |

Float literals

```
0.0
```

### Booleans

`Bool`: `True`, `False`

### Strings

The type of characters is `Char` which based on the C type `char`.

-   Length-prefixed strings (UTF-8): `String`
-   Null-terminated strings: `CString`

```cynic
var name = "Cynic";         // String
var name = "Cynic\0";       // CString

var c = 'C';                // Char
```

```
\x000
\u00
```

### Tuples

`(Int8, Float32, Bool)`

### Arrays

-   C's array type: `CArray[T, USize]` or `T[USize]`
-   Fixed-length array: `Array`
-   Slices: `Slice[T]` or `T[&]`

```cynic
Int8[4] arr1 = { 1, 2, 3, 4 };
Int8[] arr1 = { 1, 2, 3, 4 };
var arr1 = Int8[] { 1, 2, 3, 4 };

CArray[Int8, 4] arr1 = { 1, 2, 3, 4 };
CArray[Int8] arr1 = { 1, 2, 3, 4 };
var arr1 = CArray[Int8] { 1, 2, 3, 4 };

Int8[2][2] arr2 = { { 1, 2 }, { 3, 4 } };
Int8[][] arr2 = { { 1, 2 }, { 3, 4 } };
var arr2 = Int8[][] { { 1, 2 }, { 3, 4 } };

CArray[CArray[Int8, 2], 2] arr2 = { { 1, 2 }, { 3, 4 } };
CArray[CArray[Int8]] arr2 = { { 1, 2 }, { 3, 4 } };
var arr2 = CArray[CArray[Int8]] { { 1, 2 }, { 3, 4 } };
```

### Pointers

-   `Ref[T]` or `T&`: pointer/reference
-   `Box[T]` or `T@`: unique/fat pointer
-   `CRef[T]` or `T*`: raw pointer (unsafe, for interfacing with C)
-   `Maybe[T]` or `T?`: optional (special case, for nullable pointer)

Use `.*` to dereference a pointer and `.&` to get the reference/address of a value.
`.&const` can be used to obtain the reference to a constant pointer.

```cynic
var val1 = 1;           // Int
const ptr2 = val.&;     // Int&

ptr2.* += 1;
val1 == 2;              // True

var ptr3 = val1.&const; // Int*
ptr3.* += 1;             // This is a compile error
```

```cynic
const num1 = 12;                                    // Int32
Int32 const num1 = 12;                              // Int32

var num2 = 12;                                      // Int32
Int32 num2 = 12;                                    // Int32

const ptr1 = num1.&const;                           // Int32 const&
Int32 const* ptr1 = num1.&const;                    // Int32 const&
Ref[Int32 const] ptr1 = num1.&const;                // Int32 const& or Ref[Int32 const]

var ptr2 = num2.&;                                  // Int32&
Int32* ptr2 = num2.&;                               // Int32&
Ref[Int32] ptr1 = num1.&const;                      // Int32& or Ref[Int32]

const ptr1ptr = ptr1.&const;                        // Int32 const& const&
Int32 const* const* ptr1ptr = ptr1.&const;          // Int32 const& const&
Ref[Ref[Int32 const] const] ptr1ptr = ptr1.&const;  // Int32 const& const& or Ref[Ref[Int32 const] const]

var ptr2ptr = ptr2.&;                               // Int32&&
Int32** ptr2ptr = ptr2.&;                           // Int32&&
Ref[Ref[Int32]] ptr2ptr = ptr2.&;                   // Int32&& or Ref[Ref[Int32]]
```

### Voids

`Void` & `Unit`

## Compound Types

### Functions

Function declaration

```cynic
Int add(Int x, Int y) {
    return x + y;
}
```

Function pointer type

```cynic
typedef AddFunc = Int fun(Int, Int);
```

Anonymous function literal

```cynic
const add = fun (x, y) { return x + y; };

Int fun(Int, Int) const add = fun (x, y) { return x + y; };

AddFunc const add = fun (x, y) { return x + y; };
```

Anonymous function literal (shorthand)

```cynic
const add = fun (x, y) -> x + y;

Int fun(Int, Int) const add = fun (x, y) -> x + y;

AddFunc const add = fun (x, y) -> x + y;
```

### Methods

```cynic
struct Square {
    Int32 side;
}

extend Square {
    Self new(Int32 side) {
        return Self { .side = side };
    }

    Int32 perimeter(Self this) {
        return this.side * 4;
    }

    Int32 area(Self this) {
        return this.side * this.side;
    }
}
```

### Structs

Structs fields and methods are private by default

```cynic
struct MyStruct {
    pub Int32 normalField,
    pub Int32 defaultField = 1,
    Int32 privateField,
}
```

### Enums

Enum variants can optionally contain data, and Enums that have no data
in the variants will be optimized to C enums.
Enum variants are namespaced by default.

```cynic
enum MyEnum {
    Zero = 0,
    One,
    Three = 3,
}
```

You can bring enum variants to scope with `use`.

```
use MyEnum::*;
```

### Typedefs

```cynic
typedef MyTypedef = UInt32;
```

### Abstracts

```cynic
abstract MyAbstract = Unit;
```

```cynic
abstract Color = UInt32;

extend Color {
    (UInt8, UInt8, UInt8) toRgb() {
        return ((this & 0xff0000) >> 16, (this & 0xff00) >> 8, this & 0xff);
    }
}
```

### Unions

```cynic
union MyUnion {
    MyStruct,
    MyEnum,
    MyAbstract,
}

union MyUnion[T] {
    struct MyStruct {
        pub Int32 publicField,
        Int32 privateField = 1,
    },
    enum MyEnum {
        HasValue = 0,
        HaveNone,
    },
    abstract MyAbstract = Void,
}
```

```cynic
union Maybe[T] {
    abstract Just = T,
    abstract None,
}
```

To extend a union

```cynic
union MyExtendedUnion[T] {
    MyUnion,
    abstract MyTuple = (Int8, Int8),
}
```

### Generics

```cynic
struct GenericStruct[T] {
    T value;
}

union GenericUnion[T] {
    abstract Yes = T,
    abstract No,
}

T genericFun[T](T input) {
    return doSomething(input);
}
```

### Type Classes

Type class interface and implementation

```cynic
class MyTrait[T] with Numeric[T] {
    T calculate(T);
}

extend Int with MyTrait {
    Int calculate(Int other) {
        return this + other;
    }
}
```

Type class as a constraint

```cynic
struct ConstraintStruct[T] with Eq[T] {
    T value;

    Bool isEqual(Self this, T other) {
        return this.value == other;
    }
}

T constraintFun[T](T this, T other) with Eq[T] {
    return this == other;
}
```

## Modules

Cynic code is structured into “.cyc” module files. Cynic has a simple module system
that mirrors the directory structure of your project.

### Imports

To import a module from a package

```cynic
use package_name/module;
```

To import an item from a module

```cynic
use package_name/module::anItem;
```

To import all items from a module

```cynic
use package_name/module::*;
```

To import multiple items from a module

```cynic
use package_name/module::{someFunction, SomeStruct};
```

To import a module from the root of current project (absolute path)

```cynic
use @/module;
```

To import a module from the current directory (relative path)

```cynic
use ./module;
```

To import a module from the parent directory (relative path)

```cynic
use ../module;
```

### Exports

To export names

```cynic
Int32 add(Int32 x, Int32 y) {
    return x + y;
}
```

### The Main Module

A single module will serve as the main module, which is the entry point for
compilation; all modules imported from this module, and all modules imported
from those modules recursively, will be compiled. If compiling an executable
the main module should have a function called main.

## Expressions & Statements

### Variables

```cynic
Int a = 1;
var b = 1;
```

```cynic
String const d = "Hello";
const e = "Hello";
```

### Blocks

```cynic
{
    println("Hello ");
    println("World!");
}
```

```cynic
{
    println("Hello ");
    {
        println("World!");
    }
}
```

### For

Classic for statement

```cynic
for var i = 0; i < 10; i += 1 {
    println("Hello, World!");
}
```

### While

```cynic
var n = 1;

while n < 10 {
    n = n + 1;
}
```

### If

If statement

```cynic
Bool m = undefined;

if n < 10 {
    m = True;
} else {
    m = False;
}
```

Multiway if statement

```cynic
CString size = undefined;

if {
    x < 3 => {
        size = "small";
    }
    x < 7 => {
        size = "medium";
    }
    else => {
        size = "large";
    }
}
```

If expression

```cynic
const m = if n < 10 { True } else { False };
```

Multiway if expression

```cynic
const size = if {
    x < 3 => "small",
    x < 7 => "medium",
    else  => "large",
};
```

### Switch

Switch statement

```cynic
const t = Just(12);

switch i {
    Just(n) => {
        printf("t is an integer: %d\n", n);
    }
    Nothing => {
        printf("t is empty\n");
    }
}
```

Switch expression

```cynic
const t = Just(12);

String const s = switch i {
    Just(n) => sprintf("t is an integer: %d\n", n),
    Nothing => sprintf("t is empty\n"),
};

println(s);
```

### Defer

Defer statement

```cynic
const m = M.alloc();
defer m.free();

doSomething(m.&);
```

Defer block

```cynic
const m = M.alloc();
defer {
    m.free();
    printf("m is freed\n");
}

doSomething(m.&);
```
