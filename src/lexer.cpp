#include <cctype>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;
using std::getline;

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

void trimLeadingSpaces(string* currentLine);
void trimComments(string* currentLine);

void lexer(char* filepath){

    ifstream openFile;
    openFile.open(filepath, ifstream::in);

    if(!openFile.is_open()){
        printf("[Error]: couldn't open the file '%s'.\n", filepath);
        return;
    }

    vector<Token>* token_list = new vector<Token>();

    string currentLine;
    unsigned int lineCount = 0;

    while(getline(openFile, currentLine)){

        lineCount += 1;

        trimLeadingSpaces(&currentLine);
        trimComments(&currentLine);

        if(currentLine.empty()){
            continue;
        }

        // TODO: start lexing for tokens

    }

    openFile.close();

}

void trimLeadingSpaces(string* currentLine){

    size_t trimmedStringStart = currentLine->find_first_not_of(" \t");
    if(trimmedStringStart != string::npos){
        *currentLine = currentLine->substr(trimmedStringStart);
    }

}

void trimComments(string* currentLine){
    
    size_t commentStart = currentLine->find("//");

    if(commentStart != string::npos){
        *currentLine = currentLine->substr(0, commentStart);
    }

}