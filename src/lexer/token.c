#include <lexer/lexer.h>

struct Token* Token(enum TKType type) {
    struct Token* token = malloc(sizeof(struct Token));
    token->type = type;
    token->string = String();

    return token;
}

struct Token* TokenCopy(struct Token* token) {
    struct Token* token_copy = malloc(sizeof(struct Token));
    token_copy->type = token->type;
    token_copy->string = StringCopy(token->string);

    return token_copy;
}

struct TokenList* TokenList() {
    struct TokenList* tklist = malloc(sizeof(struct TokenList));
    tklist->tokens = malloc(tklist->length = 0);

    return tklist;
}

void TokenList_Add(struct TokenList* tklist, struct Token* token) {
    struct Token* token_copy = TokenCopy(token);

    tklist->tokens = realloc(tklist->tokens, ++tklist->length * sizeof(struct Token*));
    tklist->tokens[tklist->length - 1] = token_copy;
}