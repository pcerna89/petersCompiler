
// Parser.h created by Peter Cerna
#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

// using enums for clarity 
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
    PARSE_ELSE,
    PARSE_WHILE,
    PARSE_DO,
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
    PARSE_COMMA,
    PARSE_READ,
    PARSE_WRITE,
    NON_OP
};
const int PARSER_STATES = 28;
extern char ParserTransitionTable[PARSER_STATES][PARSER_STATES];
// operator precedence table
void initializeParserTransitionTable();

struct Quad { // stores the quadruple
    string op;
    string arg1;
    string arg2;
    string result;
};

class Parser {
    public:
    Parser(const vector<Token> &tokens); // constructor to take our vector of tokens
    void parse(); // main parsing function
    stack<Quad> getQuadStack() const {
        return quadStack;
    } // returns the quad stack

    private:
    stack<Token> tokenStack; // stack to hold our tokens
    stack<Quad> quadStack; // stack to hold our quads
    vector<Token> tokens; // tokens to be parsed
    Token mostRecentOperatorUsed; // most recent operator in the stack
    //int tempVariableUsedCounter = 1; // counter for our temporary variables
    vector<string> tempVariables; // vector to hold our temporary variables
    set<int> availableTemps;
    stack<string> fixUpStack; // stack to hold our fixups
    stack<string> endStack; // stack to hold our else ends
    size_t currentIndex; // current index of the token
    stack<string> whileStack; // stack to hold our whiles

    // parser helper functions
    void handleOperator(const Token &incomingToken); // handles the operator
    void reduce(const Token & triggerToken); // reduces the tokens on the stack
    ParserClass identifyTokenToParserClass(const Token &token); // converts the token to a parser class
    Token findLastLowerOperator(); // finds the next lower operator after a reduction is made
    void printQuadStack(); // prints the quad stack
    void handleSpecialCases(const Token &currentToken); // handles special cases
    string getTemp(); // gets a temporary variable
    void releaseTemp(const string &temp); // releases a temporary variable
    void handleIfThenElse(const Token &currentToken); // handles the if then else statement
    string invertCondition(const string &condition); // inverts the condition
    string generateLabel(); // generates a label for our THEN and ELSE statements
    Token peekNextToken(); // peeks at the next token
    Token peekPrevToken(); // peeks at the previous token
    void popIfThen(const Token &currentToken); // pops the if then
    void popIfThenElse(const Token &currentToken); // pops the if then else
    string generateWhileLabel(); // generates a label for our while statements
    void handleWhileDo(const Token &currentToken); // handles the while do statement
    void popWhileDo(const Token &currentToken); // pops the while do

    void generateArithmeticQuad(const Token &operatorToken, const Token &leftOperand, const Token &rightOperand); // generates the arithmetic quad
    void generateAssignmentQuad(const Token &leftOperand, const Token &rightOperand); // generates the assignment quad
    void generateRelationalQuad(const Token &operatorToken, const Token &leftOperand, const Token &rightOperand); // generates the relational quad
    void generateIfQuad(); // generates the if quad
    void generateThenQuad();
    void generateIfThenQuad();
    void generateElseQuad();
    void generateIfThenElseQuad();
    void generateWhileQuad();
    void generateDoQuad();
    void generateWhileDoQuad();
    void generateReadQuad();
    void generateWriteQuad();
};
#endif // PARSER_H