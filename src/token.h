#ifndef CYNIC_TOKEN_H
#define CYNIC_TOKEN_H

typedef enum TokenType TokenType;

enum TokenType {
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

typedef struct Token Token;

struct Token {
    TokenType type;
    char* value;
};

Token* token_new(TokenType type, char const* const ch);

void token_free(Token* token);

char const* const token_type(TokenType t);

#endif /* CYNIC_TOKEN_H */
