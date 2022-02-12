# Pipe

```cynic
use cynic/prelude::*
use cynic/math
use skeptic/prelude::*
use skeptic/data::*
use skeptic/mem
use skeptic/io

implicit mem::cAllocator

fun pipeError()
    let squared = 42 |> math::pow
```

```
error: mismatched paramater
  --> test/error/pipe_error.cyc:11:25
    |
 11 |    let squared = 42 |> math::pow
    |                  --    ^^^^^^^^^ expected 2 paramaters
    |                  |
    |                  but only given one paramater
```
