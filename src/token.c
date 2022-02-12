#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "token.h"
#include "types.h"

Token* token_new(TokenKind kind, Char const* const c)
{
    Token* token = calloc(1, sizeof(Token));
    if (token) {
        token->kind = kind;
        token->value = calloc(strlen(c) + 1, sizeof(Char));
    }
    if (token->value && c) {
        strcpy(token->value, c);
    }
    return token;
}

Void token_free(Token* token)
{
    if (token) {
        free(token->value);
        free(token);
    }
}

Char* token_kind_to_string(TokenKind kind)
{
    switch (kind) {
    case TOKEN_IDENTIFIER:
        return "IDENTIFIER";
    case TOKEN_COMMENT:
        return "COMMENT";

    case TOKEN_INTEGER:
        return "INTEGER";
    case TOKEN_FLOAT:
        return "FLOAT";
    case TOKEN_CHARACTER:
        return "CHARACTER";
    case TOKEN_STRING:
        return "STRING";

    case TOKEN_CONST:
        return "const";
    case TOKEN_VAR:
        return "var";
    case TOKEN_STATIC:
        return "static";
    case TOKEN_RETURN:
        return "return";
    case TOKEN_FOR:
        return "for";
    case TOKEN_IN:
        return "in";
    case TOKEN_DO:
        return "do";
    case TOKEN_BREAK:
        return "break";
    case TOKEN_CONTINUE:
        return "continue";
    case TOKEN_IF:
        return "if";
    case TOKEN_ELSE:
        return "else";
    case TOKEN_SWITCH:
        return "switch";
    case TOKEN_DEFER:
        return "defer";
    case TOKEN_STRUCT:
        return "struct";
    case TOKEN_ENUM:
        return "enum";
    case TOKEN_TYPEDEF:
        return "typedef";
    case TOKEN_ABSTRACT:
        return "abstract";
    case TOKEN_CLASS:
        return "class";
    case TOKEN_FUN:
        return "fun";
    case TOKEN_SIZEOF:
        return "sizeof";
    case TOKEN_TYPEOF:
        return "typeof";
    case TOKEN_ALIGNOF:
        return "alignof";
    case TOKEN_ALIGNAS:
        return "alignas";
    case TOKEN_IMPLICIT:
        return "implicit";
    case TOKEN_INCLUDE:
        return "include";
    case TOKEN_USE:
        return "use";
    case TOKEN_PUB:
        return "pub";
    case TOKEN_EXTEND:
        return "extend";
    case TOKEN_WITH:
        return "with";
    case TOKEN_AS:
        return "as";

    case TOKEN_PLUS:
        return "+";
    case TOKEN_MINUS:
        return "-";
    case TOKEN_MULTIPLICATION:
        return "*";
    case TOKEN_DIVISION:
        return "/";
    case TOKEN_EQUAL:
        return "==";
    case TOKEN_NOT_EQUAL:
        return "!=";
    case TOKEN_LESS:
        return "<";
    case TOKEN_LESS_EQUAL:
        return "<=";
    case TOKEN_GREATER:
        return ">";
    case TOKEN_GREATER_EQUAL:
        return ">=";
    case TOKEN_LOGICAL_AND:
        return "&&";
    case TOKEN_LOGICAL_OR:
        return "||";
    case TOKEN_LOGICAL_NOT:
        return "!";
    case TOKEN_SHIFT_RIGHT:
        return ">>";
    case TOKEN_SHIFT_LEFT:
        return "<<";
    case TOKEN_BITWISE_XOR:
        return "^";
    case TOKEN_BITWISE_AND:
        return "&";
    case TOKEN_BITWISE_OR:
        return "|";
    case TOKEN_BITWISE_NOT:
        return "~";
    case TOKEN_ASSIGN:
        return "=";
    case TOKEN_PLUS_ASSIGN:
        return "+=";
    case TOKEN_MINUS_ASSIGN:
        return "-=";
    case TOKEN_MULTIPLICATION_ASSIGN:
        return "*=";
    case TOKEN_DIVISION_ASSIGN:
        return "/=";
    case TOKEN_SHIFT_RIGHT_ASSIGN:
        return ">>=";
    case TOKEN_SHIFT_LEFT_ASSIGN:
        return "<<=";
    case TOKEN_BITWISE_AND_ASSIGN:
        return "&=";
    case TOKEN_BITWISE_OR_ASSIGN:
        return "|=";
    case TOKEN_BITWISE_XOR_ASSIGN:
        return "^=";
    case TOKEN_PIPELINE:
        return "|>";
    case TOKEN_UNDERSCORE:
        return "_";
    case TOKEN_USE_IMPLICIT:
        return "_&_";
    case TOKEN_OPEN_PAREN:
        return "(";
    case TOKEN_CLOSE_PAREN:
        return ")";
    case TOKEN_OPEN_CURLY:
        return "{";
    case TOKEN_CLOSE_CURLY:
        return "}";
    case TOKEN_OPEN_SQUARE:
        return "[";
    case TOKEN_CLOSE_SQUARE:
        return "]";
    case TOKEN_DOT:
        return ".";
    case TOKEN_DOT_QUERY:
        return ".?";
    case TOKEN_DOT_STAR:
        return ".*";
    case TOKEN_DOT_AND:
        return ".&";
    case TOKEN_DOT_AND_CONST:
        return ".&const";
    case TOKEN_DOUBLE_DOT:
        return "..";
    case TOKEN_DOUBLE_DOT_EQUAL:
        return "..=";
    case TOKEN_ELLIPSIS:
        return "...";
    case TOKEN_SEMICOLON:
        return ";";
    case TOKEN_COLON:
        return ":";
    case TOKEN_DOUBLE_COLON:
        return "::";
    case TOKEN_THIN_ARROW:
        return "->";
    case TOKEN_FAT_ARROW:
        return "=>";
    case TOKEN_COMMA:
        return ",";
    case TOKEN_AT:
        return "@";
    case TOKEN_PERCENT:
        return "%";
    case TOKEN_DOUBLE_PERCENT:
        return "%%";
    case TOKEN_POUND:
        return "#";
    case TOKEN_DOLLAR:
        return "$";

    case TOKEN_EOF:
        return "EOF";

    default:
        return "INVALID_TOKEN";
    }
}

Bool token_kind_is_keyword(TokenKind kind)
{
    switch (kind) {
    case TOKEN_CONST:
    case TOKEN_VAR:
    case TOKEN_STATIC:
    case TOKEN_RETURN:
    case TOKEN_FOR:
    case TOKEN_IN:
    case TOKEN_DO:
    case TOKEN_BREAK:
    case TOKEN_CONTINUE:
    case TOKEN_IF:
    case TOKEN_ELSE:
    case TOKEN_SWITCH:
    case TOKEN_DEFER:
    case TOKEN_STRUCT:
    case TOKEN_ENUM:
    case TOKEN_TYPEDEF:
    case TOKEN_ABSTRACT:
    case TOKEN_CLASS:
    case TOKEN_FUN:
    case TOKEN_INCLUDE:
    case TOKEN_USE:
    case TOKEN_PUB:
    case TOKEN_EXTEND:
    case TOKEN_WITH:
    case TOKEN_AS:
        return true;
    default:
        return false;
    }
}

Bool token_kind_is_literal(TokenKind kind)
{
    switch (kind) {
    case TOKEN_INTEGER:
    case TOKEN_FLOAT:
    case TOKEN_CHARACTER:
    case TOKEN_STRING:
        return true;
    default:
        return false;
    }
}

Bool token_kind_is_comment(TokenKind kind)
{
    switch (kind) {
    case TOKEN_COMMENT:
        return true;
    default:
        return false;
    }
}

Bool token_kind_is_identifier(TokenKind kind)
{
    switch (kind) {
    case TOKEN_IDENTIFIER:
        return true;
    default:
        return false;
    }
}
