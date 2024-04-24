
// Lexer.h by Peter Cerna
#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "StateTransitionTable.h"
#include "FileReader.h"

using namespace std;

struct Token { // stores the token type and lexeme
    string type;
    string lexeme;
};

class Lexer { // tokenizes the input file
    public:
    Lexer(const string &filename);
    vector<Token> tokenize(); // main method to tokenize the input file

    private:
    FileReader fileReader; // handles file input
    vector<Token> tokens; // stores the tokens
    string currentLexeme = ""; // stores the current lexeme

    // helper methods
    CharClass classifyChar(char c); // classifies the character
    void addToken(const string &type, const string &lexeme); // adds a token to the token list
    LexerState getNextState(LexerState currentState, CharClass charClass); // gets the next state
    string lexerStateToString(LexerState state); // converts the lexer state to a string
};

#endif // LEXER_H
