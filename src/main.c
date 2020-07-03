#include <stdio.h>
#include <string.h>

#include "lexer.h"
#include "token.h"

int main(int argc, char **argv)
{
    char const *const input = "=+(){},;";
    struct token tests[] = {
        {T_ASSIGN, "="},
        {T_PLUS, "+"},
        {T_LPAREN, "("},
        {T_RPAREN, ")"},
        {T_LBRACE, "{"},
        {T_RBRACE, "}"},
        {T_COMMA, ","},
        {T_SEMICOLON, ";"},
        {T_EOF, ""},
    };
    struct lexer *lexer = lexer_new(input);

    for (unsigned i = 0; i <= strlen(input); i++) {
        struct token *token = lexer_next_token(lexer);
        printf("%s %s\n", token_type(token->type), token_type(tests[i].type));
        printf("%s %s\n", token->value, tests[i].value);
    }
    lexer_free(lexer);
}
