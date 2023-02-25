#include <lexer/lexer.h>

void separate(struct TokenList*, struct Token*);

struct TokenList* lexer(struct String* src) {
    struct TokenList* tklist = TokenList();

    struct Token* token = Token(0);

    for (unsigned i = 0; i < src->length + 1; i++) {
        switch(src->string[i]) {
        case 0:
        case ' ': separate(tklist, token); break;

        case ';':
        case ':': separate(tklist, token);

        default: String_AddC(token->string, src->string[i]); break;
        }
    }

    free(token);

    return tklist;
}

void separate(struct TokenList* tklist, struct Token* token) {
    if(token->string->length == 0) return;

    token->type =
    (token->string->string[0] >= '0' && token->string->string[0] <= '9') * TKType_Number +
    (token->string->string[0] >= 'A' && token->string->string[0] <= 'Z' || token->string->string[0] >= 'a' && token->string->string[0] <= 'z') * TKType_Identifier +
    (token->string->string[0] == ':') * TKType_DPoint +
    (token->string->string[0] == ';') * TKType_EOC
    ;

    TokenList_Add(tklist, token);

    token->type = 0;
    String_Clear(token->string);
}