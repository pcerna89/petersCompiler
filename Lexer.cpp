
// Lexer.cpp by Peter Cerna
#include "FileReader.h"
#include "Lexer.h"
#include <cctype>

using namespace std;

// initializes the lexer with the filename
Lexer::Lexer(const string &filename) : fileReader(filename) {}

// function to get the next state based on the current state and character class
LexerState Lexer::getNextState(LexerState currentState, CharClass charClass){
    return static_cast<LexerState>(stateTransitionTable[currentState][charClass]); // using our state transition table
}

vector<string> ReservedWord{ // our reserved words
    "CLASS",
    "CONST",
    "VAR",
    "CALL",
    "PROCEDURE",
    "IF",
    "WHILE",
    "THEN",
    "DO",
    "ODD"
    "READ",
    "WRITE"
};

// function to convert lexer state to string to print for our tokens
string Lexer::lexerStateToString(LexerState state){
    switch (state){
        case INT_ACCEPT: return "Numeric Literal";
        case VAR_ACCEPT: {
            auto iterator = find(ReservedWord.begin(), ReservedWord.end(), currentLexeme);
            if (iterator != ReservedWord.end()){
                return "$" + *iterator;
            } 
            else {
                return "Identifier";
            }
        }
        case OP_ACCEPT: 
            if (currentLexeme == "+") return "$Add";
            else if (currentLexeme == "-") return "$Sub";
            else if (currentLexeme == "*") return "$Mul";
        case DIVOP_ACCEPT: return "$Div";
        case ASSIGNMENT_ACCEPT: return "$Assign";
        case EQUALITY_ACCEPT: return "$Equal";
        case LESSER_ACCEPT: return "$Less";
        case LESS_OR_EQUAL_ACCEPT: return "$LessEqual";
        case GREATER_ACCEPT: return "$Greater";
        case GREATER_OR_EQUAL_ACCEPT: return "$GreaterEqual";
        case PARENTHESES_ACCEPT: 
            if (currentLexeme == "(") return "$LP";
            else if (currentLexeme == ")") return "$RP";
        case BRACES_ACCEPT:
            if (currentLexeme == "{") return "$LB";
            else if (currentLexeme == "}") return "$RB";
        case SEMI_ACCEPT: return "$Semi";
        case COMMA_ACCEPT: return "$Comma";
        case NOT_ACCEPT: return "$Not";
        case NOT_EQUAL_ACCEPT: return "$NotEqual";
        default: return "UNKNOWN";
    }
}

// function to classify the character
CharClass Lexer::classifyChar(char c){
    if (isspace(c)) return WHITESPACE;
    if (isdigit(c)) return DIGIT;
    if (isalpha(c)) return LETTER;
    switch (c){
        case '*': return STAR;
        case '+': return PLUS;
        case '-': return MINUS;
        case '/': return SLASH;
        case '=': return EQUALS;
        case '<': return LESS;
        case '>': return GREATER;
        case '(': return LPAREN;
        case ')': return RPAREN;
        case '{': return LBRACE;
        case '}': return RBRACE;
        case ';': return SEMICOLON;
        case ',': return COMMA;
        case '!': return NOT;
        case '\n': return NEWLINE;
        default: return OTHER;
    }
}

// function to add a token to our tokens vector
void Lexer::addToken(const string &type, const string &lexeme){
    Token newToken = {type, lexeme};
    tokens.push_back(newToken);
}

// our core
vector<Token> Lexer::tokenize(){
    char nextChar;
    const string &code = fileReader.getContent();
    size_t positionInContent = 0;
    LexerState currentState = START;
   

    while (positionInContent < code.length()){ // read chars until eof
        char currentChar = code[positionInContent]; // get the current char
        CharClass charClass = classifyChar(currentChar); // classify char
        LexerState nextState = getNextState(currentState, charClass); // determine next state

        switch (nextState){ // handle the next state
            case START:
                // if we're at the start and the current lexeme is not empty,
                // add the token to the list and clear the lexeme
                currentLexeme.clear();
                currentState = nextState;
                positionInContent++; // always advance in our start state
                break;
            case ERROR_ACCEPT:
                currentLexeme.clear();
                currentState = START;
                positionInContent++;
                break;
            case INT_HOLD:
                currentLexeme += currentChar;
                currentState = nextState;
                positionInContent++;
                break;
            case INT_ACCEPT:
                addToken(lexerStateToString(INT_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                break;
            case VAR_HOLD:
                currentLexeme += currentChar;
                currentState = nextState;
                positionInContent++;
                break;
            case VAR_ACCEPT:
                addToken(lexerStateToString(VAR_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                break;
            case OP_ACCEPT:
                currentLexeme = currentChar;
                addToken(lexerStateToString(OP_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                positionInContent++;
                break;
            case SLASH_HOLD:
                currentLexeme += currentChar;
                currentState = nextState;
                positionInContent++;
                break;
            case DIVOP_ACCEPT:
                addToken(lexerStateToString(DIVOP_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                break;
            case COMMENT_HOLD:
                currentState = nextState;
                positionInContent++;
                break;
            case COMMENT_END:
                currentState = nextState;
                positionInContent++;
                break;
            case EQUALS_HOLD:
                currentLexeme += currentChar; 
                currentState = nextState;
                positionInContent++;
                break;
            case ASSIGNMENT_ACCEPT:
                addToken(lexerStateToString(ASSIGNMENT_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                break;
            case EQUALITY_ACCEPT:
                currentLexeme += currentChar;
                addToken(lexerStateToString(EQUALITY_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                positionInContent++;
                break;
            case LESSER_HOLD:
                currentLexeme += currentChar;
                currentState = nextState;
                positionInContent++;
                break;
            case LESSER_ACCEPT:
                addToken(lexerStateToString(LESSER_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                break;
            case LESS_OR_EQUAL_ACCEPT:
                currentLexeme += currentChar;
                addToken(lexerStateToString(LESS_OR_EQUAL_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                positionInContent++;
                break;
            case GREATER_HOLD:
                currentLexeme += currentChar;
                currentState = nextState;
                positionInContent++;
                break;
            case GREATER_ACCEPT:
                addToken(lexerStateToString(GREATER_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                break;
            case GREATER_OR_EQUAL_ACCEPT:
                currentLexeme += currentChar;
                addToken(lexerStateToString(GREATER_OR_EQUAL_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                positionInContent++;
                break;
            case PARENTHESES_ACCEPT:
                currentLexeme += currentChar;
                addToken(lexerStateToString(PARENTHESES_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                positionInContent++;
                break;
            case BRACES_ACCEPT:
                currentLexeme += currentChar;
                addToken(lexerStateToString(BRACES_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                positionInContent++;
                break;
            case SEMI_ACCEPT:
                currentLexeme += currentChar;
                addToken(lexerStateToString(SEMI_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                positionInContent++;
                break;
            case COMMA_ACCEPT:
                currentLexeme += currentChar;
                addToken(lexerStateToString(COMMA_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                positionInContent++;
                break;
            case NOT_HOLD:
                currentLexeme += currentChar;
                currentState = nextState;
                positionInContent++;
                break;
            case NOT_ACCEPT:
                addToken(lexerStateToString(NOT_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                break;
            case NOT_EQUAL_ACCEPT:
                currentLexeme += currentChar;
                addToken(lexerStateToString(NOT_EQUAL_ACCEPT), currentLexeme);
                currentLexeme.clear();
                currentState = START;
                positionInContent++;
                break;
            default:
            cout << "I messed up!" << endl;
                break;
        }
    }
    if (!currentLexeme.empty()){
        addToken(lexerStateToString(currentState), currentLexeme);
    }
    addToken("EOF", "EOF");

    return tokens;
}

