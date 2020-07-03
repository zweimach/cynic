#include <stdlib.h>
#include <string.h>

#include "token.h"

struct token *token_new(enum token_type type, char const *const ch)
{
    struct token *token = calloc(1, sizeof(struct token));
    if (token) {
        token->type = type;
        token->value = calloc(strlen(ch) + 1, sizeof(char));
    }
    if (token->value && ch) {
        strcpy(token->value, ch);
    }
    return token;
}

void token_free(struct token *token)
{
    free(token->value);
    free(token);
}

char const *const token_type(enum token_type t)
{
    switch (t) {
    case T_ILLEGAL:
        return "ILLEGAL";
    case T_EOF:
        return "EOF";
    case T_IDENT:
        return "IDENT";
    case T_INT:
        return "INT";
    case T_ASSIGN:
        return "ASSIGN";
    case T_PLUS:
        return "PLUS";
    case T_COMMA:
        return "COMMA";
    case T_SEMICOLON:
        return "SEMICOLON";
    case T_LPAREN:
        return "LPAREN";
    case T_RPAREN:
        return "RPAREN";
    case T_LBRACE:
        return "LBRACE";
    case T_RBRACE:
        return "RBRACE";
    case T_FUNCTION:
        return "FUNCTION";
    case T_LET:
        return "LET";
    default:
        return "UNKNOWN";
    }
}
