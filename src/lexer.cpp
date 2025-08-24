#include <cstdio>
#include <cctype>

#include <string>
using std::string;

enum Token {

    TOK_EOF,
    TOK_SEMIC,

    TOK_DATATYPE,
    TOK_IDENTIFIER,

    TOK_L_PARENTH,
    TOK_R_PARENTH,
    TOK_L_BRACKET,
    TOK_R_BRACKET,
    // TOK_L_SQ_BRACKET, // for array implementation
    // TOK_R_SQ_BRACKET,

    TOK_KEY_USING,
    TOK_KEY_IF,
    TOK_KEY_ELSE,
    TOK_KEY_WHILE,
    TOK_KEY_FOR,

    TOK_DOT,
    TOK_NUMBER,
    TOK_STR_LITERAL,
    // TOK_VARIABLE_INSERT, // for println("Hello $somevar, how are you doing?");

    TOK_COMMENT

};

void lexer(char* filepath){

    FILE* openfile = fopen(filepath, "r");

    if(openfile == NULL){

        printf("[Error]: Failed to open '%s'.\n", filepath);
        return;

    }

    

}