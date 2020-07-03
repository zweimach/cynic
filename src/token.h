#ifndef APA_TOKEN_H
#define APA_TOKEN_H

enum token_type {
    /* Specials */
    T_ILLEGAL,
    T_EOF,
    /* Identifiers */
    T_IDENT,
    /* Literals */
    T_INT,
    /* Operators */
    T_ASSIGN,
    T_PLUS,
    /* Delimiters */
    T_COMMA,
    T_SEMICOLON,
    T_LPAREN,
    T_RPAREN,
    T_LBRACE,
    T_RBRACE,
    /* Keywords */
    T_FUNCTION,
    T_LET,
};

struct token {
    enum token_type type;
    char *value;
};

struct token *token_new(enum token_type type, char const *const ch);

void token_free(struct token *token);

char const *const token_type(enum token_type t);

#endif /* APA_TOKEN_H */
