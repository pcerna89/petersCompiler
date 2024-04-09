
// SymbolTable.cpp by Peter Cerna
#include "SymbolTable.h"

int symbolTransitionTable [SYMBOL_STATES][SYMBOL_INPUTS];

void initializeSymbolTransitionTable(){
    symbolTransitionTable[SYM_BEGIN][SYM_CLASS] = SYM_PRGM_DEC; 
    
    symbolTransitionTable[SYM_PRGM_DEC][SYM_IDENT] = SYM_PRGM_ACC; 

    symbolTransitionTable[SYM_PRGM_ACC][SYM_LBRACE] = SYM_START; 

    symbolTransitionTable[SYM_START][SYM_CLASS] = SYM_INTERIM; 
    symbolTransitionTable[SYM_START][SYM_CONST] = SYM_CONST_DEC;
    symbolTransitionTable[SYM_START][SYM_VAR] = SYM_VAR_DEC;
    symbolTransitionTable[SYM_START][SYM_PROC] = SYM_PROC_DEC;
    symbolTransitionTable[SYM_START][SYM_ANY] = SYM_INTERIM;
    symbolTransitionTable[SYM_START][SYM_IDENT] = SYM_INTERIM;
    symbolTransitionTable[SYM_START][SYM_NUM_LIT] = SYM_INTERIM;
    symbolTransitionTable[SYM_START][SYM_COMMA] = SYM_INTERIM;
    symbolTransitionTable[SYM_START][SYM_SEMI] = SYM_INTERIM;
    symbolTransitionTable[SYM_START][SYM_ASSIGN] = SYM_INTERIM;
    symbolTransitionTable[SYM_START][SYM_LPAREN] = SYM_INTERIM;
    symbolTransitionTable[SYM_START][SYM_LBRACE] = SYM_INTERIM;
    
    symbolTransitionTable[SYM_CONST_DEC][SYM_IDENT] = SYM_CONST_VAR;
    
    symbolTransitionTable[SYM_CONST_VAR][SYM_ASSIGN] = SYM_CONST_ASSIGN;

    symbolTransitionTable[SYM_CONST_ASSIGN][SYM_NUM_LIT] = SYM_CONST_ACC;

    symbolTransitionTable[SYM_CONST_ACC][SYM_COMMA] = SYM_CONST_DEC;
    symbolTransitionTable[SYM_CONST_ACC][SYM_SEMI] = SYM_START;

    symbolTransitionTable[SYM_VAR_DEC][SYM_IDENT] = SYM_VAR_ACC;

    symbolTransitionTable[SYM_VAR_ACC][SYM_COMMA] = SYM_VAR_DEC;
    symbolTransitionTable[SYM_VAR_ACC][SYM_SEMI] = SYM_START;

    symbolTransitionTable[SYM_PROC_DEC][SYM_IDENT] = SYM_PROC_ACC;

    symbolTransitionTable[SYM_PROC_ACC][SYM_LPAREN] = SYM_START;

    symbolTransitionTable[SYM_INTERIM][SYM_CONST] = SYM_CONST_DEC;
    symbolTransitionTable[SYM_INTERIM][SYM_VAR] = SYM_VAR_DEC;
    symbolTransitionTable[SYM_INTERIM][SYM_PROC] = SYM_PROC_DEC;
    symbolTransitionTable[SYM_INTERIM][SYM_NUM_LIT] = SYM_INT_ACC;
    symbolTransitionTable[SYM_INTERIM][SYM_EOF] = SYM_EOF_ACC;
    symbolTransitionTable[SYM_INTERIM][SYM_ANY] = SYM_INTERIM;
    symbolTransitionTable[SYM_INTERIM][SYM_CLASS] = SYM_INTERIM;
    symbolTransitionTable[SYM_INTERIM][SYM_IDENT] = SYM_INTERIM;
    symbolTransitionTable[SYM_INTERIM][SYM_COMMA] = SYM_INTERIM;
    symbolTransitionTable[SYM_INTERIM][SYM_SEMI] = SYM_INTERIM;
    symbolTransitionTable[SYM_INTERIM][SYM_ASSIGN] = SYM_INTERIM;
    symbolTransitionTable[SYM_INTERIM][SYM_LPAREN] = SYM_INTERIM;
    symbolTransitionTable[SYM_INTERIM][SYM_LBRACE] = SYM_INTERIM;

    symbolTransitionTable[SYM_INT_ACC][SYM_EOF] = SYM_EOF_ACC;
    symbolTransitionTable[SYM_INT_ACC][SYM_ANY] = SYM_INTERIM;
    symbolTransitionTable[SYM_INT_ACC][SYM_CLASS] = SYM_INTERIM;
    symbolTransitionTable[SYM_INT_ACC][SYM_IDENT] = SYM_INTERIM;
    symbolTransitionTable[SYM_INT_ACC][SYM_NUM_LIT] = SYM_INTERIM;
    symbolTransitionTable[SYM_INT_ACC][SYM_COMMA] = SYM_INTERIM;
    symbolTransitionTable[SYM_INT_ACC][SYM_SEMI] = SYM_INTERIM;
    symbolTransitionTable[SYM_INT_ACC][SYM_ASSIGN] = SYM_INTERIM;
    symbolTransitionTable[SYM_INT_ACC][SYM_LPAREN] = SYM_INTERIM;
    symbolTransitionTable[SYM_INT_ACC][SYM_LBRACE] = SYM_INTERIM;
}
Symbolizer::Symbolizer(const vector<Token> &tokens) : tokens(tokens) {}

SymState Symbolizer::getNextSymState(SymState currentSymState, SymInput symClass){
    return static_cast<SymState>(symbolTransitionTable[currentSymState][symClass]);
}

void Symbolizer::addSymbol(const string &symbol, const string &classification, const string &value, int address, const string &segment){
    Symbol newSymbol;
    newSymbol.symbol = symbol;
    newSymbol.classification = classification;
    newSymbol.value = value;
    newSymbol.address = address;
    newSymbol.segment = segment;
    symbols.push_back(newSymbol);
}

SymInput Symbolizer::classifySym(const string &type){
    if (type == "$CLASS") return SYM_CLASS;
    if (type == "$CONST") return SYM_CONST;
    if (type == "$VAR") return SYM_VAR;
    if (type == "$PROCEDURE") return SYM_PROC;
    if (type == "Identifier") return SYM_IDENT;
    if (type == "Numeric Literal") return SYM_NUM_LIT;
    if (type == "EOF") return SYM_EOF;
    if (type == "$Comma") return SYM_COMMA;
    if (type == "$Semi") return SYM_SEMI;
    if (type == "$Assign") return SYM_ASSIGN;
    if (type == "$LP") return SYM_LPAREN;
    if (type == "$LB") return SYM_LBRACE;
    else return SYM_ANY;
}

vector<Symbol> Symbolizer::symbolize(){
    SymState currentSymState = SYM_BEGIN;
    int codeAddress = 0;
    int dataAddress = 0;
    string symbol, classification, value, segment;

    for (const auto &token : tokens){
        SymInput symClass = classifySym(token.type); // classify the token
        SymState nextSymState = getNextSymState(currentSymState, symClass); // get the next state
    
        switch (nextSymState){
            case SYM_PRGM_DEC:
                break;
            case SYM_PRGM_ACC:
                symbol = token.lexeme;
                classification = "$PROGRAM NAME";
                addSymbol(symbol, classification, value, codeAddress, "CS");
                codeAddress += 2;
                break;
            case SYM_START:
                break;
            case SYM_CONST_DEC:
                break;
            case SYM_CONST_VAR:
                symbol = token.lexeme; 
                classification = "CONST VAR"; 
                break;
            case SYM_CONST_ASSIGN:
                break;
            case SYM_CONST_ACC:
                value = token.lexeme; 
                addSymbol(symbol, classification, value, dataAddress, "DS"); 
                dataAddress += 2; 
                break;
            case SYM_VAR_DEC:
                break;
            case SYM_VAR_ACC:
                symbol = token.lexeme;
                classification = "VAR";
                value = "?"; 
                addSymbol(symbol, classification, "?", dataAddress, "DS");
                dataAddress += 2;
                break;
            case SYM_PROC_DEC:
                break;
            case SYM_PROC_ACC:
                symbol = token.lexeme;
                classification = "PROCEDURE";
                segment = "CS";
                addSymbol(symbol, classification, "?", codeAddress, "CS");
                codeAddress += 2;
                break;
            case SYM_INTERIM:
                break;
            case SYM_INT_ACC:
                symbol = token.lexeme;
                classification = "NUMERIC LITERAL";
                value = token.lexeme;
                segment = "DS";
                addSymbol(symbol, classification, value, dataAddress, "DS");
                dataAddress += 2;
                break;
            case SYM_EOF_ACC:
                break;
            default:
            cout << "OH GOD! AN ERROR OCCURED!" << endl;
                break;     
        }
        currentSymState = nextSymState;
    }
    int temp1 = 0;
    symbol = "Temp1";
    classification = "VAR(int)";
    addSymbol(symbol, classification, value = "", dataAddress, "DS");
    dataAddress += 2;
    int temp2 = 0;
    symbol = "Temp2";
    classification = "VAR(int)";
    addSymbol(symbol, classification, value = "", dataAddress, "DS");
    dataAddress += 2;
    int temp3 = 0;
    symbol = "Temp3";
    classification = "VAR(int)";
    addSymbol(symbol, classification, value = "", dataAddress, "DS");
    dataAddress += 2;

    return symbols;
}
