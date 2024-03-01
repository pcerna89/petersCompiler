// Created by Peter Cerna
// header file for input file class

#ifndef INPUTFILE_H // include guard
#define INPUTFILE_H

#include <fstream> // file stream
#include <string>  

using namespace std;

class InputFile {
    public:
        InputFile(const string& filename);
        ~InputFile();
        bool isOpen() const;
        char getNextChar();
        void close();

    private:
        ifstream fileStream;

};

#endif // INPUTFILE_H
