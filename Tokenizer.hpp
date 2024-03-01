// Created by Peter Cerna
// Tokenizer.hpp

#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include "InputFile.hpp"
#include <vector>
#include <string>

using namespace std;

class Tokenizer {
    public:
        Tokenizer(const string& filename);
        Token getNextToken();

    private:
    InputFile inputFile;
    char lookahead; 
    void readNextChar();
};

#endif // TOKENIZER_HPP