#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <cmocka.h>

#include "lexer.h"
#include "token.h"
#include "types.h"

static Void lexer_test(Void** state)
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

    for (size_t i = 0; i <= strlen(input); i++) {
        Token* token = lexer_next_token(lexer);
        assert_int_equal(token->kind, tests[i].kind);
        assert_string_equal(token->value, tests[i].value);
    }
    lexer_free(lexer);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(lexer_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
