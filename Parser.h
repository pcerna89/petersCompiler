
// Parser.h created by Peter Cerna
#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include <stack>
using namespace std;

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
    PARSE_PUT,
    NON_OP
};

const int PARSER_STATES = 25;

extern char ParserTransitionTable[PARSER_STATES][PARSER_STATES];

void initializeParserTransitionTable();

class Parser {
    public:
    Parser(const vector<Token> &tokens); // constructor to take our vector of tokens
    void parse(); // main parsing function

    private:
    stack<Token> tokenStack; // stack to hold our tokens
    vector<Token> tokens; // tokens to be parsed
    Token mostRecentOpInStack; // most recent operator in the stack

    bool isOperator(const Token &incomingToken); // checks if the token is an operator
    void handleOperator(const Token &incomingToken); // handles the operator
    void reduce(); // reduces the tokens on the stack

    ParserClass identifyTokenToParserClass(const Token &token); // converts the token to a parser class

};


#endif // PARSER_H