// Created by Peter Cerna
// InputFile.cpp

using namespace std;

#include "InputFile.hpp"

InputFile::InputFile(const string& filename){ // implementation of our constructor
    fileStream.open(filename); // takes in our given filename and opens it
}

InputFile::~InputFile(){ // implementation of our destructor 
    if (fileStream.is_open()){
        fileStream.close();
    }
}

bool InputFile::isOpen() const{ // implementation of our isOpen 
    return fileStream.is_open();
}

char InputFile::getNextChar(){ // implementation of our getNextChar 
    char character;
    if (fileStream.get(character)){
        return character;
    }
    return EOF; // end of file
}

void InputFile::close(){
    if (fileStream.is_open()){ // if boolean value returned is true (open)
        fileStream.close(); // close the file

    }
}