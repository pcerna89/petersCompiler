// FileReader.cpp
#include "FileReader.h"
#include <iostream>

using namespace std;

FileReader::FileReader(const string &filename){
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file " + filename);
    }
    char c;
    while (file.get(c)){
        content += c;
    }
    file.close();
}
