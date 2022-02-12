#ifndef CYNIC_TOKEN_H
#define CYNIC_TOKEN_H

#include <stdbool.h>
#include <stdint.h>

#include "types.h"

typedef enum TokenKind TokenKind;

enum TokenKind {
    TOKEN_INVALID = 0,

    TOKEN_IDENTIFIER,
    TOKEN_COMMENT,

    TOKEN_INTEGER,
    TOKEN_FLOAT,
    TOKEN_CHARACTER,
    TOKEN_STRING,

    TOKEN_CONST,  // const
    TOKEN_VAR,    // var
    TOKEN_STATIC, // static

    TOKEN_RETURN,   // return
    TOKEN_FOR,      // for
    TOKEN_IN,       // in
    TOKEN_DO,       // do
    TOKEN_BREAK,    // break
    TOKEN_CONTINUE, // continue
    TOKEN_IF,       // if
    TOKEN_ELSE,     // else
    TOKEN_SWITCH,   // switch
    TOKEN_DEFER,    // defer

    TOKEN_STRUCT,   // struct
    TOKEN_ENUM,     // enum
    TOKEN_TYPEDEF,  // typedef
    TOKEN_ABSTRACT, // abstract
    TOKEN_CLASS,    // class
    TOKEN_FUN,      // fun

    TOKEN_SIZEOF,  // sizeof
    TOKEN_TYPEOF,  // typeof
    TOKEN_ALIGNOF, // alignof
    TOKEN_ALIGNAS, // alignas

    TOKEN_IMPLICIT, // implicit
    TOKEN_INCLUDE,  // include
    TOKEN_USE,      // use
    TOKEN_PUB,      // pub
    TOKEN_EXTEND,   // extend
    TOKEN_WITH,     // with
    TOKEN_AS,       // as

    TOKEN_PLUS,           // +
    TOKEN_MINUS,          // -
    TOKEN_MULTIPLICATION, // *
    TOKEN_DIVISION,       // /

    TOKEN_EQUAL,         // ==
    TOKEN_NOT_EQUAL,     // !=
    TOKEN_LESS,          // <
    TOKEN_LESS_EQUAL,    // <=
    TOKEN_GREATER,       // >
    TOKEN_GREATER_EQUAL, // >=
    TOKEN_LOGICAL_AND,   // &&
    TOKEN_LOGICAL_OR,    // ||
    TOKEN_LOGICAL_NOT,   // !

    TOKEN_SHIFT_RIGHT, // >>
    TOKEN_SHIFT_LEFT,  // <<
    TOKEN_BITWISE_XOR, // ^
    TOKEN_BITWISE_AND, // &
    TOKEN_BITWISE_OR,  // |
    TOKEN_BITWISE_NOT, // ~

    TOKEN_ASSIGN,                // =
    TOKEN_PLUS_ASSIGN,           // +=
    TOKEN_MINUS_ASSIGN,          // -=
    TOKEN_MULTIPLICATION_ASSIGN, // *=
    TOKEN_DIVISION_ASSIGN,       // /=
    TOKEN_SHIFT_RIGHT_ASSIGN,    // >>=
    TOKEN_SHIFT_LEFT_ASSIGN,     // <<=
    TOKEN_BITWISE_AND_ASSIGN,    // &=
    TOKEN_BITWISE_OR_ASSIGN,     // |=
    TOKEN_BITWISE_XOR_ASSIGN,    // ^=

    TOKEN_PIPELINE,     // |>
    TOKEN_UNDERSCORE,   // _
    TOKEN_USE_IMPLICIT, // _&_

    TOKEN_OPEN_PAREN,   // (
    TOKEN_CLOSE_PAREN,  // )
    TOKEN_OPEN_CURLY,   // {
    TOKEN_CLOSE_CURLY,  // }
    TOKEN_OPEN_SQUARE,  // [
    TOKEN_CLOSE_SQUARE, // ]

    TOKEN_DOT,              // .
    TOKEN_DOT_STAR,         // .*
    TOKEN_DOT_AND,          // .&
    TOKEN_DOT_AND_CONST,    // .&const
    TOKEN_DOT_QUERY,        // .?
    TOKEN_DOUBLE_DOT,       // ..
    TOKEN_DOUBLE_DOT_EQUAL, // ..=
    TOKEN_ELLIPSIS,         // ...
    TOKEN_SEMICOLON,        // ;
    TOKEN_COLON,            // :
    TOKEN_DOUBLE_COLON,     // ::
    TOKEN_THIN_ARROW,       // ->
    TOKEN_FAT_ARROW,        // =>
    TOKEN_COMMA,            // ,
    TOKEN_AT,               // @
    TOKEN_PERCENT,          // %
    TOKEN_DOUBLE_PERCENT,   // %%
    TOKEN_POUND,            // #
    TOKEN_DOLLAR,           // $

    TOKEN_EOF,
};

Char* token_kind_to_string(TokenKind kind);

Bool token_kind_is_keyword(TokenKind kind);

Bool token_kind_is_literal(TokenKind kind);

Bool token_kind_is_comment(TokenKind kind);

Bool token_kind_is_identifier(TokenKind kind);

typedef struct Token Token;

struct Token {
    TokenKind kind;
    Char* value;
};

Token* token_new(TokenKind kind, Char const* const c);

Void token_free(Token* token);

Bool token_is_whitespace(Char const c);

#endif /* CYNIC_TOKEN_H */
