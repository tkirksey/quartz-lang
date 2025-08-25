#include <cstdio>
#include <cctype>

#include <string>
using std::string;

#include <vector>
using std::vector;

enum Token_Type {

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

    TOK_KEY,

    TOK_DOT,
    TOK_NUMBER,
    TOK_STR_LITERAL
    
    // TOK_COMMENT // for future debug comment saving capability

};

typedef struct {

    Token_Type token_type;
    string* str_data;

} Token;

void lexer(char* filepath){

    FILE* openfile = fopen(filepath, "r");

    if(openfile == NULL){

        printf("[Error]: Failed to open '%s'.\n", filepath);
        return;

    }

    vector<Token>* token_list = new vector<Token>();

    string* currentLine;

    while((currentLine = getNextLine(openfile)) != NULL){

        // if current line is a new line, skip it
        if(currentLine->length() == 0){
            delete currentLine;
            continue;
        }

        
        // if current line is a comment, skip it
        // FUTURE: Add ability to keep comments on a debug compilation
        if(currentLine->substr(0, 2).compare("//") == 0){
            delete currentLine;
            continue;
        }

        // TODO: Start lexing line for tokens (8/24/25)

    }

}

/**
 * @brief Get the Next Line object
 * 
 * @param openFile the file to get the next line from
 * @return string* A heap allocated string of the next line
 */
string* getNextLine(FILE* openFile){ 

    char nextChar = fgetc(openFile);

    if(nextChar == EOF){
        return NULL;
    }

    string* currentLine = new string("");

    // trims leading whitespaces ('\t' && ' ')
    while(isblank(nextChar)){
        nextChar = fgetc(openFile);
    }        

    while(nextChar != EOF){

        if(nextChar == '\n'){
            break;
        }
        
        /*
            This code tries to catch the
            signature of a CRLF newline from
            DOS based systems that could've
            written the file.
        */
        if(nextChar != '\r'){
            currentLine += nextChar;
        }

        nextChar = fgetc(openFile);

    }

    return currentLine;

}