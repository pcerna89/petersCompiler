
// main.cpp by Peter Cerna
#include "StateTransitionTable.h"
#include "Lexer.h"
#include "SymbolTable.h"
#include "FileReader.h"
#include "Parser.h"
using namespace std;

int main(){
    initializeStateTransitionTable();

    Lexer lexer("pgm8.txt"); // create a lexer object
    vector<Token> tokens = lexer.tokenize(); // tokenize the input file

    Parser parser(tokens); // create a parser with the tokens from lexer 
    parser.parse(); // start parsing the tokens

    ofstream tokenFile("TokenList.txt"); // create a file to store the tokens

    tokenFile << "Token List" << endl;
    tokenFile << left << setw(30) << "Lexemes:" << "Types:" << endl;
    tokenFile << "-----------------------------" << endl;

    for (const auto &token : tokens){ // write the tokens to the file
        tokenFile << left << setw(30) <<  token.lexeme << token.type << endl;
    }
    tokenFile.close();

    initializeSymbolTransitionTable();

    Symbolizer symbolizer(tokens); // create a symbolizer object
    vector<Symbol> symbols = symbolizer.symbolize(); // symbolize the tokens

    ofstream symbolFile("SymbolTable.txt"); // create a file to store the symbols
    symbolFile << endl << "Symbol Table" << endl;
    symbolFile << left << setw(30) << "Symbol:" << setw(20) << "Classification:" << setw(10) << "Value:" << setw(10) << "Address:" << "Segment:" << endl;

    for (const auto &symbol : symbols){
        symbolFile << left << setw(30) << symbol.symbol << setw(20) << symbol.classification << setw(10) << symbol.value << setw(10) << symbol.address << symbol.segment << endl;
    }
    symbolFile.close();
    
    return 0;
}