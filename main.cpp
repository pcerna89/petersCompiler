
// main.cpp by Peter Cerna
#include <iostream>
#include "StateTransitionTable.h"
#include "Lexer.h"

using namespace std;

int main(){
    initializeStateTransitionTable();
    auto tokens = readAndClassifyTokens("sampleJava0.txt");

    for (const auto &token : tokens){
        cout << "Token: " << token.type << ", Lexeme: '" << token.lexeme << "'" << endl;
    }

    return 0;
}

