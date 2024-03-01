// Created by Peter Cerna
// Tokenizer.cpp

#include "Tokenizer.hpp"

Tokenizer::Tokenizer(const string& filename) : // make our initializer list
inputFile(filename), // initialize inputFile with filename
lookahead('\0'){ // initialize lookahead with null char
    readNextChar(); // load the first character into lookahead
}

Token Tokenizer::getNextToken(){
    // token logic here
    return Token();
}

void Tokenizer::readNextChar(){
    lookahead = inputFile.getNextChar(); // reads the next character and stores it in lookahead
}