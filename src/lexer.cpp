#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <string>
#include <fstream>

#include "lexer.hpp"

using std::vector;
using std::string;
using std::ifstream;

vector<Token*>* lexer(vector<char*> inputFilepaths){

    vector<Token*>* tokens = new vector<Token*>;

    for(char* filepath : inputFilepaths){

        ifstream openFile;
        openFile.open(filepath, ifstream::in);

        if(!openFile.is_open()){
            printf("[Fatal]: could not open '%s'.\n", filepath);
            exit(EXIT_FAILURE);
        }

        while(!openFile.eof()){

            string line;
            getline(openFile, line);

            

        }

        tokens->push_back(new Token(END_OF_FILE, nullptr));

        openFile.close();

    }

    return tokens;

}