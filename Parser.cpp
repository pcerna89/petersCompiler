// Parser.cpp created by Peter Cerna
#include "Parser.h"

using namespace std;

char ParserTransitionTable[PARSER_STATES][PARSER_STATES];

// fill with a for loop
void initializeParserTransitionTable(){
    ParserTransitionTable[PARSE_SEMI][PARSE_ASSIGN] = '<';

    ParserTransitionTable[PARSE_ASSIGN][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_ASSIGN][PARSE_COMMA] = '>';

    ParserTransitionTable[PARSE_PLUS][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_PLUS] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_MINUS] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_PLUS][PARSE_RIGHTPAREN] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_PLUS][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_PLUS][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_EQUALS] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_NOTEQUAL] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_GREATER] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_LESS] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_GREATEREQUAL] = '>';
    ParserTransitionTable[PARSE_PLUS][PARSE_LESSEQUAL] = '>';

    ParserTransitionTable[PARSE_MINUS][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_PLUS] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_MINUS] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_MINUS][PARSE_RIGHTPAREN] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_MINUS][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_MINUS][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_EQUALS] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_NOTEQUAL] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_GREATER] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_LESS] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_GREATEREQUAL] = '>';
    ParserTransitionTable[PARSE_MINUS][PARSE_LESSEQUAL] = '>';

    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_RIGHTPAREN] = '=';
    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_LEFTPAREN][PARSE_DIV] = '<';

    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_PLUS] = '>';
    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_MINUS] = '>';
    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_RIGHTPAREN] = '>';
    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_MUL] = '>';
    ParserTransitionTable[PARSE_RIGHTPAREN][PARSE_DIV] = '>';

    ParserTransitionTable[PARSE_MUL][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_PLUS] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_MINUS] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_MUL][PARSE_RIGHTPAREN] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_MUL] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_DIV] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_EQUALS] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_NOTEQUAL] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_GREATER] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_LESS] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_GREATEREQUAL] = '>';
    ParserTransitionTable[PARSE_MUL][PARSE_LESSEQUAL] = '>';

    ParserTransitionTable[PARSE_DIV][PARSE_SEMI] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_PLUS] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_MINUS] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_DIV][PARSE_RIGHTPAREN] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_MUL] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_DIV] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_EQUALS] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_NOTEQUAL] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_GREATER] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_LESS] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_GREATEREQUAL] = '>';
    ParserTransitionTable[PARSE_DIV][PARSE_LESSEQUAL] = '>';

    ParserTransitionTable[PARSE_IF][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_LEFTBRACE] = '=';
    ParserTransitionTable[PARSE_IF][PARSE_ODD] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_EQUALS] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_NOTEQUAL] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_GREATER] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_LESS] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_GREATEREQUAL] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_LESSEQUAL] = '<';

    ParserTransitionTable[PARSE_THEN][PARSE_ASSIGN] = '<';
    ParserTransitionTable[PARSE_THEN][PARSE_IF] = '<';
    ParserTransitionTable[PARSE_THEN][PARSE_LEFTBRACE] = '<';
    ParserTransitionTable[PARSE_THEN][PARSE_CALL] = '<';

    ParserTransitionTable[PARSE_ODD][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_EQUALS][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_GREATER][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_LESS][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_THEN] = '>';

    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_THEN] = '>';

}

Parser::Parser(const vector<Token> &tokens) : tokens(tokens){
}

void printStack(const stack<Token> &tokenStack){
    stack<Token> printStack = tokenStack; // copy the stack to preserve the original
    vector<Token> tempVector; 

    while (!printStack.empty()){
        tempVector.push_back(printStack.top());
        printStack.pop();
    }

    cout << "Stack Contents:" << endl;
    for (auto it = tempVector.rbegin(); it != tempVector.rend(); ++it){
        cout << it->lexeme << endl;
    }
    cout << "----------------------" << endl;
    cout << endl;
}



void Parser::parse(){ // main parse loop
    initializeParserTransitionTable();

    bool skipTokenUntilOpeningBrace = true;
    bool skipTokenUntilDelimiter = false; // flag to determine if tokens should be skipped

    Token initialOpInStack{"$Semi", ";"};
    tokenStack.push(initialOpInStack);
    mostRecentOpInStack = initialOpInStack;
    cout << "\nPushed initial Schwartz onto the stack.\n" << endl;
    printStack(tokenStack);

    for (const auto &currentToken : tokens){
        cout << "Incoming token: '" <<  currentToken.lexeme << "'" << endl;

        if (skipTokenUntilOpeningBrace){
            if (currentToken.lexeme == "{"){
                //tokenStack.push(currentToken);
                //mostRecentOpInStack = currentToken;
                cout << "Encountered opening brace." << endl;
                //cout << "Pushed opening brace onto the stack." << endl;
                skipTokenUntilOpeningBrace = false;

            }
            else {
                continue;
            }
        }

        if (skipTokenUntilDelimiter){
            if (currentToken.lexeme != ";"){
                continue;
            }
            else {
                skipTokenUntilDelimiter = false; // reset on semi
                cout << "Encountered ';'. Resuming token processing. " << endl;
            }
        }

        if (currentToken.lexeme == "VAR" || currentToken.lexeme == "CONST" || currentToken.lexeme == "PROCEDURE"){
            skipTokenUntilDelimiter = true;
            cout << "Encountered keyword: " << currentToken.lexeme << ". Skipping tokens until ';'" << endl;
            continue;
        }

        if (!skipTokenUntilDelimiter && identifyTokenToParserClass(currentToken) == NON_OP){
            if (currentToken.lexeme != ";" && currentToken.lexeme != ","){
                tokenStack.push(currentToken);
                cout << "Pushed non-operator onto the stack: '" << currentToken.lexeme << "'" << endl;
            }
            else {
                cout << "Enountered a ';' or ','. Skipping token." << endl;
            }
        }
        else {
            handleOperator(currentToken);
        }
        printStack(tokenStack);
    }
}


void Parser::handleOperator (const Token &incomingToken){
    // map before hand
    ParserClass tokenClassification = identifyTokenToParserClass(incomingToken);
    ParserClass mostRecentOpClassification = identifyTokenToParserClass(mostRecentOpInStack);

    if (tokenClassification != NON_OP){ // if the token is an operator
        char transition = '?';
        transition = ParserTransitionTable[mostRecentOpClassification][tokenClassification];
        cout << "Most recent operator in the stack: " << mostRecentOpInStack.lexeme << endl;
        if (transition == '>'){
            cout << "Transition found as: " << transition << ". Reducing." << endl;
            // reduce();
        }
        else if (transition == '<'){
            cout << "Transition found as: " << transition << ". Shifting into the stack." << endl;
            tokenStack.push(incomingToken);
            cout << "Pushing '" << incomingToken.lexeme << "' onto the stack." << endl;
            mostRecentOpInStack = incomingToken;
        }
        else if (transition == '='){
            cout << "Transition found as: " << transition << ". Removing the last operator from the stack." << endl;
            tokenStack.push(incomingToken);
            cout << "Pushing '" << incomingToken.lexeme << "' onto the stack." << endl;
            mostRecentOpInStack = incomingToken;
        }
        else {
            cout << "Transition found as none." << endl;
            if (tokenClassification == PARSE_SEMI || tokenClassification == PARSE_COMMA){
                mostRecentOpInStack = incomingToken;
                cout << "Operator not being pushed onto the stack." << endl;
            }
            else {
                tokenStack.push(incomingToken);
                cout << "Pushing '" << incomingToken.lexeme << "' onto the stack." << endl;
                mostRecentOpInStack = incomingToken;
            }
        }
    }
}

void Parser::reduce(){
    cout << "Token stack size: " << tokenStack.size() << "\n" << endl;
    if (tokenStack.size() >= 3){
        stack<Token> tempStack;
        for (int i = 0; i < 3; i++){
            tempStack.push(tokenStack.top());
            tokenStack.pop();
        }
        Token rightOperand = tempStack.top();
        tempStack.pop();
        cout << "rightOperand: " << rightOperand.lexeme << endl;
        Token operatorToken = tempStack.top();
        cout << "operatorToken: " << operatorToken.lexeme << endl;
        tempStack.pop();
        Token leftOperand = tempStack.top();
        cout << "leftOperand: " << leftOperand.lexeme << endl;
        tempStack.pop();

        if (tempVariableUsedCounter <= 10){
            Token resultToken;
            resultToken.type = "TempVariable";
            resultToken.lexeme = "Temp" + to_string(tempVariableUsedCounter++);

            Quad quad;
            quad.op = operatorToken.lexeme;
            quad.arg1 = leftOperand.lexeme;
            quad.arg2 = rightOperand.lexeme;
            quad.result = resultToken.lexeme;

            quadStack.push(quad); // push the quad onto the onto the stack

            tokenStack.push(resultToken);
            cout << "Quad generated: " << quad.op << " " << quad.arg1 << " " << quad.arg2 << " " << quad.result << "\n" << endl;

            cout << "Before finding next lower operator: " << endl;
            printStack(tokenStack);

            Token nextLowerOp = findNextLowerOperator();
            cout << "Next lower operator: " << nextLowerOp.lexeme << "\n" << endl;

            cout << "After find next lower operator: " << endl;
            printStack(tokenStack);
        }
        else {
            cout << "Error: Out of temporary variables." << endl;
        }
    }
    else {
        cout << "Error: Not enough tokens to reduce." << endl;
    }
}

Token Parser::findNextLowerOperator(){
    stack<Token> tempStack;
    Token lowerOperator = {"", ""};

    // moving elements from the stack to a temporary stack until we find an operator
    while (!tokenStack.empty() && identifyTokenToParserClass(tokenStack.top()) == NON_OP){
        tempStack.push(tokenStack.top());
        tokenStack.pop();
    }
    // if we find an operator, we store it in lowerOperator
    if (!tokenStack.empty() && identifyTokenToParserClass(tokenStack.top()) != NON_OP){
        lowerOperator = tokenStack.top();
    }
    // moving elements back to the original stack
    while (!tempStack.empty()){
        tokenStack.push(tempStack.top());
        tempStack.pop();
    }

    return lowerOperator;
}

ParserClass Parser::identifyTokenToParserClass(const Token &token){
    if (token.lexeme == ";") return PARSE_SEMI;
    if (token.lexeme == "=") return PARSE_ASSIGN;
    if (token.lexeme == "+") return PARSE_PLUS;
    if (token.lexeme == "-") return PARSE_MINUS;
    if (token.lexeme == "(") return PARSE_LEFTPAREN;
    if (token.lexeme == ")") return PARSE_RIGHTPAREN;
    if (token.lexeme == "*") return PARSE_MUL;
    if (token.lexeme == "/") return PARSE_DIV;
    if (token.lexeme == "IF") return PARSE_IF;
    if (token.lexeme == "THEN") return PARSE_THEN;
    if (token.lexeme == "ODD") return PARSE_ODD;
    if (token.lexeme == "==") return PARSE_EQUALS;
    if (token.lexeme == "!=") return PARSE_NOTEQUAL;
    if (token.lexeme == ">") return PARSE_GREATER;
    if (token.lexeme == "<") return PARSE_LESS;
    if (token.lexeme == ">=") return PARSE_GREATEREQUAL;
    if (token.lexeme == "<=") return PARSE_LESSEQUAL;
    if (token.lexeme == "{") return PARSE_LEFTBRACE;
    if (token.lexeme == "}") return PARSE_RIGHTBRACE;
    if (token.lexeme == "CALL") return PARSE_CALL;
    if (token.lexeme == "PROCEDURE") return PARSE_PROC;
    if (token.lexeme == "ELSE") return PARSE_ELSE;
    if (token.lexeme == "GET") return PARSE_GET;
    if (token.lexeme == "PUT") return PARSE_PUT;
    if (token.lexeme == ",") return PARSE_COMMA;
    else return NON_OP;


}