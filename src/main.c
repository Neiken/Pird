#include <lexer/lexer.h>

#include <stdio.h>

int main() {
    struct String* code = StringS("int numero: 4;");

    struct TokenList* tklist = lexer(code);

    printf("%u\n", tklist->length);

    for(unsigned i = 0; i < tklist->length; i++) {
        printf("Token %u: type=%d string=%s\n", i, tklist->tokens[i]->type, tklist->tokens[i]->string->string);
    }

    free(tklist);

    free(code);
}