#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "token.h"

Lexer*
lexer_new(char* const buffer)
{
    size_t const buffer_length = buffer ? strlen(buffer) : 0;
    if (buffer_length == 0) {
        return NULL;
    }

    Lexer* lexer = malloc(sizeof(Lexer));
    if (!lexer) {
        return NULL;
    }

    lexer->buffer = calloc(buffer_length + 1, sizeof(char));
    if (!lexer->buffer) {
        free(lexer);
        return NULL;
    }

    strncpy(lexer->buffer, buffer, buffer_length);

    return lexer;
}

void
lexer_free(Lexer* lexer)
{
    if (!lexer) {
        return;
    }

    if (lexer->buffer) {
        free(lexer->buffer);
    }

    free(lexer);
}
