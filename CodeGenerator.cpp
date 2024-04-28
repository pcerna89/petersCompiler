
// CodeGenerator.cpp created by Peter Cerna
#include "CodeGenerator.h"
#include <fstream>
#include <algorithm>


CodeGenerator::CodeGenerator(const stack<Quad> &quads, const vector<Symbol> &symbols) : quads(quads), symbols(symbols){
}

void CodeGenerator::generateCode(){
    generateDataSection();
    generateBSSSection();
    generateTextSection();

    ofstream outputFile("output.asm");
    if (outputFile.is_open()){
        outputFile << linuxConfiguration();

        // write the data section
        for (const auto &data : dataSection){
            outputFile << data << endl;
        }

        // write the bss section
        for (const auto &bss : bssSection){
            outputFile << bss << endl;
        }

        for (const auto &text : textSection){
            outputFile << text << endl;
        }
        outputFile << finiConfiguration();

        outputFile << printString() << endl;
        outputFile << getAnInteger() << endl;
        outputFile << convertIntegerToString() << endl;
        
        outputFile.close();
    }
    else {
        cout << "Error: Unable to open file" << endl;
    }
}
string CodeGenerator::linuxConfiguration(){
    return "sys_exit\tequ 1\n"
            "sys_read\tequ 3\n"
            "sys_write\tequ 4\n"
            "stdin\t\tequ 0\n"
            "stdout\t\tequ 1\n"
            "stderr\t\tequ 3\n"
            "\n";
}
string CodeGenerator::finiConfiguration(){
    return  "fini:\n"
            "\tmov\teax, sys_exit\n"
            "\txor\tebx, ebx\n"
            "\tint\t80h\n\n";
}
string CodeGenerator::printString(){
    return "PrintString:\n"
            "\tpush\tax\n"
            "\tpush\tdx\n"
            "\tmov\teax, 4\n"
            "\tmov\tebx, 1\n"
            "\n"
            "\tmov\tecx, userMsg\n"
            "\tmov\tedx, lenUserMsg\n"
            "\tint\t80h\n"
            "\tpop\tdx\n"
            "\tpop\tax\n"
            "\tret\n";
            "\n";
}
string CodeGenerator::getAnInteger(){
    return "GetAnInteger:\n"
            "\tmov\teax, 3\n"
            "\tmov\tebx, 2\n"
            "\tmov\tecx, num\n"
            "\tmov\tedx, 6\n"
            "\tint\t0x80\n"
            "\n"
            "\tmov\tedx, eax\n"
            "\tmov\teax, 4\n"
            "\tmov\tebx, 1\n"
            "\tmov\tecx, num\n"
            "\tint\t80h\n"
            "\n"
            "ConvertStringToInteger:\n"
            "\tmov\tax, 0\n"
            "\tmov\t[ReadInt],ax\n"
            "\tmov\tecx, num\n"
            "\tmov\tbx, 0\n"
            "\tmov\tbl, byte [ecx]\n"
            "Next:\n\tsub\tbl,'0'\n"
            "\tmov\tax, [ReadInt]\n"
            "\tmov\tdx, 10\n"
            "\tmul\tdx\n"
            "\tadd\tax, bx\n"
            "\tmov\t[ReadInt],ax\n"
            "\n"
            "\tmov bx, 0\n"
            "\tadd ecx, 1\n"
            "\tmov\tbl, byte [ecx]\n"
            "\n"
            "\tcmp\tbl,0xA\n"
            "\tjne\tNext\n"
            "\tret\n";
            "\n";
}
string CodeGenerator::convertIntegerToString(){
    return "ConvertIntegerToString:\n"
            "\tmov\tebx, ResultValue + 4\n"
            "ConvertLoop:\n"
            "\tsub\tdx, dx\n"
            "\tmov\tcx, 10\n"
            "\tdiv\tcx\n"
            "\tadd\tdl, '0'\n"
            "\tmov\t[ebx], dl\n"
            "\tdec\tebx\n"
            "\tcmp\tebx, ResultValue\n"
            "\tjge\tConvertLoop\n"
            "\tret\n";
            "\n";

}
void CodeGenerator::generateDataSection(){
    dataSection.push_back("section .data");
    dataSection.push_back("\tuserMsg\t\t\tdb\t'Enter an integer(less than 32,765): '");
    dataSection.push_back("\tlenUserMsg\t\tequ\t$-userMsg");
    dataSection.push_back("\tdisplayMsg\t\tdb\t'You entered: '");
    dataSection.push_back("\tlenDisplayMsg\tequ\t$-displayMsg");
    dataSection.push_back("\tnewline\t\t\tdb\t0xA");
    dataSection.push_back("\n");
    dataSection.push_back("\tTen\t\t\t\tDW\t10");
    dataSection.push_back("\n");
    dataSection.push_back("\tResult\t\t\tdb\t'Ans= '");
    dataSection.push_back("\tResultValue\t\tdb\t'aaaaa'");
    dataSection.push_back("\tdb\t0xA");
    dataSection.push_back("\tResultEnd\t\tequ\t$-Result");
    dataSection.push_back("\n");
    dataSection.push_back("\tnum\t\t\t\ttimes\t6\tdb'ABCDEF'");
    dataSection.push_back("\tnumEnd\t\t\tequ\t$-num");
    dataSection.push_back("\n");

    set<string> numericLiterals;

    // loop through the symbol table
    for (const auto &symbol : symbols){ 
        // check if the symbol is a constant variable or a numeric literal
        if (symbol.classification == "CONST VAR" || symbol.classification == "NUMERIC LITERAL"){
            if (numericLiterals.find(symbol.symbol) == numericLiterals.end()){
                string line;
                if (symbol.classification == "CONST VAR"){
                    line = "\t" + symbol.symbol + "\t\t\tDW\t" + symbol.value;
                }
                else if (symbol.classification == "NUMERIC LITERAL"){
                    line = "\t" + symbol.symbol + "\t\t\tDW\t" + symbol.value;
                    numericLiterals.insert(symbol.symbol); // mark the numeric literal as found
                }
                dataSection.push_back(line);
            }
        }
    }
}
void CodeGenerator::generateBSSSection(){
    bssSection.push_back("section .bss");
    bssSection.push_back("\tTempChar\tRESB\t1");
    bssSection.push_back("\ttestchar\tRESB\t1");
    bssSection.push_back("\tReadInt\t\tRESW\t1");
    bssSection.push_back("\ttempint\t\tRESW\t1");
    bssSection.push_back("\tnegflag\t\tRESB\t1");


    // loop through the symbol table
    for (const auto &symbol : symbols){
        // check if the symbol is a variable
        if (symbol.classification == "VAR" || symbol.classification.substr(0, 4) == "VAR("){
            if (find(bssSection.begin(), bssSection.end(), symbol.symbol) == bssSection.end()){
                string line = "\t" + symbol.symbol + "\t\tRESW\t1";
                bssSection.push_back(line);
            }
        }
    }
    bssSection.push_back("\n");
}
void CodeGenerator::generateTextSection(){
    textSection.push_back("global _start");
    textSection.push_back("section .text");
    textSection.push_back("_start: nop");
    
    printQuadStack();
    stack<Quad> tempQuads = quads;
    vector<Quad> quadVector;

    while(!tempQuads.empty()){
        quadVector.push_back(tempQuads.top());
        tempQuads.pop();
    }
 
    for (auto it = quadVector.rbegin(); it != quadVector.rend(); ++it){
        Quad quad = *it;
        cout << "Processing quad: " << quad.op << " " << quad.arg1 << " " << quad.arg2 << " " << quad.result << endl;
        textSection.push_back(generateQuadAssembly(quad));

    }
    

}
string CodeGenerator::generateQuadAssembly(const Quad &quad){
    stringstream assembly;
    // arithmetic quads
    if (quad.op == "+"){
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tadd ax, [" << quad.arg2 << "]\n";
        assembly << "\tmov [" << quad.result << "], ax\n";
    }
    else if (quad.op == "-"){
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tsub ax, [" << quad.arg2 << "]\n";
        assembly << "\tmov [" << quad.result << "], ax\n";
    }
    else if (quad.op == "*"){
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tmul word [" << quad.arg2 << "]\n";
        assembly << "\tmov [" << quad.result << "], ax\n";
    }
    else if (quad.op == "/"){
        assembly << "\tdx, 0\n";
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tmov bx, [" << quad.arg2 << "]\n";
        assembly <<"\tdiv bx\n";
        assembly << "\tmov [" << quad.result << "], ax\n";
    }
    // assigntment quad
    else if (quad.op == "="){
        assembly << "\tmov ax, [" << quad.arg2 << "]\n";
        assembly << "\tmov [" << quad.arg1 << "], ax\n"; 
    }
    // relational quads
    else if (quad.op == "=="){
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tcmp ax, [" << quad.arg2 << "] ";
    }
    else if (quad.op == "!="){
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tcmp ax, [" << quad.arg2 << "] ";
    }
    else if (quad.op == ">"){
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tcmp ax, [" << quad.arg2 << "] ";
    }
    else if (quad.op == "<"){
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tcmp ax, [" << quad.arg2 << "] ";
    }
    else if (quad.op == ">="){
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tcmp ax, [" << quad.arg2 << "]\n";

    }
    else if (quad.op == "<="){
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tcmp ax, [" << quad.arg2 << "] ";

    }
    // if quad
    else if (quad.op == "IF"){
    // dont do anything
    }
    // then quad
    else if (quad.op == "THEN"){
        assembly << "\tJ" + quad.arg2 << " " << quad.arg1 << "\n"; 
    }
    // else quad
    else if (quad.op == "ELSE"){
        assembly << "\tJMP " << quad.arg1 << "\n";
    }
    // while quad
    else if (quad.op == "WHILE"){
        assembly << quad.arg1 << ":\n";
    }
    // do quad
    else if (quad.op == "DO"){
        assembly << "\tJ" + quad.arg2 << " " << quad.arg1 << "\n";
    }
    // label quads
    else if (quad.op.substr(0, 1) == "L"){
        assembly << quad.op << ": ";
        assembly << "nop\n";
    }
    else if (quad.op.substr(0, 1) == "W"){
        assembly << "\tjmp " << quad.op << "\n";
    }
    // read quad
    else if (quad.op == "CIN"){
        assembly << "\tcall PrintString\n";
        assembly << "\tcall GetAnInteger\n";
        assembly << "\tmov ax, [ReadInt]\n";
        assembly << "\tmov [" << quad.arg1 << "], ax\n";
    }
    // write quad
    else if (quad.op == "COUT"){
        
        assembly << "\tmov ax, [" << quad.arg1 << "]\n";
        assembly << "\tcall ConvertIntegerToString\n";
        assembly << "\n";
        assembly << "\tmov eax, 4\n";
        assembly << "\tmov ebx, 1\n";
        assembly << "\tmov ecx, Result\n";
        assembly << "\tmov edx, ResultEnd\n";
        assembly << "\tint 80h\n\n";
    }


    return assembly.str();
}
void CodeGenerator::printQuadStack(){
    cout << "Quad Stack Contents:\n" << endl;
    stack<Quad> tempStack = quads; // copy the stack to preserve the original
    vector<Quad> tempVector; 

    while (!tempStack.empty()){ // transfer from the stack to the vector in reverse order
        tempVector.push_back(tempStack.top());
        tempStack.pop();
    }

    for (auto it = tempVector.rbegin(); it != tempVector.rend(); ++it){ // reverse iterator
        cout << it->op << " " << it->arg1 << " " << it->arg2 << " " << it->result << endl;
    }
    cout << "----------------------" << endl;
    cout << endl;
}


