#include <cstdio>
#include <vector>
#include <string>

#include "parseFlags.hpp"

using std::vector;
using std::string;

void printHelp(string arg0);

int main(int argc, char** argv){

    if(argc == 1){
        printf("Usage: %s [options] files...\n", argv[0]);
        printf("Use '%s --help' to list basic options\n", argv[0]);
        return 0;
    }

    if(string(argv[1]).compare("--help") == 0){
        printHelp(string(argv[0]));
        exit(EXIT_SUCCESS);
    }

    vector<string> args;
    
    for(int i = 0; i < argc; i++){
        args.push_back(argv[i]);
    }

    int res = parseFlags(args);

    switch(res){
        case MISSING_OUTPUT_FILEPATH:
            printf("[Error] no filepath passed with '-o' flag\n");
            break;
    }

    if(files.size() == 0){
        printf("[Fatal Error] no file(s) passed in arguments\n");
        exit(EXIT_FAILURE);
    }

}

void printHelp(string arg0){

    printf("Usage: %s [options] files...\n", arg0.c_str());
    printf("\n");
    printf("Options:\n");
    printf("  --help            print this menu (will be ignored if not first argument)\n");
    printf("  -o <filepath>     place output in specified filepath\n");

}