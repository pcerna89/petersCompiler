
// main.cpp by Peter Cerna
#include <iostream>
#include "Lexer.cpp"

using namespace std;

int main(){
    initializeStateTransitionTable();
    auto tokens = readAndClassifyTokens("sampleJava0.txt");
    return 0;
}

