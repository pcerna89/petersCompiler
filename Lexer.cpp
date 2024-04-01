
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

string trim(const string &str){
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first){
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

vector<Token> readAndClassifyTokens(const string &filename){
    vector<Token> tokens;
    ifstream file(filename);
    LexerState currentState = START, nextLexerState;
    string currentLexeme;
    char c;


    if (!file.is_open()){
        cerr << "Error opening file '" << filename << "'" << endl;
        return tokens; // return empty vector in case of failure

    }
    while (file.get(c)){
        nextLexerState = nextState(currentState, c);

        if (nextLexerState == START){ // checking if we are at start
            if (!currentLexeme.empty()){
                currentLexeme = trim(currentLexeme);
                if (!currentLexeme.empty()){
                    string tokenType = lexerStateToString(currentState);
                    tokens.push_back({tokenType, currentLexeme});
                }
                currentLexeme.clear();
            }
        }
        else if (nextLexerState == ERROR_ACCEPT){
            cerr << "Error: Invalid token '" << currentLexeme << "'" << endl;
            currentState = START;
            currentLexeme.clear();
        }
        else if (nextLexerState == INT_HOLD){

        }
        else if (nextLexerState == INT_ACCEPT){

        }
        else if (nextLexerState == VAR_HOLD){
            
        }
        else if (nextLexerState == VAR_ACCEPT){
            
        }
        else if (nextLexerState == OP_ACCEPT){
            
        }
        else if (nextLexerState == SLASH_HOLD){
            
        }
        else if (nextLexerState == DIVOP_ACCEPT){
            
        }
        else if (nextLexerState == COMMENT_HOLD){
            
        }
        else if (nextLexerState == COMMENT_END){
            
        }
        else if (nextLexerState == EQUALS_HOLD){
            
        }
        else if (nextLexerState == ASSIGNMENT_ACCEPT){
            
        }
        else if (nextLexerState == EQUALITY_ACCEPT){
            
        }
        else if (nextLexerState == LESSER_HOLD){
            
        }
        else if (nextLexerState == LESSER_ACCEPT){
            
        }
        else if (nextLexerState == LESS_OR_EQUAL_ACCEPT){
            
        }
        else if (nextLexerState == GREATER_HOLD){
            
        }
        else if (nextLexerState == GREATER_ACCEPT){
            
        }
        else if (nextLexerState == GREATER_OR_EQUAL_ACCEPT){
            
        }
        else if (nextLexerState == PARENTHESES_ACCEPT){
            
        }
        else if (nextLexerState == BRACES_ACCEPT){
            
        }
        else if (nextLexerState == SEMI_ACCEPT){
            
        }
        else if (nextLexerState == COMMA_ACCEPT){
            
        }
        else if (nextLexerState == NOT_HOLD){
            
        }
        else if (nextLexerState == NOT_ACCEPT){
            
        }
        else if (nextLexerState == NOT_EQUAL_ACCEPT){
            
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