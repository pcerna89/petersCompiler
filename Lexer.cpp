
// Lexer.cpp by Peter Cerna
#include "Lexer.h"

using namespace std;

string lexerStateToString(LexerState state){
    switch (state){
        case START: return "START";
        case ERROR_ACCEPT: return "ERROR_ACCEPT";
        case INT_HOLD: return "INT_HOLD";
        case INT_ACCEPT: return "INT_ACCEPT";
        case VAR_HOLD: return "VAR_HOLD";
        case VAR_ACCEPT: return "VAR_ACCEPT";
        case OP_ACCEPT: return "OP_ACCEPT";
        case SLASH_HOLD: return "SLASH_HOLD";
        case DIVOP_ACCEPT: return "DIVOP_ACCEPT";
        case COMMENT_HOLD: return "COMMENT_HOLD";
        case COMMENT_END: return "COMMENT_END";
        case EQUALS_HOLD: return "EQUALS_HOLD";
        case ASSIGNMENT_ACCEPT: return "ASSIGNMENT_ACCEPT";
        case EQUALITY_ACCEPT: return "EQUALITY_ACCEPT";
        case LESSER_HOLD: return "LESSER_HOLD";
        case LESSER_ACCEPT: return "LESSER_ACCEPT";
        case LESS_OR_EQUAL_ACCEPT: return "LESS_OR_EQUAL_ACCEPT";
        case GREATER_HOLD: return "GREATER_HOLD";
        case GREATER_ACCEPT: return "GREATER_ACCEPT";
        case GREATER_OR_EQUAL_ACCEPT: return "GREATER_OR_EQUAL_ACCEPT";
        case PARENTHESES_ACCEPT: return "PARENTHESES_ACCEPT";
        case BRACES_ACCEPT: return "BRACES_ACCEPT";
        case SEMI_ACCEPT: return "SEMI_ACCEPT";
        case COMMA_ACCEPT: return "COMMA_ACCEPT";
        case NOT_HOLD: return "NOT_HOLD";
        case NOT_ACCEPT: return "NOT_ACCEPT";
        case NOT_EQUAL_ACCEPT: return "NOT_EQUAL_ACCEPT";

        default: return "UNKNOWN";
    }
}

ReservedWord reservedWordFromString(const string &lexeme){
    if (lexeme == "CLASS") return CLASS;
    if (lexeme == "CONST") return CONST;
    if (lexeme == "VAR") return VAR;
    if (lexeme == "CALL") return CALL;
    if (lexeme == "PROCEDURE") return PROCEDURE;
    if (lexeme == "IF") return IF;
    if (lexeme == "WHILE") return WHILE;
    if (lexeme == "THEN") return THEN;
    if (lexeme == "DO") return DO;
    if (lexeme == "ODD") return ODD;
    return static_cast<ReservedWord>(-1); // return invalid enum value
}

// function to classify and update the current state
// returns the new state based on the current state and input character
LexerState nextState(LexerState currentState, char inputCharacter){
    CharClass charClass = OTHER; // default class

    if (isspace(inputCharacter)){
        charClass = WHITESPACE;
    }
    else if (isdigit(inputCharacter)){
        charClass = DIGIT;
    }
    else if (isalpha(inputCharacter)){
        charClass = LETTER;
    }
    else if (inputCharacter == '*'){
        charClass = STAR;
    }
    else if (inputCharacter == '+'){
        charClass = PLUS;
    }
    else if (inputCharacter == '-'){
        charClass = MINUS;
    }
    else if (inputCharacter == '/'){
        charClass = SLASH;
    }
    else if (inputCharacter == '='){
        charClass = EQUALS;
    }
    else if (inputCharacter == '<'){
        charClass = LESS;
    }
    else if (inputCharacter == '>'){
        charClass = GREATER;
    }
    else if (inputCharacter == '('){
        charClass = LPAREN;
    }
    else if (inputCharacter == ')'){
        charClass = RPAREN;
    }
    else if (inputCharacter == '{'){
        charClass = LBRACE;
    }
    else if (inputCharacter == '}'){
        charClass = RBRACE;
    }
    else if (inputCharacter == ';'){
        charClass = SEMICOLON;
    }
    else if (inputCharacter == ','){
        charClass = COMMA;
    }
    else if (inputCharacter == '!'){
        charClass = NOT;
    }
    else if (inputCharacter == '\n'){
        charClass = NEWLINE;
    }
    return static_cast<LexerState>(stateTransitionTable[currentState][charClass]);
}

vector<Token> readAndClassifyTokens(const string &filename){
    vector<Token> tokens;
    ifstream file(filename);
    LexerState currentState = START, nextLexerState;
    string currentLexeme;
    char c;


    if (!file.is_open()){
        cerr << "Error opening file '" << filename << "'" << endl;
    }
    while (file.get(c)){
        // trash and kill myself NO LET ME DIE IN SHAME
        // to do: change file reading into string char by char
        // switch statements instead of these god awful if else statements
        // does get (c) read the whitespace and cause it to skip the next?
        nextLexerState = nextState(currentState, c); 

        if (nextLexerState == START){ // checking if we are at start
            if (!currentLexeme.empty()){
                string tokenType = lexerStateToString(currentState);
                tokens.push_back({tokenType, currentLexeme});
            }
            currentLexeme.clear();
        }
        else if (nextLexerState == ERROR_ACCEPT){
            cerr << "Error: Invalid token '" << currentLexeme << "'" << endl;
            currentState = START;
            currentLexeme.clear();
        }
        else if (nextLexerState == INT_HOLD){
            currentLexeme += c;
        }
        else if (nextLexerState == INT_ACCEPT){
            tokens.push_back({"NUMERIC LITERAL", (currentLexeme)});
            currentLexeme.clear();

        }
        else if (nextLexerState == VAR_HOLD){
            currentLexeme += c;
        }
        else if (nextLexerState == VAR_ACCEPT){
            ReservedWord reservedWord = reservedWordFromString(currentLexeme);
            if (reservedWord != static_cast<ReservedWord>(-1)){
                switch (reservedWord){
                    case CLASS:
                        tokens.push_back({"$CLASS", currentLexeme});
                        break;
                    case CONST:
                        tokens.push_back({"$CONST", currentLexeme});
                        break;
                    case VAR:
                        tokens.push_back({"$VAR", currentLexeme});
                        break;
                    case CALL:
                        tokens.push_back({"$CALL", currentLexeme});
                        break;
                    case PROCEDURE:
                        tokens.push_back({"$PROCEDURE", currentLexeme});
                        break;
                    case IF:
                        tokens.push_back({"$IF", currentLexeme});
                        break;
                    case WHILE:
                        tokens.push_back({"$WHILE", currentLexeme});
                        break;
                    case THEN:
                        tokens.push_back({"$THEN", currentLexeme});
                        break;
                    case DO:
                        tokens.push_back({"$DO", currentLexeme});
                        break;
                    case ODD:
                        tokens.push_back({"$ODD", currentLexeme});
                        break;
                    default:
                        break;
                }
            }
            else {
                tokens.push_back({"IDENTIFIER", currentLexeme});
            // need to do const vars
            }
            currentLexeme.clear();
        }
        else if (nextLexerState == OP_ACCEPT){
            if (currentLexeme == "+"){
                tokens.push_back({"$ADD", currentLexeme});
            }
            else if (currentLexeme == "-"){
                tokens.push_back({"$SUB", currentLexeme});
            }
            else if (currentLexeme == "*"){
                tokens.push_back({"$MUL", currentLexeme});
            }
            currentLexeme.clear();
        }
        else if (nextLexerState == SLASH_HOLD){
            currentLexeme += c;
        }
        else if (nextLexerState == DIVOP_ACCEPT){
            tokens.push_back({"$DIV", currentLexeme});
            currentLexeme.clear();
        }
        else if (nextLexerState == COMMENT_HOLD){
            // do nothing
        }
        else if (nextLexerState == COMMENT_END){
            currentLexeme.clear();
        }
        else if (nextLexerState == EQUALS_HOLD){
            currentLexeme += c;
        }
        else if (nextLexerState == ASSIGNMENT_ACCEPT){
            tokens.push_back({"$ASSIGNMENT", currentLexeme});
            currentLexeme.clear();
        }
        else if (nextLexerState == EQUALITY_ACCEPT){
            tokens.push_back({"$EQUALS", currentLexeme});
            currentLexeme.clear();
        }
        else if (nextLexerState == LESSER_HOLD){
            currentLexeme += c;
        }
        else if (nextLexerState == LESSER_ACCEPT){
            tokens.push_back({"$LESSER", currentLexeme});
            currentLexeme.clear();
        }
        else if (nextLexerState == LESS_OR_EQUAL_ACCEPT){
            tokens.push_back({"$LESS EQUALS", currentLexeme});
            currentLexeme.clear();
        }
        else if (nextLexerState == GREATER_HOLD){
            currentLexeme += c;   
        }
        else if (nextLexerState == GREATER_ACCEPT){
            tokens.push_back({"$GREATER", currentLexeme});
            currentLexeme.clear();
        }
        else if (nextLexerState == GREATER_OR_EQUAL_ACCEPT){
            tokens.push_back({"$GREATER EQUALS", currentLexeme});
            currentLexeme.clear();
        }
        else if (nextLexerState == PARENTHESES_ACCEPT){
            if (currentLexeme == "("){
                tokens.push_back({"$LP", currentLexeme});
            }
            else if (currentLexeme == ")"){
                tokens.push_back({"$RP", currentLexeme});
            }
            currentLexeme.clear();
        }
        else if (nextLexerState == BRACES_ACCEPT){
            if (currentLexeme == "{"){
                tokens.push_back({"$RB", currentLexeme});
            }
            else if (currentLexeme == "}"){
                tokens.push_back({"$LB", currentLexeme});
            }
            currentLexeme.clear();
        }
        else if (nextLexerState == SEMI_ACCEPT){
            tokens.push_back({"$SEMI", currentLexeme});
            currentLexeme.clear();
        }
        else if (nextLexerState == COMMA_ACCEPT){
            tokens.push_back({"$COMMA", currentLexeme});
            currentLexeme.clear();
        }
        else if (nextLexerState == NOT_HOLD){
            currentLexeme += c;
        }
        else if (nextLexerState == NOT_ACCEPT){
            tokens.push_back({"$NOT", currentLexeme});
            currentLexeme.clear();
        }
        else if (nextLexerState == NOT_EQUAL_ACCEPT){
            tokens.push_back({"$NOT EQUALS", currentLexeme});
            currentLexeme.clear();
        }
        else {
            // for non start states and non error states
            currentLexeme += c;
        }
        currentState = nextLexerState;
    }
    if (!currentLexeme.empty()){
        string tokenType = lexerStateToString(currentState);
        tokens.push_back({tokenType, currentLexeme});
    }

    file.close();
    return tokens;
}