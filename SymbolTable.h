// SymbolTable.h by Peter Cerna
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include <iostream>
#include <vector>
#include <string>
#include "Lexer.h"
using namespace std;

enum SymState { // our different symbol states
    SYM_BEGIN,
    SYM_PRGM_DEC,
    SYM_PRGM_ACC,
    SYM_START,
    SYM_CONST_DEC,
    SYM_CONST_VAR,
    SYM_CONST_ASSIGN,
    SYM_CONST_ACC,
    SYM_VAR_DEC,
    SYM_VAR_ACC,
    SYM_PROC_DEC,
    SYM_PROC_ACC,
    SYM_INTERIM,
    SYM_INT_ACC,
    SYM_EOF_ACC
};

enum SymInput { // our different symbol inputs
    SYM_CLASS,
    SYM_CONST,
    SYM_VAR,
    SYM_PROC,
    SYM_IDENT,
    SYM_NUM_LIT,
    SYM_EOF,
    SYM_COMMA,
    SYM_SEMI,
    SYM_ASSIGN,
    SYM_LPAREN,
    SYM_LBRACE,
    SYM_ANY
};

// struct to store the symbol
struct Symbol { 
    string symbol;
    string classification;
    string value;
    int address;
    string segment;
};

// class to symbolize the tokens
class Symbolizer {
    public:
    Symbolizer(const vector<Token> &tokens); 
    vector<Symbol> symbolize(); // symbolizes the tokens

    private:
    vector<Token> tokens; // stores the tokens
    vector<Symbol> symbols; // stores the symbols
    string currentSymbol = "";

    // helper methods
    SymInput classifySym(const string &type); // classifies the symbol
    void addSymbol(const string &symbol, const string &classification, const string &value, int address, const string &segment); // adds a symbol to the symbol list
    SymState getNextSymState(SymState currentSymState, SymInput symClass); // gets the next symbol state
};
const int SYMBOL_STATES = 15;
const int SYMBOL_INPUTS = 13;

extern int symbolTransitionTable[SYMBOL_STATES][SYMBOL_INPUTS];

void initializeSymbolTransitionTable();
#endif // SYMBOL_TABLE_H

