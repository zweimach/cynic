#ifndef CYNIC_TOKEN_H
#define CYNIC_TOKEN_H

#include <stdbool.h>
#include <stdint.h>

typedef enum TokenKind TokenKind;

typedef struct Token Token;

enum TokenKind {
    TOKEN_INVALID = -1,
    TOKEN_EOF,

    TOKEN_IDENTIFIER,

    // Literals
    TOKEN_CHARACTER,
    TOKEN_FLOAT,
    TOKEN_INTEGER,
    TOKEN_STRING,

    // Keywords
    TOKEN_ABSTRACT, // abstract
    TOKEN_ALIGNAS,  // alignas
    TOKEN_ALIGNOF,  // alignof
    TOKEN_AS,       // as
    TOKEN_BREAK,    // break
    TOKEN_CLASS,    // class
    TOKEN_CONST,    // const
    TOKEN_CONTINUE, // continue
    TOKEN_DEFER,    // defer
    TOKEN_DO,       // do
    TOKEN_ELSE,     // else
    TOKEN_ENUM,     // enum
    TOKEN_EXTEND,   // extend
    TOKEN_FN,       // fn
    TOKEN_FOR,      // for
    TOKEN_IF,       // if
    TOKEN_IMPLICIT, // implicit
    TOKEN_IN,       // in
    TOKEN_INCLUDE,  // include
    TOKEN_INLINE,   // inline
    TOKEN_LET,      // let
    TOKEN_MUT,      // mut
    TOKEN_PUB,      // pub
    TOKEN_RETURN,   // return
    TOKEN_SIZEOF,   // sizeof
    TOKEN_STATIC,   // static
    TOKEN_STRUCT,   // struct
    TOKEN_SWITCH,   // switch
    TOKEN_TYPE,     // type
    TOKEN_TYPEDEF,  // typedef
    TOKEN_TYPEOF,   // typeof
    TOKEN_UNION,    // union
    TOKEN_USE,      // use
    TOKEN_VAR,      // var
    TOKEN_WITH,     // with
    TOKEN_YIELD,    // yield

    // Operators
    TOKEN_ARROW_DOUBLE,        // =>
    TOKEN_ARROW_SINGLE,        // ->
    TOKEN_ASSIGN,              // =
    TOKEN_ASTERISK,            // *
    TOKEN_ASTERISK_ASSIGN,     // *=
    TOKEN_AT,                  // @
    TOKEN_BACKSLASH,           /* \ */
    TOKEN_BITWISE_AND,         // &
    TOKEN_BITWISE_AND_ASSIGN,  // &=
    TOKEN_BITWISE_NOT,         // ~
    TOKEN_BITWISE_OR,          // |
    TOKEN_BITWISE_OR_ASSIGN,   // |=
    TOKEN_BITWISE_XOR,         // ^
    TOKEN_BITWISE_XOR_ASSIGN,  // ^=
    TOKEN_COLON,               // :
    TOKEN_COLON_COLON,         // ::
    TOKEN_COMMA,               // ,
    TOKEN_CURLY_CLOSE,         // }
    TOKEN_CURLY_OPEN,          // {
    TOKEN_DOLLAR,              // $
    TOKEN_DOT,                 // .
    TOKEN_DOT_AND,             // .&
    TOKEN_DOT_AND_MUT,         // .&mut
    TOKEN_DOT_ASTERISK,        // .*
    TOKEN_DOT_BANG,            // .!
    TOKEN_DOT_DOT,             // ..
    TOKEN_DOT_DOT_EQUAL,       // ..=
    TOKEN_DOT_QUERY,           // .?
    TOKEN_ELLIPSIS,            // ...
    TOKEN_EQUAL,               // ==
    TOKEN_GREATER,             // >
    TOKEN_GREATER_EQUAL,       // >=
    TOKEN_LESS,                // <
    TOKEN_LESS_EQUAL,          // <=
    TOKEN_LOGICAL_AND,         // &&
    TOKEN_LOGICAL_NOT,         // !
    TOKEN_LOGICAL_OR,          // ||
    TOKEN_MINUS,               // -
    TOKEN_MINUS_ASSIGN,        // -=
    TOKEN_NOT_EQUAL,           // !=
    TOKEN_PAREN_CLOSE,         // )
    TOKEN_PAREN_OPEN,          // (
    TOKEN_PERCENT,             // %
    TOKEN_PERCENT_PERCENT,     // %%
    TOKEN_PIPELINE,            // |>
    TOKEN_PLACEHOLDER,         // _
    TOKEN_PLACEHOLDER_SPECIAL, // _&_
    TOKEN_PLUS,                // +
    TOKEN_PLUS_ASSIGN,         // +=
    TOKEN_QUERY,               // ?
    TOKEN_SEMICOLON,           // ;
    TOKEN_SHIFT_LEFT,          // <<
    TOKEN_SHIFT_LEFT_ASSIGN,   // <<=
    TOKEN_SHIFT_RIGHT,         // >>
    TOKEN_SHIFT_RIGHT_ASSIGN,  // >>=
    TOKEN_SLASH,               // /
    TOKEN_SLASH_ASSIGN,        // /=
    TOKEN_SQUARE_CLOSE,        // ]
    TOKEN_SQUARE_OPEN,         // [
};

struct Token {
    TokenKind kind;
    uint32_t start;
    uint32_t end;
};

Token* token_new(TokenKind kind, uint32_t start, uint32_t end);

void token_free(Token* const token);

#endif /* CYNIC_TOKEN_H */
