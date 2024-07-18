# petersCompiler
# Language Translator Project
## Overview

This project is a language translator that meets the requirements for the "B" grading option in the COSC 4316 Lab for Spring 2024. The translator successfully implements lexical analysis, syntax analysis, and code generation for a subset of the Java programming language. [TranslatorLabSp2024GradeOptions.pdf](https://github.com/user-attachments/files/16288059/TranslatorLabSp2024GradeOptions.pdf)

## Features
File Reading ("FileReading.h and FileReading.cpp"): Reads in sample Java0 programs.

Lexical Analysis ("Lexer.h and Lexer.cpp"): The lexer reads token by token and creates the resulting token list for later use in symbol table construction and by the parser.

State Transition Table ("StateTransitionTable.h and StateTransitionTable.cpp"): The state transition table utilizes finite state automata to navigate each type of token encountered.

Symbol Table ("SymbolTable.h and SymbolTable.cpp"): Generates and maintains a symbol table for identifiers, constants, and other language constructs.

Parser ("Parser.h and Parser.cpp"): Parses through the token list and creates the resulting quads to be used for assembly code generation.

Code Generator ("CodeGenerator.h and "CodeGenerator.cpp"): Generates x86 assembly that corresponds to the quads generated from the parser.

.txt Files: Test programs created using the Java0 language to test throughout the project.

## Grading Criteria
“C” Option:
You must implement all of the following: CONST, VAR, compound statements [{
and }], integer I/O, generate a source listing, and a code listing. In addition, your
translator must process all arithmetic assignment statements. Implement either
the “IF” or “WHILE” statement. You have to implement the “>” and “>=” relational
operators though you are encouraged to implement all relational operators.
Nesting is not required. Your code must assemble and execute to be
acceptable. Assume all programs will be correct. Hence error messages are
not required. Write several sample programs to demonstrate the features of your
translator. Source code and executables for these programs as well as the
translator must be supplied in machine readable format. Supply a printed copy of
all program results with the source code. For all grading options: You have
not completed the grading option successfully unless all your programs
compile, assemble, and execute with appropriate I/O!

“B” Option:
Complete the “C” option but implement both the “IF” and “WHILE” statements.
One must allow for reasonable nesting (at least 5 deep). Some error messages
are expected. Write several sample programs to demonstrate the features of
your translator.


