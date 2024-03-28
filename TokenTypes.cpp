// tokentypes.cpp
#include "TokenTypes.h"

using namespace std;

string tokenTypeToString(TokenType type){
    switch (type){
        case TokenType::KEY_CLASS:
            return "KEY_CLASS";
        case TokenType::KEY_CONST:
            return "KEY_CONST";
        case TokenType::KEY_VAR:
            return "KEY_VAR";
        case TokenType::KEY_PROCEDURE:
            return "KEY_PROCEDURE";
        case TokenType::KEY_IF:
            return "KEY_IF";
        case TokenType::KEY_THEN:  
            return "KEY_THEN";
        case TokenType::KEY_ELSE:
            return "KEY_ELSE";
        case TokenType::KEY_WHILE:
            return "KEY_WHILE";
        case TokenType::KEY_CALL:
            return "KEY_CALL";
        case TokenType::KEY_DO:
            return "KEY_DO";
        case TokenType::KEY_ODD:
            return "KEY_ODD";
        case TokenType::OP_ASSIGN:
            return "OP_ASSIGN";
        case TokenType::OP_PLUS:
            return "OP_PLUS";
        case TokenType::OP_MINUS:
            return "OP_MINUS";
        case TokenType::OP_MULT:
            return "OP_MULT";
        case TokenType::OP_DIV:
            return "OP_DIV";
        case TokenType::RELOP_EQUAL:
            return "RELOP_EQUAL";
        case TokenType::RELOP_NOTEQUAL:
            return "RELOP_NOTEQUAL";
        case TokenType::RELOP_LESSTHAN:
            return "RELOP_LESSTHAN";
        case TokenType::RELOP_LESSTHANEQUAL:
            return "RELOP_LESSTHANEQUAL";
        case TokenType::RELOP_GREATERTHAN:
            return "RELOP_GREATERTHAN";
        case TokenType::RELOP_GREATERTHANEQUAL:
            return "RELOP_GREATERTHANEQUAL";
        case TokenType::SYM_COMMA:
            return "SYM_COMMA";
        case TokenType::SYM_SEMI:
            return "SYM_SEMI";
        case TokenType::SYM_LPAREN:
            return "SYM_LPAREN";
        case TokenType::SYM_RPAREN:
            return "SYM_RPAREN";
        case TokenType::SYM_LBRACE:
            return "SYM_LBRACE";
        case TokenType::SYM_RBRACE:
            return "SYM_RBRACE";
        case TokenType::IDENT:
            return "IDENT";
        case TokenType::LIT_INTEGER:
            return "LIT_INTEGER";
        case TokenType::COMMENT:
            return "COMMENT";
        case TokenType::END_OF_FILE:
            return "END_OF_FILE";
        case TokenType::UNDEFINED:
            return "UNDEFINED";

        default:
            return "UNKNOWN_TOKEN_TYPE";

    
    }

}