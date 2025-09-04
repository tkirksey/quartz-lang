#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <string>

using std::vector;

enum TokenType {

    INDENTIFIER,
    DATA_TYPE,
    NUMBER,
    STRING,
    COMMNET,
    OPERATOR,
    END_OF_FILE

};

class Token {

    public:
        TokenType tokenType;
        string* tokenValue;

        Token(TokenType tokenType, string* tokenValue){
            this->tokenType = tokenType;
            this->tokenValue = tokenValue;
        }

        ~Token(){
            delete tokenValue;
        }

};

vector<Token*>* lexer(vector<char*> inputFilepaths);

#endif