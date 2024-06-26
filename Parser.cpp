// Parser.cpp created by Peter Cerna
#include "Parser.h"
using namespace std;

char ParserTransitionTable[PARSER_STATES][PARSER_STATES];

// our operator precedence table
void initializeParserTransitionTable(){
    ParserTransitionTable[PARSE_SEMI][PARSE_ASSIGN] = '<';
    ParserTransitionTable[PARSE_SEMI][PARSE_LEFTBRACE] = '<';

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
    ParserTransitionTable[PARSE_PLUS][PARSE_DO] = '>';

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
    ParserTransitionTable[PARSE_MINUS][PARSE_DO] = '>';

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
    ParserTransitionTable[PARSE_MUL][PARSE_DO] = '>';

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
    ParserTransitionTable[PARSE_DIV][PARSE_DO] = '>';

    ParserTransitionTable[PARSE_IF][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_IF][PARSE_THEN] = '=';
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
    ParserTransitionTable[PARSE_THEN][PARSE_WHILE] = '<';

    ParserTransitionTable[PARSE_ELSE][PARSE_ASSIGN] = '<';
    ParserTransitionTable[PARSE_ELSE][PARSE_IF] = '<';
    ParserTransitionTable[PARSE_ELSE][PARSE_LEFTBRACE] = '<';
    ParserTransitionTable[PARSE_ELSE][PARSE_WHILE] = '<';

    ParserTransitionTable[PARSE_WHILE][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_DO] = '=';
    ParserTransitionTable[PARSE_WHILE][PARSE_ODD] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_EQUALS] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_NOTEQUAL] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_GREATER] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_LESS] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_GREATEREQUAL] = '<';
    ParserTransitionTable[PARSE_WHILE][PARSE_LESSEQUAL] = '<';

    ParserTransitionTable[PARSE_DO][PARSE_ASSIGN] = '<';
    ParserTransitionTable[PARSE_DO][PARSE_IF] = '<';
    ParserTransitionTable[PARSE_DO][PARSE_WHILE] = '<';
    ParserTransitionTable[PARSE_DO][PARSE_LEFTBRACE] = '<';
    ParserTransitionTable[PARSE_DO][PARSE_CALL] = '<';

    ParserTransitionTable[PARSE_ODD][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_ODD][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_ODD][PARSE_DO] = '>';

    ParserTransitionTable[PARSE_EQUALS][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_EQUALS][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_EQUALS][PARSE_DO] = '>';

    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_NOTEQUAL][PARSE_DO] = '>';

    ParserTransitionTable[PARSE_GREATER][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_GREATER][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_GREATER][PARSE_DO] = '>';

    ParserTransitionTable[PARSE_LESS][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_LESS][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_LESS][PARSE_DO] = '>';

    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_GREATEREQUAL][PARSE_DO] = '>';

    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_PLUS] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_MINUS] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_LEFTPAREN] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_MUL] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_DIV] = '<';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_THEN] = '>';
    ParserTransitionTable[PARSE_LESSEQUAL][PARSE_DO] = '>';

}

Parser::Parser(const vector<Token> &tokens) : tokens(tokens){
}

void printStack(const stack<Token> &tokenStack){ 
    stack<Token> printStack = tokenStack; // copy the stack to preserve the original
    vector<Token> tempVector; //

    while (!printStack.empty()){
        tempVector.push_back(printStack.top());
        printStack.pop();
    }

    cout << "Stack Contents:\n\n" << endl;
    for (const Token &token : tempVector){
        cout << token.lexeme << endl;
    }
    cout << "----------------------" << endl;
    cout << endl;
}

void Parser::printQuadStack(){
    cout << "Quad Stack Contents:\n" << endl;
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

    for (currentIndex = 0; currentIndex < tokens.size(); ++currentIndex){
        Token currentToken = tokens[currentIndex];
        cout << "Incoming token: '" <<  currentToken.lexeme << "'." << endl;

        Token nextToken = peekNextToken();
        Token prevToken = peekPrevToken();

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
        if (currentToken.lexeme == "CIN"){
            generateReadQuad();
            skipTokenUntilDelimiter = true;
            cout << "Encountered 'CIN'. Skipping token." << endl;
            continue;
        }
        if (currentToken.lexeme == "COUT"){
            generateWriteQuad();
            skipTokenUntilDelimiter = true;
            cout << "Encountered 'CIN'. Skipping token." << endl;
            continue;
        }
        
        // if we're not skipping and we identify the nonop
        if (!skipTokenUntilDelimiter && identifyTokenToParserClass(currentToken) == NON_OP){ 
            if (currentToken.lexeme != ";" && currentToken.lexeme != ","){
                tokenStack.push(currentToken);
                cout << "Pushed non-operator onto the stack: '" << currentToken.lexeme << "'." << endl;
            }
            else {
                cout << "Enountered a ';' or ','. Skipping token." << endl;
            }
        }
        handleOperator(currentToken); // handle the operator
        handleSpecialCases(currentToken); // handle special cases
        if (currentToken.lexeme == "}" && tokenStack.top().lexeme == "THEN" && peekNextToken().lexeme != "ELSE"){
            popIfThen(currentToken);
        }
        if (currentToken.lexeme == "}" && tokenStack.top().lexeme == "ELSE"){
            popIfThenElse(currentToken);
        }
        if (currentToken.lexeme == "}" && tokenStack.top().lexeme == "DO"){
            popWhileDo(currentToken);
        }
        handleIfThenElse(currentToken);  
        handleWhileDo(currentToken);
        printStack(tokenStack);
    }
    printQuadStack();
}

void Parser::popIfThen(const Token &currentToken){
    cout << "Popped 'THEN' from the stack." << endl;
    tokenStack.pop(); // pop off the THEN
    if (tokenStack.top().lexeme == "IF"){
        tokenStack.pop(); // pop
        cout << "Popped 'IF' from the stack." << endl;
        generateIfThenQuad();
        printStack(tokenStack);
    }
}

void Parser::popIfThenElse(const Token &currentToken){
    cout << "Popped '"<< tokenStack.top().lexeme << "' from the stack." << endl;
    tokenStack.pop(); // pop off the ELSE

    if (tokenStack.top().lexeme == "THEN"){
        cout << "Popped 'THEN' from the stack." << endl;
        tokenStack.pop(); // pop off the THEN
        if (tokenStack.top().lexeme == "IF"){
        cout << "Popped 'IF' from the stack." << endl;
        tokenStack.pop(); // pop off the IF
        generateIfThenElseQuad();
        printStack(tokenStack);
        }
    }
}

void Parser::popWhileDo(const Token &currentToken){
    cout << "Popped 'DO' from the stack." << endl;
    tokenStack.pop(); // pop off the DO
    if (tokenStack.top().lexeme == "WHILE"){
        cout << "Popped 'WHILE' from the stack." << endl;
        tokenStack.pop(); // pop off the WHILE
        generateWhileDoQuad();
        printStack(tokenStack);
    }
}

void Parser::handleSpecialCases(const Token &currentToken){
    if (tokenStack.size() >= 2){
        // top token is temporarily removed to examine the next one
        Token topToken = tokenStack.top();
        tokenStack.pop();
        Token secondToken = tokenStack.top();
        // if we encounter the special case of {}
        if (topToken.lexeme == "}" && secondToken.lexeme == "{"){
            tokenStack.pop(); 
            cout << "Popped '}' and '{' from the stack." << endl;
            printStack(tokenStack);
        }
        // if we encounter the special case of ()
        else if (topToken.lexeme == ")"){
            cout << "Popped ')' from the stack." << endl;
            // if next token on the stack is a left paren then we pop it off the stack as well
            if (!tokenStack.empty() && tokenStack.top().lexeme == "("){
                tokenStack.pop();
                cout << "Popped '(' from the stack." << endl;
            }
            else {
                // we use a temp stack as to store the expression until we find the left paren
                stack<Token> tempStack;
                while (!tokenStack.empty() && tokenStack.top().lexeme != "("){
                    tempStack.push(tokenStack.top());
                    tokenStack.pop();
                }
                // if we find the left paren, we pop it off the stack
                if (!tokenStack.empty() && tokenStack.top().lexeme == "("){
                    tokenStack.pop();
                    cout << "Popped '(' from the stack." << endl;
                }
                // we push the expression back into the stack
                while (!tempStack.empty()){
                    tokenStack.push(tempStack.top());
                    tempStack.pop();
                }
            }
            mostRecentOperatorUsed = findLastLowerOperator();
        }
        else {
            tokenStack.push(topToken); // push back the token if it's not the special case
            //cout << "Pushed '" << topToken.lexeme << "' back onto the stack." << endl;
        
        }
    }
}

void Parser::handleOperator (const Token &incomingToken){
    // map before hand
    ParserClass tokenClassification = identifyTokenToParserClass(incomingToken);
    ParserClass mostRecentOpClassification = identifyTokenToParserClass(mostRecentOperatorUsed);

    if (tokenClassification != NON_OP){ // if the token is an operator
        char transition = '?';
        transition = ParserTransitionTable[mostRecentOpClassification][tokenClassification];
        cout << "Most recent operator used: '" << mostRecentOperatorUsed.lexeme << "'." << endl;
        cout << "Comparing '" << mostRecentOperatorUsed.lexeme << "' against incoming token '" << incomingToken.lexeme << "'." << endl;
        if (transition == '>'){
            cout << "Transition found as: '" << transition << "'. Reducing." << endl;
            reduce(incomingToken);
        }
        else if (transition == '<'){
            cout << "Transition found as: " << transition << ". Shifting into the stack." << endl;
            tokenStack.push(incomingToken);
            cout << "Pushing '" << incomingToken.lexeme << "' onto the stack." << endl;
            mostRecentOperatorUsed = incomingToken;
            //printStack(tokenStack);
        }
        else if (transition == '='){
            cout << "Transition found as: '" << transition << "'." << endl;
            tokenStack.push(incomingToken);
            cout << "Pushing '" << incomingToken.lexeme << "' onto the stack." << endl;
            mostRecentOperatorUsed = incomingToken;
            printStack(tokenStack);
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
                printStack(tokenStack); // debugging
            }
        }
    }
}

void Parser::handleIfThenElse(const Token &currentToken){
    if (currentToken.lexeme == "IF"){
        generateIfQuad();
    }
    else if (currentToken.lexeme == "THEN"){
        generateThenQuad();
    }
    else if (currentToken.lexeme == "ELSE")
    {
        generateElseQuad();
    }
}

void Parser::handleWhileDo(const Token &currentToken){
    if (currentToken.lexeme == "WHILE"){
        generateWhileQuad();
    }
    else if (currentToken.lexeme == "DO"){
        generateDoQuad();
    }
}

void Parser::reduce(const Token& triggerToken){

    bool needsFurtherReduction = !triggerToken.lexeme.empty();

    cout << "Token stack size: " << tokenStack.size() << "\n" << endl;
    // while the stack is greater than 3, we reduce
    while (tokenStack.size() > 3){

        Token rightOperand = tokenStack.top(); tokenStack.pop();
        Token operatorToken = tokenStack.top(); tokenStack.pop();
        Token leftOperand = tokenStack.top(); tokenStack.pop();

        // if the operator is an arithmetic operator
        if (operatorToken.lexeme == "+" || 
            operatorToken.lexeme == "-" || 
            operatorToken.lexeme == "*" ||
            operatorToken.lexeme == "/"){
            generateArithmeticQuad(operatorToken, leftOperand, rightOperand);
            printStack(tokenStack);
        }
        // if the operator is an assignment operator
        else if (operatorToken.lexeme == "="){
            generateAssignmentQuad(leftOperand, rightOperand);
            printStack(tokenStack);
        }
        // if the operator is a relational operator
        else if (operatorToken.lexeme == "==" ||
                 operatorToken.lexeme == "!=" ||
                 operatorToken.lexeme == ">" ||
                 operatorToken.lexeme == "<" ||
                 operatorToken.lexeme == ">=" ||
                 operatorToken.lexeme == "<="){
            generateRelationalQuad(operatorToken, leftOperand, rightOperand);
            printStack(tokenStack);
        }
        // find the next lower operator after a reduction is made
        Token lastLowerOp = findLastLowerOperator();
        if (!lastLowerOp.lexeme.empty()){
            mostRecentOperatorUsed = lastLowerOp;
        }
        // if we need to further reduce
        if (needsFurtherReduction){
            handleOperator(triggerToken); // recursively call handleOperator
            needsFurtherReduction = false; // reset the flag
            break;
        }

    }
}

void Parser::generateArithmeticQuad(const Token &operatorToken, const Token &leftOperand, const Token &rightOperand){
    string resultTempVariable = getTemp();
    Quad arithQuad = {operatorToken.lexeme, leftOperand.lexeme, rightOperand.lexeme, resultTempVariable};

    quadStack.push(arithQuad);
    cout << "Generated Arithmetic Quad: '" << arithQuad.op << 
            "' '" << arithQuad.arg1 << 
            "' '" << arithQuad.arg2 << 
            "' '" << arithQuad.result << 
            "'." << endl;

    Token resultToken = {"TempVariable", resultTempVariable};
    tokenStack.push(resultToken);
    cout << "Pushed result onto the stack: '" << resultToken.lexeme << "'\n" << endl;
}

void Parser::generateAssignmentQuad(const Token &leftOperand, const Token &rightOperand){
    Quad assQuad = {"=", leftOperand.lexeme, rightOperand.lexeme, "?"};

    quadStack.push(assQuad);
    cout << "Generated Assignment Quad: '" << assQuad.op << 
            "' '" << assQuad.arg1 << 
            "' '" << assQuad.arg2 << 
            "' '" << assQuad.result <<
            "'." <<  endl;
}

void Parser::generateRelationalQuad(const Token &operatorToken, const Token &leftOperand, const Token &rightOperand){
    Quad relQuad = {operatorToken.lexeme, leftOperand.lexeme, rightOperand.lexeme, "?"};
    quadStack.push(relQuad);
    cout << "Generated Relational Quad: '" << relQuad.op << 
            "' '" << relQuad.arg1 << 
            "' '" << relQuad.arg2 << 
            "' '" << relQuad.result << 
            "'." << endl;
    releaseTemp(relQuad.result);
}

void Parser::generateIfQuad(){
    Quad ifQuad = {"IF", "?", "?", "?"};
    quadStack.push(ifQuad);
    cout << "Generated IF Quad: '" << ifQuad.op << 
            "' '" << ifQuad.arg1 << 
            "' '" << ifQuad.arg2 << 
            "' '" << ifQuad.result << 
            "'." << endl;
}

void Parser::generateThenQuad(){
    string thenLabel = generateLabel(); // generate a label for our THEN
    fixUpStack.push(thenLabel); // push the label onto the fixup stack
    cout << "Generated and pushed label for THEN to fixup stack: '" << thenLabel << "'." << endl;
    string condition;

    if (!quadStack.empty()){
        Quad topQuad = quadStack.top();
        condition = topQuad.op;
    }

    string oppositeCondition = invertCondition(condition);

    Quad thenQuad = {"THEN", thenLabel, oppositeCondition, "?" };
    quadStack.push(thenQuad);
    cout << "Generated THEN Quad: '" << thenQuad.op << 
            "' '" << thenQuad.arg1 << 
            "' '" << thenQuad.arg2 << 
            "' '" << thenQuad.result << 
            "'." << endl;
    releaseTemp(thenQuad.result); 
}

void Parser::generateElseQuad(){
    string elseLabel = generateLabel(); // generate a label for our ELSE
    endStack.push(elseLabel); // push the label onto the end stack
    cout << "Generated and pushed label for ELSE to end stack: '" << elseLabel << "'." << endl;

    Quad elseQuad = {"ELSE", elseLabel, "?", "?"};
    quadStack.push(elseQuad);

    cout << "Generated ELSE Quad: '" << elseQuad.op << 
            "' '" << elseQuad.arg1 << 
            "' '" << elseQuad.arg2 << 
            "' '" << elseQuad.result << 
            "'." << endl;

    string thenLabel = fixUpStack.top(); // get the label from the fixup stack
    Quad labelQuad = {thenLabel, "?", "?", "?"};
    quadStack.push(labelQuad);
    cout << "Generated ELSE Quad: '" << elseQuad.op << 
            "' '" << elseQuad.arg1 << 
            "' '" << elseQuad.arg2 << 
            "' '" << elseQuad.result << 
            "'." << endl;

    fixUpStack.pop(); // pop the label off the fixup stack
    cout << "Popped label for THEN from fixup stack: '" << thenLabel << "'." << endl;
}

void Parser::generateWhileQuad(){
    string whileLabel = generateWhileLabel(); // generate a label for our WHILE
    whileStack.push(whileLabel); // push the label onto the while stack
    cout << "Generated and pushed label for WHILE to while stack: '" << whileLabel << "'." << endl;

    Quad whileQuad = {"WHILE", whileLabel, "?", "?"};
    quadStack.push(whileQuad);
    cout << "Generated WHILE Quad: '" << whileQuad.op << 
            "' '" << whileQuad.arg1 << 
            "' '" << whileQuad.arg2 << 
            "' '" << whileQuad.result << 
            "'." << endl;
}

void Parser::generateDoQuad(){
    string doLabel = generateLabel(); // generate a label for our DO
    fixUpStack.push(doLabel); // push the label onto the fixup stack
    cout << "Generated and pushed label for DO to fixup stack: '" << doLabel << "'." << endl;
    string condition;

    if (!quadStack.empty()){
        Quad topQuad = quadStack.top();
        condition = topQuad.op;
    }

    string oppositeCondition = invertCondition(condition);
    Quad doQuad = {"DO", doLabel, oppositeCondition, "?"};
    quadStack.push(doQuad);
    cout << "Generated DO Quad: '" << doQuad.op << 
            "' '" << doQuad.arg1 << 
            "' '" << doQuad.arg2 << 
            "' '" << doQuad.result << 
            "'." << endl;
    releaseTemp(doQuad.result); 
}

void Parser::generateIfThenQuad(){
    string thenLabel = fixUpStack.top(); // get the label from the fixup stack
    fixUpStack.pop(); // pop the label off the fixup stack
    cout << "Popped label for THEN from fixup stack: '" << thenLabel << "'." << endl;

    Quad ifThenQuad = {thenLabel, "?", "?", "?"};
    quadStack.push(ifThenQuad);
    cout << "Generated IF THEN Quad: '" << ifThenQuad.op << 
            "' '" << ifThenQuad.arg1 << 
            "' '" << ifThenQuad.arg2 << 
            "' '" << ifThenQuad.result << 
            "'." << endl;
}

void Parser::generateIfThenElseQuad(){
    string elseLabel = endStack.top(); // get the label from the end stack
    endStack.pop(); // pop the label off the end stack
    cout << "Popped label for ELSE from end stack: '" << elseLabel << "'." << endl;

    Quad ifThenElseQuad = {elseLabel, "?", "?", "?"};
    quadStack.push(ifThenElseQuad);
    cout << "Generated IF THEN ELSE Quad: '" << ifThenElseQuad.op << 
            "' '" << ifThenElseQuad.arg1 << 
            "' '" << ifThenElseQuad.arg2 << 
            "' '" << ifThenElseQuad.result << 
            "'." << endl;
}

void Parser::generateWhileDoQuad(){
    string whileLabel = whileStack.top(); // get the label from the while stack
    string doLabel = fixUpStack.top(); // get the label from the fixup stack

    Quad whileDoQuad = {whileLabel, "?", "?", "?"};
    quadStack.push(whileDoQuad);
    cout << "Generated WHILE DO Quad: '" << whileDoQuad.op << 
            "' '" << whileDoQuad.arg1 << 
            "' '" << whileDoQuad.arg2 << 
            "' '" << whileDoQuad.result << 
            "'." << endl;
    whileStack.pop(); // pop the label off the while stack
    cout << "Popped label for WHILE from while stack: '" << whileLabel << "'." << endl;

    Quad doQuad = {doLabel, "?", "?", "?"};
    quadStack.push(doQuad);
    cout << "Generated WHILE DO Quad: '" << doQuad.op << 
            "' '" << doQuad.arg1 << 
            "' '" << doQuad.arg2 << 
            "' '" << doQuad.result << 
            "'." << endl;
    fixUpStack.pop(); // pop the label off the fixup stack
    cout << "Popped label for DO from fixup stack: '" << doLabel << "'." << endl;
    
}

void Parser::generateReadQuad(){
    string arg1 = peekNextToken().lexeme;
    Quad readQuad = {"CIN", arg1, "?", "?"};
    quadStack.push(readQuad);
    cout << "Generated Read Quad: '" << readQuad.op << 
            "' '" << readQuad.arg1 << 
            "' '" << readQuad.arg2 << 
            "' '" << readQuad.result << 
            "'." << endl;
}

void Parser::generateWriteQuad(){
    string arg1 = peekNextToken().lexeme;
    Quad writeQuad = {"COUT", arg1, "?", "?"};
    quadStack.push(writeQuad);
    cout << "Generated Write Quad: '" << writeQuad.op << 
            "' '" << writeQuad.arg1 << 
            "' '" << writeQuad.arg2 << 
            "' '" << writeQuad.result << 
            "'." << endl;
}

Token Parser::peekNextToken(){
    if (currentIndex + 1 < tokens.size()){
        //cout << "Peeked at next token: '" << tokens[currentIndex + 1].lexeme << "'." << endl;
        return tokens[currentIndex + 1];
    }
    return Token();
}

Token Parser::peekPrevToken(){
    if (currentIndex > 0){
        //cout << "Peeked at prev token: '" << tokens[currentIndex - 1].lexeme << "'." << endl;
        return tokens[currentIndex - 1];
    }
    return Token();
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

string Parser::generateLabel(){
    static int labelCounter = 1; // static counter to keep track of the label
    return "L" + to_string(labelCounter++); // return the label
}

string Parser::generateWhileLabel(){
    static int whileLabelCounter = 1; // static counter to keep track of the label
    return "W" + to_string(whileLabelCounter++); // return the label
}

string Parser::invertCondition(const string &condition){ // invert the condition of our boolean expression
    if (condition == "==") return "NE";
    if (condition == "!=") return "E";
    if (condition == ">") return "LE";
    if (condition == "<") return "GE";
    if (condition == ">=") return "L";
    if (condition == "<=") return "G";
    return "";
}

string Parser::getTemp(){
    if (!availableTemps.empty()){
        int index = *availableTemps.begin();
        availableTemps.erase(index);
        return tempVariables[index];
    }
    else {
        string newTemp = "Temp" + to_string(tempVariables.size() + 1);
        tempVariables.push_back(newTemp);
        return newTemp;
    }

}

void Parser::releaseTemp(const string &temp){
    auto it = find(tempVariables.begin(), tempVariables.end(), temp);
    if (it != tempVariables.end()){
        int index = distance(tempVariables.begin(), it);
        availableTemps.insert(index);
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
    if (token.lexeme == "WHILE") return PARSE_WHILE;
    if (token.lexeme == "DO") return PARSE_DO;
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
    if (token.lexeme == "READ") return PARSE_WRITE;
    if (token.lexeme == "WRITE") return PARSE_READ;
    if (token.lexeme == ",") return PARSE_COMMA;
    else return NON_OP;
}