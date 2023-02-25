#ifndef PIRD_STRING_HEADER
#define PIRD_STRING_HEADER

#pragma once
#include <string.h>

#include <stdlib.h>

struct String {
    unsigned length;
    char* string;
};

struct String* String();
struct String* StringS(char*);
struct String* StringSL(char*, unsigned);
struct String* StringCopy(struct String*);
void String_AddC(struct String*, char);
void String_Clear(struct String*);

#endif