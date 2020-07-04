#include <stdint.h>
#include <stdlib.h>

#include "token.h"

Token*
token_new(TokenKind kind, uint32_t start, uint32_t end)
{
    Token* token = malloc(sizeof(Token));
    if (!token) {
        return NULL;
    }

    token->kind = kind;
    token->start = start;
    token->end = end;

    return token;
}

void
token_free(Token* const token)
{
    if (!token) {
        return;
    }

    free(token);
}
