#ifndef APA_LEXER_H
#define APA_LEXER_H

#include "token.h"

struct lexer {
    char *input;
    unsigned position;
    unsigned read_position;
    char ch;
    struct token **token_list;
    unsigned token_count;
};

struct lexer *lexer_new(char const *const input);

void lexer_free(struct lexer *lexer);

void lexer_read_char(struct lexer *lexer);

void lexer_add_token(struct lexer *lexer, struct token *token);

struct token *lexer_next_token(struct lexer *lexer);

#endif /* APA_LEXER_H */
