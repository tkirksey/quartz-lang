#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <string>

using std::vector;
using std::string;

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
        size_t lineNumber;

        Token(TokenType tokenType, string* tokenValue, size_t lineNumber){
            this->tokenType = tokenType;
            this->tokenValue = tokenValue;
            this->lineNumber = lineNumber;
        }

        ~Token(){
            delete tokenValue;
        }

        string toString(){

            string ret;

            switch(this->tokenType){

                case INDENTIFIER:
                    ret += "[IDENTIFIER]: ";
                    break;
                // todo: finish this switch statement

            }

        }

};

vector<Token*>* lexer(vector<char*> inputFilepaths);

#endif