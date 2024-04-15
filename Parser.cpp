
// Parser.cpp created by Peter Cerna
#include "Parser.h"

using namespace std;

char ParserTransitionTable[PARSER_STATES][PARSER_STATES];

void initializeParserTransitionTable(){
    ParserTransitionTable[PARSE_SEMI][PARSE_ASSIGN] = '<';

    ParserTransitionTable[PARSE_ASSIGN][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_DIV] = '<';

    ParserTransitionTable[PARSE_PLUS][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_PLUS] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_MINUS] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_PLUS][PARSE_RIGHTPAREN] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_PLUS][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_PLUS][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_EQUALS] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_NOTEQUAL] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_GREATER] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_LESS] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_GREATEREQUAL] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_LESSEQUAL] = '>';

    ParserTransitionTable[PARSE_MINUS][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_PLUS] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_MINUS] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_MINUS][PARSE_RIGHTPAREN] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_MINUS][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_MINUS][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_EQUALS] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_NOTEQUAL] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_GREATER] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_LESS] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_GREATEREQUAL] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_LESSEQUAL] = '>';

    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_RIGHTPAREN] = '=';
    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_DIV] = '<';

    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_PLUS] = '>';
    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_MINUS] = '>';
    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_RIGHTPAREN] = '>';
    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_MUL] = '>';
    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_DIV] = '>';

    ParserTransitionTable[PARSE_MUL][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_PLUS] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_MINUS] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_MUL][PARSE_RIGHTPAREN] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_MUL] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_DIV] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_EQUALS] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_NOTEQUAL] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_GREATER] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_LESS] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_GREATEREQUAL] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_LESSEQUAL] = '>';

    ParserTransitionTable[PARSE_DIV][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_PLUS] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_MINUS] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_DIV][PARSE_RIGHTPAREN] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_MUL] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_DIV] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_EQUALS] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_NOTEQUAL] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_GREATER] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_LESS] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_GREATEREQUAL] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_LESSEQUAL] = '>';

    ParserTransitionTable[PARSE_IF][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_LEFTBRACE] = '=';
    ParserTransitionTable[PARSE_IF][PARSE_ODD] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_EQUALS] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_NOTEQUAL] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_GREATER] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_LESS] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_GREATEREQUAL] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_LESSEQUAL] = '<';

    ParserTransitionTable[PARSE_THEN][PARSE_ASSIGN] = '<';
    ParserTransitionTable[PARSE_THEN][PARSE_IF] = '<';
    ParserTransitionTable[PARSE_THEN][PARSE_LEFTBRACE] = '<';
    ParserTransitionTable[PARSE_THEN][PARSE_CALL] = '<';

    ParserTransitionTable[PARSE_ODD][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_EQUALS][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_GREATER][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_LESS][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_THEN] = '>';
}

array  (const &token : tokens){

}