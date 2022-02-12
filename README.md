# Cynic

Cynic is a systems programming language that compiles to C99, it is designed for
creating concise, high performance cross-platform applications. Cynic is highly
portable, it can be used in addition to or as an alternative to C.

Cynic is like C: it has pointers and pointer arithmetic, structs, arrays, manual memory management, and C-like syntax.

Cynic adds features such as pattern matching, defers, algebraic data types, region-based memory management, and type classes.

Cynic also removes features from C such as C's preprocessor and goto.

At a glance:

-   Cynic has a strong, static type system to catch errors at compile-time.
-   Cynic is a procedural language, not object-oriented or functional; however, type classes, boxes and abstracts can simulate object-oriented interfaces and polymorphism.
-   Cynic compiles to standard C99, which then compiles to native libraries or executables.
-   Memory management in Cynic is manual (no automatic garbage collection), with some convenience features to make this easier.

TODO:

-   [x] Syntax
-   [ ] Types
-   [ ] Functions
-   [ ] Module system
-   [ ] Strings
-   [ ] Class hierarchies
-   [ ] Standard library

```cynic
use cynic/prelude::*
use cynic/math
use skeptic/prelude::*
use skeptic/io
use skeptic/mem
use skeptic/testing

implicit mem::cAllocator

pub fun main()
    const s = Shape[Int8]::Square::new(12)

    // perimeter
    io::println({
        switch s.*
            Square{} => "Square"
            Circle{} => "Circle",
        " has a perimeter of ",
        s |> Shape::perimeter(_) |> Show::toString(_),
    })

    const name =
        switch s.*
            Square{} => "Square"
            Circle{} => "Circle"
    io::printf("{} has a perimeter of {}\n", {name, s |> Shape::perimeter(_)})

    // area
    io::println({
        name,
        " is ",
        if const i = s |> Shape::area(_)
            i < 5 => "small"
            i < 10 => "medium"
            i < 20 => "large"
            else => "huge",
        " with an area of ",
        s |> Shape::area(_) |> Show::toString(_),
    })

    const size =
        if const i = s |> Shape::area(_)
            i < 5 => "small"
            i < 10 => "medium"
            i < 20 => "large"
            else => "huge"
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
    sides: T

extend Square[T]
    pub fun new(sides: T) T
        Self{.sides = sides}

    pub fun area(&self) T
        s.sides * s.sides

    pub fun perimeter(&self) T
        s.sides * 4

struct Circle[T] with Numeric[T]
    radius: T

extend Circle[T]
    pub fun new(radius: T) Self
        Self{.radius = radius}

    pub fun area(&self) T
        c.radius |> math::pow(_) |> (_ * 2)

    pub fun perimeter(&self) T
        c.radius * PI * 2
```

### Naming Convention

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

### Special Type Syntax

Special syntax or shorthand for type notations

| Type               | Shorthand   |
| ------------------ | ----------- |
| `CArray[T, USize]` | `T[USize]`  |
| `Slice[T]`         | `T[&]`      |
| `Array[T]`         | `T[@]`      |
| `Maybe[T]`         | `T?`        |
| `Ref[T]`           | `T&`        |
| `Box[T]`           | `T@`        |
| `CRef[T]`          | `T*`        |
| `Result[E, T]`     | `E!T`       |
| `Tuple[T, U, V]`   | `[T, U, V]` |

### Operators

| Operator  | Type class       | Description               | Note                        |
| --------- | ---------------- | ------------------------- | --------------------------- |
| `+`       | `Add:add`        | Addition                  |                             |
| `+=`      |                  | Addition assignment       | Not overloadable            |
| `-`       | `Sub::sub`       | Subtraction               |                             |
| `-=`      |                  | Subtraction assignment    | Not overloadable            |
| `*`       | `Mul::mul`       | Multiplication            |                             |
| `*=`      |                  | Multiplication assignment | Not overloadable            |
| `/`       | `Div::div`       | Division                  |                             |
| `/=`      |                  | Division assignment       | Not overloadable            |
| `%`       | `Rem::rem`       | Remainder                 |                             |
| `%=`      |                  | Remainder assignment      | Not overloadable            |
| `%%`      | `Mod::mod`       | Modulus                   |                             |
| `%%=`     |                  | Modulus assignment        | Not overloadable            |
| `<<`      | `Shl::shl`       | Shift left                |                             |
| `<<=`     |                  | Shift left assignment     | Not overloadable            |
| `>>`      | `Shr::shr`       | Shift right               |                             |
| `>>=`     |                  | Shift right assignment    | Not overloadable            |
| `&&`      |                  | Logical and               | Not overloadable            |
| `\|\|`    |                  | Logical or                | Not overloadable            |
| `!`       | `Not::not`       | Logical not               |                             |
| `==`      | `PartialEq::eq`  | Equality                  |                             |
| `!=`      | `PartialEq::neq` | Non-equality              |                             |
| `<`       | `PartialOrd::lt` | Less than                 |                             |
| `<=`      | `PartialOrd::le` | Less than or equal        |                             |
| `>`       | `PartialOrd::gt` | Greater than              |                             |
| `>=`      | `PartialOrd::ge` | Greater than or equal     |                             |
| `&`       | `BitAnd::bitAnd` | Bitwise and               |                             |
| `&=`      |                  | Bitwise and assignment    | Not overloadable            |
| `\|`      | `BitOr::bitOr`   | Bitwise or                |                             |
| `\|=`     |                  | Bitwise or assignment     | Not overloadable            |
| `^`       | `BitXor::bitXor` | Bitwise xor               |                             |
| `^=`      |                  | Bitwise xor assignment    | Not overloadable            |
| `~`       | `BitNot::bitNot` | Bitwise not               |                             |
| `.`       |                  | Member access             | Not overloadable            |
| `.*`      |                  | Dereference               | Not overloadable            |
| `.&`      |                  | Address of                | Not overloadable            |
| `.&const` |                  | Constant address of       | Not overloadable            |
| `.?`      |                  | Try                       | Not overloadable            |
| `\|>`     |                  | Pipe                      | Not overloadable            |
| `->`      |                  | Method pipe               | Not overloadable            |
| `[]`      | `Index::index`   | Indexing                  |                             |
| `()`      |                  | Function call             | Technically not an operator |
| `{}`      |                  | Type construction         | Technically not an operator |

### Precedence

```
x() x[] x.y x.* x.? x.& x.&const
x{}
!x -x ~x
* / % %%
+ -
<< >>
& ^ |
== != < > <= >=
&&
||
-> |>
= += -= *= /= %= %%= <<= >>= &= |= ^=
```

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
var name = "Cynic"         // String
var name = "Cynic\0"       // CString

var c = 'C'                // Char
```

```
\x000
\u00
```

### Tuples

`Tuple[Int8, Float32, Bool]`

```cynic
const pair1: Tuple[Int, Int] = {42, 0}

const pair2 = Tuple[Int, Int]{42, 0}

const pair3 = Tuple{42, 0} // Tuple[Int, Int]
```

### Arrays

-   C's array type: `CArray[T, USize]` or `T[USize]`
-   Fixed-length array: `Array`
-   Slices: `Slice[T]` or `T[&]`

```cynic
var arr1: Int8[4] = { 1, 2, 3, 4 }
var arr1: Int8[] = { 1, 2, 3, 4 }
var arr1 = Int8[]{ 1, 2, 3, 4 }

var arr1: CArray[Int8, 4] = { 1, 2, 3, 4 }
var arr1: CArray[Int8] = { 1, 2, 3, 4 }
var arr1 = CArray[Int8]{ 1, 2, 3, 4 }

var arr2: Int8[2][2] = {{ 1, 2 }, { 3, 4 }}
var arr2: Int8[][] = {{ 1, 2 }, { 3, 4 }}
var arr2 = Int8[][]{{ 1, 2 }, { 3, 4 }}

var arr2: CArray[CArray[Int8, 2], 2] = {{1, 2}, {3, 4}}
var arr2: CArray[CArray[Int8]] = {{ 1, 2 }, { 3, 4 }}
var arr2 = CArray[CArray[Int8]]{{ 1, 2 }, { 3, 4 }}
```

### Pointers

-   `Ref[T]` or `T&`: pointer/reference
-   `Box[T]` or `T@`: unique/fat pointer
-   `CRef[T]` or `T*`: raw pointer (unsafe, for interfacing with C)
-   `Maybe[T]` or `T?`: optional (special case, for nullable pointer)

Use `.*` to dereference a pointer and `.&` to get the reference/address of a value.
`.&const` can be used to obtain the reference to a constant pointer.

```cynic
var val1 = 1             // Int
const ptr2 = val.&       // Int&

ptr2.* += 1
val1 == 2                // True

var ptr3 = val1.&const   // Int&
ptr3.* += 1              // This is a compile error
```

```cynic
const num1 = 12                                           // Int32
const num1: Int32 = 12                                    // Int32

var num2 = 12                                             // Int32
var num2: Int32 = 12                                      // Int32

const ptr1 = num1.&const                                  // Int32 const&
const ptr1: Int32 const& = num1.&const                    // Int32 const&
const ptr1: Ref[Int32 const] = num1.&const                // Int32 const& or Ref[Int32 const]

var ptr2 = num2.&                                         // Int32&
var ptr2: Int32& = num2.&                                 // Int32&
var ptr2: Ref[Int32] = num2.&                             // Int32& or Ref[Int32]

const ptr1ptr = ptr1.&const                               // Int32 const& const&
const ptr1ptr: Int32 const& const& = ptr1.&const          // Int32 const& const&
const ptr1ptr: Ref[Ref[Int32 const] const] = ptr1.&const  // Int32 const& const& or Ref[Ref[Int32 const] const]

var ptr2ptr = ptr2.&                                      // Int32&&
var ptr2ptr: Int32&& = ptr2.&                             // Int32&&
var ptr2ptr: Ref[Ref[Int32]] = ptr2.&                     // Int32&& or Ref[Ref[Int32]]
```

### Voids

`Void` & `Unit`

## Compound Types

### Functions

Function declaration

```cynic
fun add(Int x, Int y) Int
    x + y
```

Function pointer type

```cynic
typedef AddFunc = (Int, Int) Int
```

Anonymous function literal

```cynic
const add = \x, y -> x + y

const add: (Int, Int) Int = \x, y -> x + y

const add: AddFunc = \x, y -> x + y
```

### Methods

```cynic
struct Square
    sides: Int32

extend Square
    pub fun new(sides: Int32) Self
        Self{ .sides = sides }

    pub fun perimeter(&self) Int32
        s.side * 4

    pub fun area(&self) Int32
        s.side * this.side
```

### Structs

Structs fields and methods are private by default

```cynic
struct MyStruct
    pub normalField: Int32
    pub defaultField: Int32 = 1
    privateField: Int32
```

### Enums

Enum variants are namespaced by default.

```cynic
enum MyEnum
    Zero = 0
    One
    Three = 3
```

You can bring enum variants to scope with `use`.

```
use MyEnum::*
```

### Typedefs

```cynic
typedef MyTypedef = UInt32
```

### Abstracts

```cynic
abstract MyAbstract = Unit
```

```cynic
abstract Color = UInt32

extend Color
    fun toRgb() [UInt8, UInt8, UInt8]
        {(this & 0xff0000) >> 16, (this & 0xff00) >> 8, this & 0xff}
```

### Unions

```cynic
union MyUnion
    MyStruct
    MyEnum
    MyAbstract

union MyUnion[T]
    struct MyStruct
        pub publicField: Int32
        privateField: Int32 = 1

    enum MyEnum
        Zero = 0
        One
        Three = 3

    abstract MyAbstract = Unit
```

```cynic
union MyOptional[T]
    abstract Just = T
    abstract None
```

To extend a union

```cynic
union MyExtendedUnion[T]
    abstract MyTuple = [Int8, Int8]

extend MyExtendedUnion with MyUnion[T]
```

### Generics

```cynic
struct GenericStruct[T]
    value: T

union GenericUnion[T]
    abstract Yes = T
    abstract No

fun genericFun[T](input: T) T
    return doSomething(input)
```

### Type Classes

Type class interface and implementation

```cynic
class MyTrait[T] with Numeric[T]
    fun calculate(Self&, T) T

extend Int32 with MyTrait
    fun calculate(&self, other: Int32) Int32
        self + other
```

Type class as a constraint

```cynic
struct ConstraintStruct[T] with Eq[T]
    value: T

extend ConstraintStruct[T]
    fun isEqual(&self, other: T) Bool
        this.value == other

fun constraintFun[T](&self, other: T) T with Eq[T]
    this == other
```

## Modules

Cynic code is structured into “.cyc” module files. Cynic has a simple module system
that mirrors the directory structure of your project.

### Imports

To import a module from a package

```cynic
use package_name/module
```

To import an item from a module

```cynic
use package_name/module::anItem
```

To import all items from a module

```cynic
use package_name/module::*
```

To import multiple items from a module

```cynic
use package_name/module::{someFunction, SomeStruct}
```

To import a module from the root of current project (absolute path)

```cynic
use @/module
```

To import a module from the current directory (relative path)

```cynic
use ./module
```

To import a module from the parent directory (relative path)

```cynic
use ../module
```

### Exports

To export names

```cynic
Int32 add(Int32 x, Int32 y)
    return x + y
```

### The Main Module

A single module will serve as the main module, which is the entry point for
compilation; all modules imported from this module, and all modules imported
from those modules recursively, will be compiled. If compiling an executable
the main module should have a function called main.

## Expressions & Statements

### Variables

```cynic
var a: Int = 1
var b = 1
```

```cynic
const c: String = "Hello"
const d = "Hello"
```

### Blocks

Use `do` to open a new block

```cynic
do
    println("Hello ")
    println("World!")
```

```cynic
do
    println("Hello ")
    do
        println("World!")
```

### For

Classic `for` statement

```cynic
var num = Int8[]{1, 2, 3, 4}

for var i = 0; i < num.len(); i += 1
    num[i] *= num[i]
```

`for` statement with only the condition

```cynic
var num = Int8[]{1, 2, 3, 4}

var i = 0
for i < num.len()
    num[i] *= num[i]
    i += 1
```

`for` `in` statement

```cynic
var num = Int8[]{1, 2, 3, 4}

for var i in num
    i *= i
```

Infinite `for` loop

```cynic
for
    println("Forever loop")
```

### If

`if` statement

```cynic
Bool m = undefined

if n < 10
    m = True
else
    m = False
```

Multiway `if` statement

```cynic
CString size = undefined

if |
    x < 3 =>
        size = "small"
    x < 7 =>
        size = "medium"
    else =>
        size = "large"
```

`if` expression

```cynic
const m = if n < 10 { True } else { False }

const m = if n < 10
        True
    else
        False
```

Multiway `if` expression

```cynic
const size = if |
    x < 3 => "small"
    x < 7 => "medium"
    else  => "large"
```

### Switch

`switch` statement

```cynic
const t = Just(12)

switch i
    Just{n} =>
        printf("t is an integer: %d\n", n)
    Nothing =>
        printf("t is empty\n")
```

`switch` expression

```cynic
const t = Just(12)

String const s = switch i
    Just(n) => sprintf("t is an integer: %d\n", n)
    Nothing => sprintf("t is empty\n")

println(s)
```

### Defer

`defer` statement

```cynic
const m = M.alloc()
defer m.free()

doSomething(m.&)
```

`defer` block

```cynic
const m = M.alloc()
defer
    m.free()
    printf("m is freed\n")

doSomething(m.&)
```
