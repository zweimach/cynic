## Grammar

### Lexical Grammar

```
number         → digit+ ( "." digit+ )? ;
string         → "\"" <any char except "\"">* "\"" ;
identifier     → alpha ( alpha | digit )* ;
alpha          → "a" ... "z" | "A" ... "Z" | "_" ;
decimal        → digit ( digit )* ;
digit          → "0" ... "9" ;
hexdigit       → "a" ... "f" | "A" ... "F" | digit ;
```

### Syntax Grammar

```
program               → declaration* EOF ;

declaration           → classDeclaration
                      | structDeclaration
                      | enumDeclaration
                      | functionDeclaration
                      | statement ;

classDeclaration      → "class" IDENTIFIER ( ":" IDENTIFIER )?
                        "{" function* "}" ;

functionDeclaration   → "fun" function ;

structDeclaration     → "struct" IDENTIFIER ( "=" expression )? "}" ;

enumDeclaration       → "enum" IDENTIFIER ( "=" expression )? ";" ;
```
