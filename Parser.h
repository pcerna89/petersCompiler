
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
    vector<Token> tokens;
    size_t currentTokenIndex = 0;
    stack<Token> tokenStack; 

    bool canReduce(); // attempts to ressssduced based on the current state and tokens
    void reduce(); // reduces the tokens on the stack
    void processToken(const Token &token); // processes the current token
    ParserClass mapTokenToParserClass(const Token &token); // converts the token to a parser class

};


#endif // PARSER_H