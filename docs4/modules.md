# Modules

Cynic code is structured into “.cyc” module files. Cynic has a simple module system
that mirrors the directory structure of your project.

## Imports

To import a module from a package:

```cynic
use package_name/module;
```

To import an item from a module:

```cynic
use package_name/module::anItem;
```

To import all items from a module:

```cynic
use package_name/module::*;
```

To import multiple items from a module:

```cynic
use package_name/module::{someFunction, SomeStruct};
```

To import a module from the root of current project (absolute path):

```cynic
use @/module;
```

To import a module from the current directory (relative path):

```cynic
use ./module;
```

To import a module from the parent directory (relative path):

```cynic
use ../module;
```

## Exports

To export names and symbols, you use the `pub` keyword.
For example, to export a top-level function:

```cynic
pub Int32 add(Int32 x, Int32 y) {
    return x + y;
}
```

## The Main Module

A single module will serve as the `main` module, which is the entry point for
compilation; all modules imported from this module, and all modules imported
from those modules recursively, will be compiled. If compiling an executable
the `main` module should have a function called `main`.
