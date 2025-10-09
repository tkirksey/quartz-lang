#include "parseFlags.hpp"

string outputFilepath = "a.out";

int parseFlags(vector<string> args){

    for(int i = 1; i < args.size(); i++){

        if(args.at(i).compare("--help") == 0){
            printHelp(args.at(0));
            return -1;
        }

        if(args.at(i).compare("-o") == 0){

            if((i + 1) == args.size()){
                return -2;
            }

            outputFilepath = string(args.at(i));
            continue;
        }

    }

    return 0;

}

void printHelp(string arg0){

    printf("Usage: %s [options] files...\n", arg0.c_str());
    printf("\n");
    printf("Options:\n");
    printf("  --help            print this menu\n");
    printf("  -o <filepath>     place output in specified filepath\n");

}