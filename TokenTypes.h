// tokentypes.h
#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H

#include <string>
using namespace std;

enum class TokenType { // represents our different types of tokens
    // reserved words
    KEY_CLASS,
    KEY_CONST,
    KEY_VAR,
    KEY_PROCEDURE,
    KEY_IF,
    KEY_THEN,
    KEY_ELSE,
    KEY_WHILE,
    KEY_CALL,
    KEY_DO,
    KEY_ODD,

    // operators
    OP_ASSIGN,
    OP_PLUS,
    OP_MINUS,
    OP_MULT,
    OP_DIV,

    // relational operators
    RELOP_EQUAL,
    RELOP_NOTEQUAL,
    RELOP_LESSTHAN,
    RELOP_LESSTHANEQUAL,
    RELOP_GREATERTHAN,
    RELOP_GREATERTHANEQUAL,

    // symbols
    SYM_COMMA,
    SYM_SEMI,
    SYM_LPAREN,
    SYM_RPAREN,
    SYM_LBRACE,
    SYM_RBRACE,

    // identifiers
    IDENT,

    // literals
    LIT_INTEGER,

    // comments
    COMMENT,

    // special cases
    END_OF_FILE,
    UNDEFINED
};

struct Token {
    TokenType type;
    string lexeme;
    size_t line; // for error reporting

    Token(TokenType type, string lexeme, size_t line) : type(type), lexeme(move(lexeme)), line(line) {}
};


#endif // TOKEN_TYPES_H