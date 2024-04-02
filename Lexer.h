
// Lexer.h by Peter Cerna
#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "StateTransitionTable.h"

using namespace std;

struct Token {
    string type;
    string lexeme;
};
string lexerStateToString(LexerState state);
LexerState nextState(LexerState currentState, char inputCharacter);
vector<Token> readAndClassifyTokens(const string &filename);

#endif // LEXER_H
