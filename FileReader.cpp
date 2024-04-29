// FileReader.cpp by Peter Cerna
#include "FileReader.h"
#include <iostream>
using namespace std;

FileReader::FileReader(const string &filename){ 
    ifstream file(filename); // open the file
    if (!file.is_open()) {
        throw runtime_error("Unable to open file " + filename);
    }
    char c;
    while (file.get(c)){ // read the file character by character
        content += c; 
    }
    file.close();
}
