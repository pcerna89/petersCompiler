
// StateTransitionTable.h by Peter Cerna
#ifndef STATE_TRANSITION_TABLE_H
#define STATE_TRANSITION_TABLE_H
#include <vector>
#include <string>
using namespace std;
extern vector<string> ReservedWord; // stores the reserved words

enum LexerState { // our different lexer states
    START,
    ERROR_ACCEPT,
    INT_HOLD,
    INT_ACCEPT,
    VAR_HOLD,
    VAR_ACCEPT,
    OP_ACCEPT,
    SLASH_HOLD,
    DIVOP_ACCEPT,
    COMMENT_HOLD,
    COMMENT_END,
    EQUALS_HOLD,
    ASSIGNMENT_ACCEPT,
    EQUALITY_ACCEPT,
    LESSER_HOLD,
    LESSER_ACCEPT,
    LESS_OR_EQUAL_ACCEPT,
    GREATER_HOLD,
    GREATER_ACCEPT,
    GREATER_OR_EQUAL_ACCEPT,
    PARENTHESES_ACCEPT,
    BRACES_ACCEPT,
    SEMI_ACCEPT,
    COMMA_ACCEPT,
    NOT_HOLD,
    NOT_ACCEPT,
    NOT_EQUAL_ACCEPT
};
enum CharClass { // our different character classes
    WHITESPACE,
    OTHER,
    DIGIT,
    LETTER,
    STAR,
    PLUS,
    MINUS,
    SLASH,
    EQUALS,
    LESS,
    GREATER,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    SEMICOLON,
    COMMA,
    NOT,
    NEWLINE,
};


const int TOTAL_STATES = 27; 
const int CHAR_CLASSES = 19;

extern int stateTransitionTable[TOTAL_STATES][CHAR_CLASSES]; // stores the state transitions

void initializeStateTransitionTable(); 

#endif // STATE_TRANSITION_TABLE_H
