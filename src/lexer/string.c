#include <lexer/string.h>

struct String* String() {
    struct String* string = malloc(sizeof(struct String));
    string->string = malloc(string->length = 0);

    return string;
}

struct String* StringS(char* value) {
    return StringSL(value, (unsigned) strlen(value));
}

struct String* StringSL(char* value, unsigned length) {
    struct String* string = malloc(sizeof(struct String));
    string->length = length;
    string->string = malloc((length + 1) * sizeof(char));
    strncpy(string->string, value, length * sizeof(char));
    string->string[length] = 0;

    return string;
}

struct String* StringCopy(struct String* string) { return StringSL(string->string, string->length); }

void String_AddC(struct String* string, char c) {
    string->string = realloc(string->string, (++string->length + 1) * sizeof(char));
    string->string[string->length - 1] = c;
    string->string[string->length] = 0;
}

void String_Clear(struct String* string) {
    string->string = realloc(string->string, string->length = 0);
}