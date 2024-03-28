// lexical scanner created by Peter Cerna, may god have mercy on me
// scanner.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include "TokenTypes.h"

using namespace std;

enum ScannerState {
    START,
    IN_IDENT, // building an identifier or keyword
    IN_NUMBER, // accumulating a numeric literal
    IN_ASSIGN, // recognizing an assignment operator
    IN_OP, // handling an operator
    IN_RELOP, // handling a relational operator
    IN_COMMENT, // in comment/comment block
    FINISHED, // ready to return a token
    ERROR
};


int main(){

    ScannerState currentState = START;
    string lexeme = "";
    vector<Token> tokens;
    size_t line = 1; // to keep track of line number for tokens

    string filePath = "sampleJava0.java0"; // change this to the file you want to read
    ifstream sourceFile(filePath);

    if (!sourceFile.is_open()){
        cerr << "Error: could not open file " << filePath << endl;
        return 1;
    }

    char readChar;
    while (sourceFile.get(readChar)){
        if (currentState == START){
            if (isalpha(readChar)){
                current
            }
        }
    }

    return 0;
}