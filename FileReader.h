#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <string>

using namespace std;

class FileReader {
    public:
    string content;
    FileReader(const string &filename);
    const string &getContent() const {
        return content;
    }
};

#endif // FILEREADER_H