#include <cstdlib>
#include <cstring>
#include <cstdio>

#include <vector>
using std::vector;

#include "flags.hpp"

/* === [ Declarations ] === */

bool isQuartzFile(const char *filepath);
void processFlag(const char *flag, const char* flagArgument);

static inline bool areStringsEqual(const char *str1, const char *str2);
static inline bool isFlag(const char *str);
static inline void printHelp();

/* === [ Initializations ] === */

void processArgs(int ARGC, char **ARGV, vector<char*>* inputFilepaths){

    for(int argumentIndex = 1; argumentIndex < ARGC; argumentIndex += 1){

        // found a flag
        if(isFlag(ARGV[argumentIndex])){

            if((argumentIndex + 1) == ARGC){
                processFlag(ARGV[argumentIndex], NULL);
            } else {
                processFlag(ARGV[argumentIndex], ARGV[argumentIndex + 1]);
            }

            continue;

        }
        
        // found a quartz file
        if(isQuartzFile(ARGV[argumentIndex])){

           inputFilepaths->push_back(ARGV[argumentIndex]);

           continue;

        }

    }

}

void processFlag(const char *flag, const char *flagArgument){

    // process output flag
    if(areStringsEqual("--output", flag) || areStringsEqual("-o", flag)){

        if(flagArgument == NULL){

            printf("[Warning]: no output filepath passed with '--output/-o' flag.\n");

        } else {

            OUTPUT_FILEPATH = flagArgument;

        }

        return;

    }

    // process werror flag
    if(areStringsEqual("--werror", flag)){

        ENABLE_WERROR = true;

        printf("[Todo]: warnings as errors functionality\n");

        return;

    }

    // process help flag
    if(areStringsEqual("--help", flag) || areStringsEqual("-h", flag)){

        printHelp();
        exit(EXIT_SUCCESS);

    }

}

bool isQuartzFile(const char *filepath){

    const char *file_extension = strrchr(filepath, '.');

    if(file_extension == NULL){
        return false;
    }

    return areStringsEqual(file_extension, ".qz");

}

static inline bool areStringsEqual(const char *str1, const char *str2){

    return strcmp(str1, str2) == 0;

}

static inline bool isFlag(const char *str){

    return str[0] == '-';

}

static inline void printHelp(){

    printf("Usage: qzc [Options] file...\n");
    printf("\n");
    printf("Options:\n");
    printf("  --output  -o    changes the filepath of the output file.\n");
    printf("  --werror        enables treating warnings as errors (NOT FUNCTIONAL)\n");
    printf("  --help    -h    displays this menu\n");
    printf("\n");

}
