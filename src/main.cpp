#define QUARTZ_VERSION 82025

#include <cstdio>
#include <cstdlib>

#include "process_args.hpp"
#include "lexer.hpp"

#include <vector>
using std::vector;

int main(int argc, char** argv){

    vector<char*> input_filepaths;

    process_args(argc, argv, &input_filepaths);

    printf("[Debug]: finished processing arguments.\n");

    if(input_filepaths.empty()){
        printf("[Fatal]: no input files\n");
        exit(EXIT_FAILURE);
    }

    for(char* c : input_filepaths){

        lexer(c);

    }

    printf("[Debug]: finished lexing files.\n");

    return 0;
}

