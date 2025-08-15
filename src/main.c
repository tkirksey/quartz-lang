#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define QUARTZ_VERSION 82025

/* === [ Declarations ] === */

void print_usage();
extern void process_args(int ARGC, char **ARGV, char** input_filepaths);

/* === [ Initializations ] === */

int main(int argc, char** argv){

    char* input_filepaths[argc];

    for(int i = 0; i < argc; i++){
        input_filepaths[i] = NULL;
    }

    process_args(argc, argv, input_filepaths);

    if(input_filepaths[0] == NULL){
        printf("[Fatal]: no input files\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

