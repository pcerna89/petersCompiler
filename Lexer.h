
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

struct Token {
    string type;
    string lexeme;
};

class Lexer {
    public:
    Lexer(const string &filename);
    vector<Token> tokenize(); // main method to tokenize the input file

    private:
    FileReader fileReader; // handles file input
    vector<Token> tokens; // stores the tokens
    string currentLexeme = ""; // stores the current lexeme

    // helper methods
    CharClass classifyChar(char c);
    void addToken(const string &type, const string &lexeme);
    LexerState getNextState(LexerState currentState, CharClass charClass);
    string lexerStateToString(LexerState state);
};

#endif // LEXER_H
