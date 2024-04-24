// FileReader.h by Peter Cerna
#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <string>

using namespace std;

class FileReader { // handles file input
    public: 
    string content; // stores the content of the file
    FileReader(const string &filename); 
    const string &getContent() const {
        return content; 
    }
};

#endif // FILEREADER_H