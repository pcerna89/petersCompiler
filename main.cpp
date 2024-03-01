// Created by Peter Cerna
// main.cpp

#include "InputFile.hpp"
#include "Tokenizer.hpp"
#include <iostream>

int main(){
    string filename = "sampleJava0.java0"; // test file name
    Tokenizer tokenizer(filename);

    Token token = tokenizer.getNextToken();
    while (token.type != TokenType::END_OF_FILE){
        cout << token.toString() << endl; // print our token
        token = tokenizer.getNextToken(); // retrieve next token
    }

    return 0;
}