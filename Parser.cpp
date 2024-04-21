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

void printStack(const stack<Token> &tokenStack){ /// change later so it's in the header file
    stack<Token> printStack = tokenStack; // copy the stack to preserve the original
    vector<Token> tempVector; //

    while (!printStack.empty()){
        tempVector.push_back(printStack.top());
        printStack.pop();
    }

    cout << "Stack Contents:" << endl;
    for (auto it = tempVector.rbegin(); it != tempVector.rend(); ++it){ // reverse iterator
        cout << it->lexeme << endl; 
    }
    cout << "----------------------" << endl;
    cout << endl;
}

void Parser::printQuadStack(){
    cout << "Quad Stack Contents:" << endl;
    stack<Quad> tempStack = quadStack; // copy the stack to preserve the original
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


void Parser::parse(){ // main parse loop
    initializeParserTransitionTable();

    bool skipTokenUntilOpeningBrace = true;
    bool skipTokenUntilDelimiter = false; // flag to determine if tokens should be skipped

    Token initialOpInStack{"$Semi", ";"};
    tokenStack.push(initialOpInStack);
    mostRecentOperatorUsed = initialOpInStack;
    cout << "\nPushed initial Schwartz onto the stack.\n" << endl;
    printStack(tokenStack);

    for (const auto &currentToken : tokens){
        cout << "Incoming token: '" <<  currentToken.lexeme << "'" << endl;

        if (skipTokenUntilOpeningBrace){
            if (currentToken.lexeme == "{"){
                cout << "Encountered opening brace." << endl;
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
            handleSpecialCases();
        }
        printStack(tokenStack);
    }
    printQuadStack();
}


void Parser::handleOperator (const Token &incomingToken){
    // map before hand
    ParserClass tokenClassification = identifyTokenToParserClass(incomingToken);
    ParserClass mostRecentOpClassification = identifyTokenToParserClass(mostRecentOperatorUsed);

    if (tokenClassification != NON_OP){ // if the token is an operator
        char transition = '?';
        transition = ParserTransitionTable[mostRecentOpClassification][tokenClassification];
        cout << "Most recent operator used: " << mostRecentOperatorUsed.lexeme << endl;
        cout << "Comparing against incoming token: " << incomingToken.lexeme << endl;
        if (transition == '>'){
            cout << "Transition found as: " << transition << ". Reducing." << endl;
            reduce(incomingToken);
        }
        else if (transition == '<'){
            cout << "Transition found as: " << transition << ". Shifting into the stack." << endl;
            tokenStack.push(incomingToken);
            cout << "Pushing '" << incomingToken.lexeme << "' onto the stack." << endl;
            mostRecentOperatorUsed = incomingToken;
        }
        else if (transition == '='){
            cout << "Transition found as: " << transition << ". Removing the last operator from the stack." << endl;
            tokenStack.push(incomingToken);
            cout << "Pushing '" << incomingToken.lexeme << "' onto the stack." << endl;
            mostRecentOperatorUsed = incomingToken;
        }
        else {
            cout << "No transition found." << endl;
            if (tokenClassification == PARSE_SEMI || tokenClassification == PARSE_COMMA){
                //mostRecentOperatorUsed = incomingToken;
                cout << "Operator not being pushed onto the stack." << endl;
            }
            else {
                tokenStack.push(incomingToken);
                cout << "Pushing '" << incomingToken.lexeme << "' onto the stack." << endl;
                mostRecentOperatorUsed = incomingToken;
            }
        }
    }
}

Token Parser::findLastLowerOperator(){
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

void Parser::reduce(const Token& triggerToken){

    bool needsFurtherReduction = !triggerToken.lexeme.empty();

    cout << "Token stack size: " << tokenStack.size() << "\n" << endl;
    while (tokenStack.size() > 3){

        Token rightOperand = tokenStack.top();
        tokenStack.pop();

        Token operatorToken = tokenStack.top();
        tokenStack.pop();

        Token leftOperand = tokenStack.top();
        tokenStack.pop();

        if (operatorToken.lexeme == "+" || 
            operatorToken.lexeme == "-" || 
            operatorToken.lexeme == "*" ||
            operatorToken.lexeme == "/"){
            generateArithmeticQuad(operatorToken, leftOperand, rightOperand);
            printStack(tokenStack);
        }

        else if (operatorToken.lexeme == "="){
            generateAssignmentQuad(leftOperand, rightOperand);
            printStack(tokenStack);
        }

        else if (operatorToken.lexeme == "==" ||
                 operatorToken.lexeme == "!=" ||
                 operatorToken.lexeme == ">" ||
                 operatorToken.lexeme == "<" ||
                 operatorToken.lexeme == ">=" ||
                 operatorToken.lexeme == "<="){
            generateRelationalQuad(operatorToken, leftOperand, rightOperand);
            printStack(tokenStack);
        }

        else {
            cout << "Error: Operator not recognized." << endl;
            break;
        }

        Token lastLowerOp = findLastLowerOperator();

        if (!lastLowerOp.lexeme.empty()){
            mostRecentOperatorUsed = lastLowerOp;
        }
/*
        else {
            mostRecentOperatorUsed = {"$Semi", ";"};
        }
*/
        if (needsFurtherReduction){
            handleOperator(triggerToken); // recursively call handleOperator
            needsFurtherReduction = false; // reset the flag
        }

        if (tokenStack.size() < 3) break; // break if we have less than 3 elements in the stack
    }
}

void Parser::generateArithmeticQuad(const Token &operatorToken, const Token &leftOperand, const Token &rightOperand){
    if (tempVariableUsedCounter <= 10){
        string resultTempVariable = "Temp" + to_string(tempVariableUsedCounter++);
        Quad arithQuad = {operatorToken.lexeme, leftOperand.lexeme, rightOperand.lexeme, resultTempVariable};

        quadStack.push(arithQuad);
        cout << "Generated Quad: '" << arithQuad.op << 
                "' '" << arithQuad.arg1 << 
                "' '" << arithQuad.arg2 << 
                "' '" << arithQuad.result << 
                "'" << endl;

        Token resultToken = {"TempVariable", resultTempVariable};
        tokenStack.push(resultToken);
        cout << "Pushed result onto the stack: '" << resultToken.lexeme << "'\n" << endl;
    }
    else {
        cout << "Error: Out of temporary variables." << endl;
    }
}

void Parser::generateAssignmentQuad(const Token &leftOperand, const Token &rightOperand){
    if (tempVariableUsedCounter <= 10){
        string resultTempVariable = "Temp" + to_string(tempVariableUsedCounter++);
        Quad assQuad = {"=", leftOperand.lexeme, resultTempVariable, "?"};

        quadStack.push(assQuad);
        cout << "Generated Quad: '" << assQuad.op << 
                "' '" << assQuad.arg1 << 
                "' '" << assQuad.arg2 << 
                "' '" << assQuad.result <<
                "'" <<  endl;
    }
    else {
        cout << "Error: Out of temporary variables." << endl;
    }
}

void Parser::generateRelationalQuad(const Token &operatorToken, const Token &leftOperand, const Token &rightOperand){
    Quad quad = {operatorToken.lexeme, leftOperand.lexeme, rightOperand.lexeme, ""};
    quadStack.push(quad);
    cout << "Generated Quad: '" << quad.op << "' '" << quad.arg1 << "' '" << quad.arg2 << "' '" << quad.result << "'" << endl;
}

void Parser::handleSpecialCases(){
    if (tokenStack.size() >= 2){
        Token topToken = tokenStack.top();
        tokenStack.pop();
        Token secondToken = tokenStack.top();

        if (topToken.lexeme == "}" && secondToken.lexeme == "{"){
            tokenStack.pop(); // pop off both tokens for the special case {}
            cout << "Popped '}' and '{' from the stack." << endl;
        }
        else {
            tokenStack.push(topToken); // push back the token if it's not the special case
        
        }
    }
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