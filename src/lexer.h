#ifndef CYNIC_LEXER_H
#define CYNIC_LEXER_H

#include "token.h"

typedef struct Lexer Lexer;

struct Lexer {
    char* input;
    unsigned position;
    unsigned read_position;
    char ch;
    Token** token_list;
    unsigned token_count;
};

Lexer* lexer_new(char const* const input);

void lexer_free(Lexer* lexer);

void lexer_read_char(Lexer* lexer);

void lexer_add_token(Lexer* lexer, Token* token);

Token* lexer_next_token(Lexer* lexer);

#endif /* CYNIC_LEXER_H */
