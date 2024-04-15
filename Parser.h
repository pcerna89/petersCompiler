
// Parser.h created by Peter Cerna
#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"

enum ParserClass { // our different parser states
    PARSE_SEMI,
    PARSE_ASSIGN,
    PARSE_PLUS,
    PARSE_MINUS,
    PARSE_LEFTPAREN,
    PARSE_RIGHTPAREN,
    PARSE_MUL,
    PARSE_DIV,
    PARSE_IF,
    PARSE_THEN,
    PARSE_ODD,
    PARSE_EQUALS,
    PARSE_NOTEQUAL,
    PARSE_GREATER,
    PARSE_LESS,
    PARSE_GREATEREQUAL,
    PARSE_LESSEQUAL,
    PARSE_LEFTBRACE,
    PARSE_RIGHTBRACE,
    PARSE_CALL,
    PARSE_PROC,
    PARSE_ELSE,
    PARSE_GET,
    PARSE_PUT
};

const int PARSER_STATES = 24;

extern char ParserTransitionTable[PARSER_STATES][PARSER_STATES];

void initializeParserTransitionTable();


#endif // PARSER_H