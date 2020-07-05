#ifndef CYNIC_LEXER_H
#define CYNIC_LEXER_H

#include <stdint.h>

#include "token.h"

typedef struct Lexer Lexer;

struct Lexer {
    char* buffer;
    uint32_t index;
};

Lexer* lexer_new(char* const buffer);

void lexer_free(Lexer* lexer);

#endif /* CYNIC_LEXER_H */
