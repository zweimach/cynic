#include <stdio.h>
#include <string.h>

#include "lexer.h"
#include "token.h"
#include "types.h"

Int main(Int argc, Char** argv)
{
    Char const* const input = "=+(){},;";
    Token tests[] = {
        {TOKEN_ASSIGN, "="},
        {TOKEN_PLUS, "+"},
        {TOKEN_OPEN_PAREN, "("},
        {TOKEN_CLOSE_PAREN, ")"},
        {TOKEN_OPEN_CURLY, "{"},
        {TOKEN_CLOSE_CURLY, "}"},
        {TOKEN_COMMA, ","},
        {TOKEN_SEMICOLON, ";"},
        {TOKEN_EOF, "\0"},
    };

    Lexer* lexer = lexer_new(input);

    for (USize i = 0; i <= strlen(input); i++) {
        Token* token = lexer_next_token(lexer);
        printf("%u %u\n", token->kind, tests[i].kind);
        printf("%s %s\n", token->value, tests[i].value);
    }

    lexer_free(lexer);
}
