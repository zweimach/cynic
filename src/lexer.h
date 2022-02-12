#ifndef CYNIC_LEXER_H
#define CYNIC_LEXER_H

#include <stdint.h>

#include "token.h"
#include "types.h"

typedef struct Lexer Lexer;

struct Lexer {
    Char ch;
    UInt32 position;
    UInt32 read_position;
    UInt32 token_count;
    Token** token_list;
    Char* input;
};

Lexer* lexer_new(Char const* const input);

Void lexer_free(Lexer* lexer);

Void lexer_read_char(Lexer* lexer);

Void lexer_add_token(Lexer* lexer, Token* token);

Token* lexer_next_token(Lexer* lexer);

#endif /* CYNIC_LEXER_H */
