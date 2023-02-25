#ifndef PIRD_LEXER_HEADER
#define PIRD_LEXER_HEADER

#pragma once
#include "string.h"

#include <stdlib.h>

// ---------------------TOKEN--------------------- //

enum TKType {
    TKType_Null      ,
    TKType_Identifier,
    TKType_Type      ,

    TKType_Number    ,

    TKType_Setter    ,
    TKType_DPoint    , //Double Point
    TKType_EOC       ,
};

struct Token {
    enum TKType type;
    struct String* string;
};

struct TokenList {
    unsigned length;
    struct Token** tokens;
};

struct Token* Token(enum TKType);
struct Token* TokenCopy(struct Token*);

struct TokenList* TokenList();
void TokenList_Add(struct TokenList*, struct Token*);

// ---------------------TOKEN--------------------- //

// ---------------------LEXER--------------------- //

struct TokenList* lexer(struct String*);

// ---------------------LEXER--------------------- //

#endif