#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "lexer.hpp"

using std::vector;

const char * OUTPUT_FILEPATH = "a.out";
vector<char*> INPUT_FILEPATHS;

void processArgs(int argc, char** argv);
void printHelp();
bool isQuartzFile(char* filepath);

int main(int argc, char** argv){

    processArgs(argc, argv);

    if(INPUT_FILEPATHS.size() == 0){
        printf("[Fatal]: no input filepaths provided.\n");
        exit(EXIT_FAILURE);
    }

    vector<Token>* tokens = lexer(INPUT_FILEPATHS);

    

    return 0;
}

void processArgs(int argc, char** argv){

    if(argc == 1){
        return;
    }

    for(int i = 1; i < argc; i++){

        char* currArg = argv[i];

        // output filepath flag
        if(!strcmp(currArg, "-o")){

            if((i + 1) < argc){
                OUTPUT_FILEPATH = argv[(i + 1)];
            } else {
                printf("[Error]: missing additional argument for '-o' flag.\n");
            }

            i += 1;

            continue;

        }

        if(!(strcmp(currArg, "-h") && strcmp(currArg, "--help"))){

            printHelp();
            exit(EXIT_SUCCESS);
        
        }

        if(isQuartzFile(currArg)){
        
            INPUT_FILEPATHS.push_back(currArg);
            continue;
        
        }

    }

}

void printHelp(){

    printf("Usage: qzc [options] file...\n");
    printf("Options:\n");
    printf("  -o <file>     The file to place the output in.\n");
    printf("  -h            Print this information.\n");
    printf("\n");

}

bool isQuartzFile(char* filepath){

    char* extension = strrchr(filepath, '.');

    if(extension == NULL){
        return false;
    }

    if(strcmp(extension, ".qz") != 0){
        return false;
    }

    return true;

}