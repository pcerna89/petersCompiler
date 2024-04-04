
// main.cpp by Peter Cerna
#include "StateTransitionTable.h"
#include "Lexer.h"
#include "FileReader.h"

using namespace std;

int main(){
    initializeStateTransitionTable();

    Lexer lexer("sampleJava0.txt");

    vector<Token> tokens = lexer.tokenize();

    cout << left << setw(30) << "Lexemes" << "Tokens" << endl;
    cout << "-----------------------------" << endl;

    for (const auto &token : tokens){
        cout << left << setw(30) <<  token.lexeme << token.type << endl;
    }

    return 0;
}

