#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

#include "lexer.hpp"

using std::vector;
using std::string;

size_t getFileSize(char * filepath);


vector<Token*>* lexer(vector<char*> inputFilepaths){

    vector<Token*>* tokens = new vector<Token*>;

    for(char* filepath : inputFilepaths){

        const size_t fileSize = getFileSize(filepath);

        char file[fileSize + 1];
        bzero(&file, fileSize);

        FILE* openFile = fopen(filepath, "r");

        if(!openFile){
            printf("[Fatal]: failed to open '%s'", filepath);
            exit(EXIT_FAILURE);
        }

        {
            size_t result = fread(&file, 1, fileSize, openFile);
        
            if(result != fileSize){
                printf("[Fatal]: error reading '%s'", filepath);
                exit(EXIT_FAILURE);
            }

            file[result] = '\0';
        }

        // the entire file is now a cstring

        char* filePtr = &file[0];

        size_t lineNumber = 1;

        while(*filePtr != '\0'){

            if(*filePtr == '\n'){
                lineNumber += 1;
                filePtr++;
            }

            // trim whitespace
            while(*filePtr == ' ' || *filePtr == '\t'){
                filePtr++;
            }

            // if single line comment is found.
            if(strstr(filePtr, "//") == filePtr){

                char* firstNL = filePtr;
                
                while(*firstNL != '\n'){
                    firstNL++;
                }

                size_t commentLength = firstNL - filePtr;

                string* str = new string(filePtr, commentLength);
                
                tokens->push_back(new Token(COMMNET, str, lineNumber));

                filePtr = ++firstNL;
                lineNumber += 1;

            }

            // block comment logic


        }

        tokens->push_back(new Token(END_OF_FILE, nullptr, lineNumber));

        fclose(openFile);

    }

    return tokens;

}

size_t getFileSize(char * filepath){

    FILE* openFile = fopen(filepath, "rb");

    if(!openFile){
        printf("[Fatal]: failed to open '%s'", filepath);
        exit(EXIT_FAILURE);
    }

    if(fseek(openFile, 0L, SEEK_END) != 0){
        printf("[Fatal]: failed to seek '%s'", filepath);
        exit(EXIT_FAILURE);
    }

    size_t fileSize = ftell(openFile);

    fclose(openFile);

    return fileSize;

}