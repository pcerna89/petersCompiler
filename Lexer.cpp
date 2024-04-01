
// Lexer.cpp by Peter Cerna
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "StateTransitionTable.h"

using namespace std;

struct Token {
    string type;
    string lexeme;
};

// function to classify and update the current state
// returns the new state based on the current state and input character
LexerState nextState(LexerState currentState, char inputChar){
    CharClass charClass = OTHER; // default class

    if (isspace(inputChar)){
        charClass = WHITESPACE;
    }
    else if (isdigit(inputChar)){
        charClass = DIGIT;
    }
    else if (isalpha(inputChar)){
        charClass = LETTER;
    }

    return static_cast<; 

vector<Token> readAndClassifyTokens(const string &filename){
    vector<Token> tokens;
    ifstream file(filename);
    char c;
    LexerState currentState = START;

    if (!file.is_open()){
        cerr << "Error opening file '" << filename << "'" << endl;
        return tokens; // return empty vector in case of failure

    }

    while (file.get(c)){
        currentState = nextState(currentState, c);
    }

    file.close();
    return tokens;
}