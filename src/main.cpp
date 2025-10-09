#include <cstdio>
#include <vector>
#include <string>

#include "parseFlags.hpp"

using std::vector;
using std::string;

int main(int argc, char** argv){

    if(argc == 1){
        printf("Usage: %s [options] files...\n", argv[0]);
        printf("Use '%s --help' to list basic options\n", argv[0]);
        return 0;
    }

    vector<string> args;
    
    for(int i = 0; i < argc; i++){
        args.push_back(argv[i]);
    }

    int res = parseFlags(args);

    switch(res){
        case PRINT_HELP_EXIT:
            exit(EXIT_SUCCESS);
        case MISSING_OUTPUT_FILEPATH:
            printf("[Error] no filepath passed with '-o' flag\n");
            break;
    }

    if(files.size() == 0){
        printf("[Fatal Error] no file(s) passed in arguments");
        exit(EXIT_FAILURE);
    }

    

}