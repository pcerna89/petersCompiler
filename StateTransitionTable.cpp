
// StateTransitionTable.cpp by Peter Cerna
#include "StateTransitionTable.h"

int stateTransitionTable [TOTAL_STATES][CHAR_CLASSES]; // state transition table

void initializeStateTransitionTable(){ // initializes the state transition table
    // start state transitions
    stateTransitionTable[START][WHITESPACE] = START;
    stateTransitionTable[START][OTHER] = ERROR_ACCEPT;
    stateTransitionTable[START][DIGIT] = INT_HOLD;
    stateTransitionTable[START][LETTER] = VAR_HOLD;
    stateTransitionTable[START][STAR] = OP_ACCEPT;
    stateTransitionTable[START][PLUS] = OP_ACCEPT;
    stateTransitionTable[START][MINUS] = OP_ACCEPT;
    stateTransitionTable[START][SLASH] = SLASH_HOLD;
    stateTransitionTable[START][EQUALS] = EQUALS_HOLD;
    stateTransitionTable[START][LESS] = LESSER_HOLD;
    stateTransitionTable[START][GREATER] = GREATER_HOLD;
    stateTransitionTable[START][LPAREN] = PARENTHESES_ACCEPT;
    stateTransitionTable[START][RPAREN] = PARENTHESES_ACCEPT;
    stateTransitionTable[START][LBRACE] = BRACES_ACCEPT;
    stateTransitionTable[START][RBRACE] = BRACES_ACCEPT;
    stateTransitionTable[START][SEMICOLON] = SEMI_ACCEPT;
    stateTransitionTable[START][COMMA] = COMMA_ACCEPT;
    stateTransitionTable[START][NOT] = NOT_HOLD;
    stateTransitionTable[START][NEWLINE] = START;

    // error accept state transitions
    stateTransitionTable[ERROR_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[ERROR_ACCEPT][OTHER] = START;
    stateTransitionTable[ERROR_ACCEPT][DIGIT] = START;
    stateTransitionTable[ERROR_ACCEPT][LETTER] = START;
    stateTransitionTable[ERROR_ACCEPT][STAR] = START;
    stateTransitionTable[ERROR_ACCEPT][PLUS] = START;
    stateTransitionTable[ERROR_ACCEPT][MINUS] = START;
    stateTransitionTable[ERROR_ACCEPT][SLASH] = START;
    stateTransitionTable[ERROR_ACCEPT][EQUALS] = START;
    stateTransitionTable[ERROR_ACCEPT][LESS] = START;
    stateTransitionTable[ERROR_ACCEPT][GREATER] = START;
    stateTransitionTable[ERROR_ACCEPT][LPAREN] = START;
    stateTransitionTable[ERROR_ACCEPT][RPAREN] = START;
    stateTransitionTable[ERROR_ACCEPT][LBRACE] = START;
    stateTransitionTable[ERROR_ACCEPT][RBRACE] = START;
    stateTransitionTable[ERROR_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[ERROR_ACCEPT][COMMA] = START;
    stateTransitionTable[ERROR_ACCEPT][NOT] = START;
    stateTransitionTable[ERROR_ACCEPT][NEWLINE] = START;

    // integer hold state transitions
    stateTransitionTable[INT_HOLD][WHITESPACE] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][OTHER] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][DIGIT] = INT_HOLD;
    stateTransitionTable[INT_HOLD][LETTER] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][STAR] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][PLUS] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][MINUS] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][SLASH] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][EQUALS] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][LESS] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][GREATER] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][LPAREN] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][RPAREN] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][LBRACE] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][RBRACE] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][SEMICOLON] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][COMMA] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][NOT] = INT_ACCEPT;
    stateTransitionTable[INT_HOLD][NEWLINE] = INT_ACCEPT;
    
    // integer accept state transitions
    stateTransitionTable[INT_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[INT_ACCEPT][OTHER] = START;
    stateTransitionTable[INT_ACCEPT][DIGIT] = START;
    stateTransitionTable[INT_ACCEPT][LETTER] = START;
    stateTransitionTable[INT_ACCEPT][STAR] = START;
    stateTransitionTable[INT_ACCEPT][PLUS] = START;
    stateTransitionTable[INT_ACCEPT][MINUS] = START;
    stateTransitionTable[INT_ACCEPT][SLASH] = START;
    stateTransitionTable[INT_ACCEPT][EQUALS] = START;
    stateTransitionTable[INT_ACCEPT][LESS] = START;
    stateTransitionTable[INT_ACCEPT][GREATER] = START;
    stateTransitionTable[INT_ACCEPT][LPAREN] = START;
    stateTransitionTable[INT_ACCEPT][RPAREN] = START;
    stateTransitionTable[INT_ACCEPT][LBRACE] = START;
    stateTransitionTable[INT_ACCEPT][RBRACE] = START;
    stateTransitionTable[INT_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[INT_ACCEPT][COMMA] = START;
    stateTransitionTable[INT_ACCEPT][NOT] = START;
    stateTransitionTable[INT_ACCEPT][NEWLINE] = START;

    // variable hold state transitions
    stateTransitionTable[VAR_HOLD][WHITESPACE] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][OTHER] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][DIGIT] = VAR_HOLD;
    stateTransitionTable[VAR_HOLD][LETTER] = VAR_HOLD;
    stateTransitionTable[VAR_HOLD][STAR] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][PLUS] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][MINUS] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][SLASH] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][EQUALS] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][LESS] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][GREATER] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][LPAREN] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][RPAREN] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][LBRACE] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][RBRACE] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][SEMICOLON] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][COMMA] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][NOT] = VAR_ACCEPT;
    stateTransitionTable[VAR_HOLD][NEWLINE] = VAR_ACCEPT;

    // variable accept state transitions
    stateTransitionTable[VAR_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[VAR_ACCEPT][OTHER] = START;
    stateTransitionTable[VAR_ACCEPT][DIGIT] = START;
    stateTransitionTable[VAR_ACCEPT][LETTER] = START;
    stateTransitionTable[VAR_ACCEPT][STAR] = START;
    stateTransitionTable[VAR_ACCEPT][PLUS] = START;
    stateTransitionTable[VAR_ACCEPT][MINUS] = START;
    stateTransitionTable[VAR_ACCEPT][SLASH] = START;
    stateTransitionTable[VAR_ACCEPT][EQUALS] = START;
    stateTransitionTable[VAR_ACCEPT][LESS] = START;
    stateTransitionTable[VAR_ACCEPT][GREATER] = START;
    stateTransitionTable[VAR_ACCEPT][LPAREN] = START;
    stateTransitionTable[VAR_ACCEPT][RPAREN] = START;
    stateTransitionTable[VAR_ACCEPT][LBRACE] = START;
    stateTransitionTable[VAR_ACCEPT][RBRACE] = START;
    stateTransitionTable[VAR_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[VAR_ACCEPT][COMMA] = START;
    stateTransitionTable[VAR_ACCEPT][NOT] = START;
    stateTransitionTable[VAR_ACCEPT][NEWLINE] = START;

    // operator accept state transitions
    stateTransitionTable[OP_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[OP_ACCEPT][OTHER] = START;
    stateTransitionTable[OP_ACCEPT][DIGIT] = START;
    stateTransitionTable[OP_ACCEPT][LETTER] = START;
    stateTransitionTable[OP_ACCEPT][STAR] = START;
    stateTransitionTable[OP_ACCEPT][PLUS] = START;
    stateTransitionTable[OP_ACCEPT][MINUS] = START;
    stateTransitionTable[OP_ACCEPT][SLASH] = START;
    stateTransitionTable[OP_ACCEPT][EQUALS] = START;
    stateTransitionTable[OP_ACCEPT][LESS] = START;
    stateTransitionTable[OP_ACCEPT][GREATER] = START;
    stateTransitionTable[OP_ACCEPT][LPAREN] = START;
    stateTransitionTable[OP_ACCEPT][RPAREN] = START;
    stateTransitionTable[OP_ACCEPT][LBRACE] = START;
    stateTransitionTable[OP_ACCEPT][RBRACE] = START;
    stateTransitionTable[OP_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[OP_ACCEPT][COMMA] = START;
    stateTransitionTable[OP_ACCEPT][NOT] = START;
    stateTransitionTable[OP_ACCEPT][NEWLINE] = START;

    // slash hold state transitions
    stateTransitionTable[SLASH_HOLD][WHITESPACE] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][OTHER] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][DIGIT] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][LETTER] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][STAR] = COMMENT_HOLD;
    stateTransitionTable[SLASH_HOLD][PLUS] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][MINUS] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][SLASH] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][EQUALS] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][LESS] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][GREATER] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][LPAREN] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][RPAREN] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][LBRACE] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][RBRACE] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][SEMICOLON] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][COMMA] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][NOT] = DIVOP_ACCEPT;
    stateTransitionTable[SLASH_HOLD][NEWLINE] = DIVOP_ACCEPT;

    // division operator accept state transitions
    stateTransitionTable[DIVOP_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[DIVOP_ACCEPT][OTHER] = START;
    stateTransitionTable[DIVOP_ACCEPT][DIGIT] = START;
    stateTransitionTable[DIVOP_ACCEPT][LETTER] = START;
    stateTransitionTable[DIVOP_ACCEPT][STAR] = START;
    stateTransitionTable[DIVOP_ACCEPT][PLUS] = START;
    stateTransitionTable[DIVOP_ACCEPT][MINUS] = START;
    stateTransitionTable[DIVOP_ACCEPT][SLASH] = START;
    stateTransitionTable[DIVOP_ACCEPT][EQUALS] = START;
    stateTransitionTable[DIVOP_ACCEPT][LESS] = START;
    stateTransitionTable[DIVOP_ACCEPT][GREATER] = START;
    stateTransitionTable[DIVOP_ACCEPT][LPAREN] = START;
    stateTransitionTable[DIVOP_ACCEPT][RPAREN] = START;
    stateTransitionTable[DIVOP_ACCEPT][LBRACE] = START;
    stateTransitionTable[DIVOP_ACCEPT][RBRACE] = START;
    stateTransitionTable[DIVOP_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[DIVOP_ACCEPT][COMMA] = START;
    stateTransitionTable[DIVOP_ACCEPT][NOT] = START;
    stateTransitionTable[DIVOP_ACCEPT][NEWLINE] = START;

    // comment hold state transitions
    stateTransitionTable[COMMENT_HOLD][WHITESPACE] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][OTHER] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][DIGIT] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][LETTER] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][STAR] = COMMENT_END;
    stateTransitionTable[COMMENT_HOLD][PLUS] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][MINUS] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][SLASH] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][EQUALS] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][LESS] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][GREATER] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][LPAREN] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][RPAREN] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][LBRACE] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][RBRACE] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][SEMICOLON] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][COMMA] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][NOT] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_HOLD][NEWLINE] = COMMENT_HOLD;

    // comment end state transitions
    stateTransitionTable[COMMENT_END][WHITESPACE] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][OTHER] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][DIGIT] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][LETTER] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][STAR] = COMMENT_END;
    stateTransitionTable[COMMENT_END][PLUS] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][MINUS] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][SLASH] = START;
    stateTransitionTable[COMMENT_END][EQUALS] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][LESS] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][GREATER] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][LPAREN] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][RPAREN] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][LBRACE] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][RBRACE] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][SEMICOLON] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][COMMA] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][NOT] = COMMENT_HOLD;
    stateTransitionTable[COMMENT_END][NEWLINE] = COMMENT_HOLD;

    // equals hold state transitions
    stateTransitionTable[EQUALS_HOLD][WHITESPACE] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][OTHER] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][DIGIT] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][LETTER] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][STAR] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][PLUS] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][MINUS] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][SLASH] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][EQUALS] = EQUALITY_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][LESS] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][GREATER] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][LPAREN] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][RPAREN] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][LBRACE] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][RBRACE] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][SEMICOLON] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][COMMA] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][NOT] = ASSIGNMENT_ACCEPT;
    stateTransitionTable[EQUALS_HOLD][NEWLINE] = ASSIGNMENT_ACCEPT;

    // assignment accept state transitions
    stateTransitionTable[ASSIGNMENT_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][OTHER] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][DIGIT] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][LETTER] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][STAR] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][PLUS] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][MINUS] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][SLASH] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][EQUALS] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][LESS] = START; 
    stateTransitionTable[ASSIGNMENT_ACCEPT][GREATER] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][LPAREN] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][RPAREN] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][LBRACE] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][RBRACE] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][COMMA] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][NOT] = START;
    stateTransitionTable[ASSIGNMENT_ACCEPT][NEWLINE] = START;

    // equality accept state transitions
    stateTransitionTable[EQUALITY_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[EQUALITY_ACCEPT][OTHER] = START;
    stateTransitionTable[EQUALITY_ACCEPT][DIGIT] = START;
    stateTransitionTable[EQUALITY_ACCEPT][LETTER] = START;
    stateTransitionTable[EQUALITY_ACCEPT][STAR] = START;
    stateTransitionTable[EQUALITY_ACCEPT][PLUS] = START;
    stateTransitionTable[EQUALITY_ACCEPT][MINUS] = START;
    stateTransitionTable[EQUALITY_ACCEPT][SLASH] = START;
    stateTransitionTable[EQUALITY_ACCEPT][EQUALS] = START;
    stateTransitionTable[EQUALITY_ACCEPT][LESS] = START;
    stateTransitionTable[EQUALITY_ACCEPT][GREATER] = START;
    stateTransitionTable[EQUALITY_ACCEPT][LPAREN] = START;
    stateTransitionTable[EQUALITY_ACCEPT][RPAREN] = START;
    stateTransitionTable[EQUALITY_ACCEPT][LBRACE] = START;
    stateTransitionTable[EQUALITY_ACCEPT][RBRACE] = START;
    stateTransitionTable[EQUALITY_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[EQUALITY_ACCEPT][COMMA] = START;
    stateTransitionTable[EQUALITY_ACCEPT][NOT] = START;
    stateTransitionTable[EQUALITY_ACCEPT][NEWLINE] = START;

    // lesser hold state transitions
    stateTransitionTable[LESSER_HOLD][WHITESPACE] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][OTHER] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][DIGIT] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][LETTER] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][STAR] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][PLUS] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][MINUS] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][SLASH] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][EQUALS] = LESS_OR_EQUAL_ACCEPT;
    stateTransitionTable[LESSER_HOLD][LESS] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][GREATER] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][LPAREN] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][RPAREN] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][LBRACE] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][RBRACE] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][SEMICOLON] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][COMMA] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][NOT] = LESSER_ACCEPT;
    stateTransitionTable[LESSER_HOLD][NEWLINE] = LESSER_ACCEPT;

    // lesser accept state transitions
    stateTransitionTable[LESSER_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[LESSER_ACCEPT][OTHER] = START;
    stateTransitionTable[LESSER_ACCEPT][DIGIT] = START;
    stateTransitionTable[LESSER_ACCEPT][LETTER] = START;
    stateTransitionTable[LESSER_ACCEPT][STAR] = START;
    stateTransitionTable[LESSER_ACCEPT][PLUS] = START;
    stateTransitionTable[LESSER_ACCEPT][MINUS] = START;
    stateTransitionTable[LESSER_ACCEPT][SLASH] = START;
    stateTransitionTable[LESSER_ACCEPT][EQUALS] = START;
    stateTransitionTable[LESSER_ACCEPT][LESS] = START;
    stateTransitionTable[LESSER_ACCEPT][GREATER] = START;
    stateTransitionTable[LESSER_ACCEPT][LPAREN] = START;
    stateTransitionTable[LESSER_ACCEPT][RPAREN] = START;
    stateTransitionTable[LESSER_ACCEPT][LBRACE] = START;
    stateTransitionTable[LESSER_ACCEPT][RBRACE] = START;
    stateTransitionTable[LESSER_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[LESSER_ACCEPT][COMMA] = START;
    stateTransitionTable[LESSER_ACCEPT][NOT] = START;
    stateTransitionTable[LESSER_ACCEPT][NEWLINE] = START;

    // less or equal accept state transitions
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][OTHER] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][DIGIT] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][LETTER] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][STAR] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][PLUS] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][MINUS] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][SLASH] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][EQUALS] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][LESS] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][GREATER] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][LPAREN] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][RPAREN] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][LBRACE] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][RBRACE] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][COMMA] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][NOT] = START;
    stateTransitionTable[LESS_OR_EQUAL_ACCEPT][NEWLINE] = START;

    // greater hold state transitions
    stateTransitionTable[GREATER_HOLD][WHITESPACE] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][OTHER] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][DIGIT] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][LETTER] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][STAR] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][PLUS] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][MINUS] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][SLASH] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][EQUALS] = GREATER_OR_EQUAL_ACCEPT;
    stateTransitionTable[GREATER_HOLD][LESS] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][GREATER] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][LPAREN] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][RPAREN] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][LBRACE] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][RBRACE] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][SEMICOLON] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][COMMA] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][NOT] = GREATER_ACCEPT;
    stateTransitionTable[GREATER_HOLD][NEWLINE] = GREATER_ACCEPT;

    // greater accept state transitions
    stateTransitionTable[GREATER_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[GREATER_ACCEPT][OTHER] = START;
    stateTransitionTable[GREATER_ACCEPT][DIGIT] = START;
    stateTransitionTable[GREATER_ACCEPT][LETTER] = START;
    stateTransitionTable[GREATER_ACCEPT][STAR] = START;
    stateTransitionTable[GREATER_ACCEPT][PLUS] = START;
    stateTransitionTable[GREATER_ACCEPT][MINUS] = START;
    stateTransitionTable[GREATER_ACCEPT][SLASH] = START;
    stateTransitionTable[GREATER_ACCEPT][EQUALS] = START;
    stateTransitionTable[GREATER_ACCEPT][LESS] = START;
    stateTransitionTable[GREATER_ACCEPT][GREATER] = START;
    stateTransitionTable[GREATER_ACCEPT][LPAREN] = START;
    stateTransitionTable[GREATER_ACCEPT][RPAREN] = START;
    stateTransitionTable[GREATER_ACCEPT][LBRACE] = START;
    stateTransitionTable[GREATER_ACCEPT][RBRACE] = START;
    stateTransitionTable[GREATER_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[GREATER_ACCEPT][COMMA] = START;
    stateTransitionTable[GREATER_ACCEPT][NOT] = START;
    stateTransitionTable[GREATER_ACCEPT][NEWLINE] = START;

    // greater or equal accept state transitions
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][OTHER] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][DIGIT] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][LETTER] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][STAR] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][PLUS] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][MINUS] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][SLASH] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][EQUALS] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][LESS] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][GREATER] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][LPAREN] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][RPAREN] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][LBRACE] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][RBRACE] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][COMMA] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][NOT] = START;
    stateTransitionTable[GREATER_OR_EQUAL_ACCEPT][NEWLINE] = START;
    
    // parentheses accept state transitions
    stateTransitionTable[PARENTHESES_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][OTHER] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][DIGIT] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][LETTER] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][STAR] = START; 
    stateTransitionTable[PARENTHESES_ACCEPT][PLUS] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][MINUS] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][SLASH] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][EQUALS] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][LESS] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][GREATER] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][LPAREN] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][RPAREN] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][LBRACE] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][RBRACE] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][COMMA] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][NOT] = START;
    stateTransitionTable[PARENTHESES_ACCEPT][NEWLINE] = START;

    // braces accept state transitions
    stateTransitionTable[BRACES_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[BRACES_ACCEPT][OTHER] = START;
    stateTransitionTable[BRACES_ACCEPT][DIGIT] = START;
    stateTransitionTable[BRACES_ACCEPT][LETTER] = START;
    stateTransitionTable[BRACES_ACCEPT][STAR] = START;
    stateTransitionTable[BRACES_ACCEPT][PLUS] = START;
    stateTransitionTable[BRACES_ACCEPT][MINUS] = START;
    stateTransitionTable[BRACES_ACCEPT][SLASH] = START;
    stateTransitionTable[BRACES_ACCEPT][EQUALS] = START;
    stateTransitionTable[BRACES_ACCEPT][LESS] = START;
    stateTransitionTable[BRACES_ACCEPT][GREATER] = START;
    stateTransitionTable[BRACES_ACCEPT][LPAREN] = START;
    stateTransitionTable[BRACES_ACCEPT][RPAREN] = START;
    stateTransitionTable[BRACES_ACCEPT][LBRACE] = START;
    stateTransitionTable[BRACES_ACCEPT][RBRACE] = START;
    stateTransitionTable[BRACES_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[BRACES_ACCEPT][COMMA] = START;
    stateTransitionTable[BRACES_ACCEPT][NOT] = START;
    stateTransitionTable[BRACES_ACCEPT][NEWLINE] = START;

    // semicolon accept state transitions
    stateTransitionTable[SEMI_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[SEMI_ACCEPT][OTHER] = START;
    stateTransitionTable[SEMI_ACCEPT][DIGIT] = START;
    stateTransitionTable[SEMI_ACCEPT][LETTER] = START;
    stateTransitionTable[SEMI_ACCEPT][STAR] = START;
    stateTransitionTable[SEMI_ACCEPT][PLUS] = START;
    stateTransitionTable[SEMI_ACCEPT][MINUS] = START;
    stateTransitionTable[SEMI_ACCEPT][SLASH] = START;
    stateTransitionTable[SEMI_ACCEPT][EQUALS] = START;
    stateTransitionTable[SEMI_ACCEPT][LESS] = START;
    stateTransitionTable[SEMI_ACCEPT][GREATER] = START;
    stateTransitionTable[SEMI_ACCEPT][LPAREN] = START;
    stateTransitionTable[SEMI_ACCEPT][RPAREN] = START;
    stateTransitionTable[SEMI_ACCEPT][LBRACE] = START;
    stateTransitionTable[SEMI_ACCEPT][RBRACE] = START;
    stateTransitionTable[SEMI_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[SEMI_ACCEPT][COMMA] = START;
    stateTransitionTable[SEMI_ACCEPT][NOT] = START;
    stateTransitionTable[SEMI_ACCEPT][NEWLINE] = START;

    // comma accept state transitions
    stateTransitionTable[COMMA_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[COMMA_ACCEPT][OTHER] = START;
    stateTransitionTable[COMMA_ACCEPT][DIGIT] = START;
    stateTransitionTable[COMMA_ACCEPT][LETTER] = START;
    stateTransitionTable[COMMA_ACCEPT][STAR] = START;
    stateTransitionTable[COMMA_ACCEPT][PLUS] = START;
    stateTransitionTable[COMMA_ACCEPT][MINUS] = START;
    stateTransitionTable[COMMA_ACCEPT][SLASH] = START;
    stateTransitionTable[COMMA_ACCEPT][EQUALS] = START;
    stateTransitionTable[COMMA_ACCEPT][LESS] = START;
    stateTransitionTable[COMMA_ACCEPT][GREATER] = START;
    stateTransitionTable[COMMA_ACCEPT][LPAREN] = START;
    stateTransitionTable[COMMA_ACCEPT][RPAREN] = START;
    stateTransitionTable[COMMA_ACCEPT][LBRACE] = START;
    stateTransitionTable[COMMA_ACCEPT][RBRACE] = START;
    stateTransitionTable[COMMA_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[COMMA_ACCEPT][COMMA] = START;
    stateTransitionTable[COMMA_ACCEPT][NOT] = START;
    stateTransitionTable[COMMA_ACCEPT][NEWLINE] = START;

    // not hold state transitions
    stateTransitionTable[NOT_HOLD][WHITESPACE] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][OTHER] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][DIGIT] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][LETTER] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][STAR] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][PLUS] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][MINUS] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][SLASH] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][EQUALS] = NOT_EQUAL_ACCEPT;
    stateTransitionTable[NOT_HOLD][LESS] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][GREATER] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][LPAREN] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][RPAREN] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][LBRACE] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][RBRACE] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][SEMICOLON] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][COMMA] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][NOT] = NOT_ACCEPT;
    stateTransitionTable[NOT_HOLD][NEWLINE] = NOT_ACCEPT;
    
    // not accept state transitions
    stateTransitionTable[NOT_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[NOT_ACCEPT][OTHER] = START;
    stateTransitionTable[NOT_ACCEPT][DIGIT] = START;
    stateTransitionTable[NOT_ACCEPT][LETTER] = START;
    stateTransitionTable[NOT_ACCEPT][STAR] = START;
    stateTransitionTable[NOT_ACCEPT][PLUS] = START;
    stateTransitionTable[NOT_ACCEPT][MINUS] = START;
    stateTransitionTable[NOT_ACCEPT][SLASH] = START;
    stateTransitionTable[NOT_ACCEPT][EQUALS] = START;
    stateTransitionTable[NOT_ACCEPT][LESS] = START;
    stateTransitionTable[NOT_ACCEPT][GREATER] = START;
    stateTransitionTable[NOT_ACCEPT][LPAREN] = START;
    stateTransitionTable[NOT_ACCEPT][RPAREN] = START;
    stateTransitionTable[NOT_ACCEPT][LBRACE] = START;
    stateTransitionTable[NOT_ACCEPT][RBRACE] = START;
    stateTransitionTable[NOT_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[NOT_ACCEPT][COMMA] = START;
    stateTransitionTable[NOT_ACCEPT][NOT] = START;
    stateTransitionTable[NOT_ACCEPT][NEWLINE] = START;

    // not equal accept state transitions
    stateTransitionTable[NOT_EQUAL_ACCEPT][WHITESPACE] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][OTHER] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][DIGIT] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][LETTER] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][STAR] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][PLUS] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][MINUS] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][SLASH] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][EQUALS] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][LESS] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][GREATER] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][LPAREN] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][RPAREN] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][LBRACE] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][RBRACE] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][SEMICOLON] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][COMMA] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][NOT] = START;
    stateTransitionTable[NOT_EQUAL_ACCEPT][NEWLINE] = START;
}

