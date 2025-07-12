#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "structs.h"

#define QUARTZ_VERSION 72025

extern bool WERROR;

extern void parse_args(int argc, char** argv, flag_values_t* flag_values, input_filepaths_t* input_filepaths);
extern void filter_input_filepaths(input_filepaths_t* input_filepaths);

int main(int argc, char** argv){

    if(argc == 1){
        printf("Quartz Compiler -- devolpement version %06d\n", QUARTZ_VERSION);
        exit(EXIT_SUCCESS);
    }

    // Step 1: parse arguments for flags and input filepaths

    char* input_filepaths_array[argc - 1];

    // input filepaths setup
    input_filepaths_t input_filepaths = {

        .input_filepaths_array = input_filepaths_array,
        .input_filepaths_count = 0

    };

    // flag variables setup
    flag_values_t flag_values = {

        .output_filename = "a.out"

    };

    parse_args(argc, argv, &flag_values, &input_filepaths);
    filter_input_filepaths(&input_filepaths);
    
    

    return 0;
}