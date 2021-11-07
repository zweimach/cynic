#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <cmocka.h>

#include "lexer.h"
#include "token.h"

static void lexer_test(void** state)
{
    (void)state;

    char const* const input = "=+(){},;";
    Token tests[] = {
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
    Lexer* lexer = lexer_new(input);

    for (unsigned i = 0; i <= strlen(input); i++) {
        Token* token = lexer_next_token(lexer);
        assert_string_equal(token_type(token->type), token_type(tests[i].type));
        assert_string_equal(token->value, tests[i].value);
    }
    lexer_free(lexer);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(lexer_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
