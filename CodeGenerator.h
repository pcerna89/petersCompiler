
// CodeGenerator.h created by Peter Cerna
#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H


#include "Parser.h"
#include <vector>
#include <sstream>
#include <set>
#include <string>
#include "SymbolTable.h"

using namespace std;

class CodeGenerator{
    public:
    CodeGenerator(const stack<Quad> &quads, const vector<Symbol> &symbols); // constructor
    void generateCode(); // generates the code

    private:
    string linuxConfiguration(); // returns the linux 
    string finiConfiguration(); // returns the fini configuration
    void generateDataSection(); // generates the data section
    void generateBSSSection(); // generates the bss section
    void generateTextSection(); // generates the text section
    string generateQuadAssembly(const Quad& quads); // generates the quad assembly
    string printString();
    string getAnInteger();
    string convertIntegerToString();
    void printQuadStack(); // prints the quad stack

    stack<Quad> quads; // stack of quads
    vector<Symbol> symbols; // vector of symbols
    vector<string> dataSection; // vector of data section
    vector<string> bssSection; // vector of bss section
    vector<string> textSection; // vector of text section 
    set<string> numericLiterals;
};


#endif // CODE_GEN_H