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

    // Step 1: parse arguments for flags and seperate potential input files

    /*
    
        psuedocode:

        check if argument starts with '-'
        if so, evaulate flag an increment index accordingly
        else, add argument to input files list
    
    */

    char* input_filepaths_array[argc - 1];

    // input files
    input_filepaths_t input_filepaths = {

        .input_filepaths_array = input_filepaths_array,
        .input_filepaths_count = 0

    };

    // flag variables
    flag_values_t flag_values = {

        .output_filename = "a.out"

    };

    parse_args(argc, argv, &flag_values, &input_filepaths);

    // Step 2: filter out .qz file

    filter_input_filepaths(&input_filepaths);

    
    /*
    
        Tests for step 1 & 2
    
    */

    // printf("Flags:\n");
    // printf("    --output:   %s\n", flag_values.output_filename);
    // printf("    --Werror:   %s\n", WERROR ? "true" : "false");
    // printf("\n");
    // printf("Input Filepaths:\n");
    // for(uint64_t i = 0; i < input_filepaths.input_filepaths_count; i++){
    //     printf("    %s\n", input_filepaths.input_filepaths_array[i]);
    // }
    // printf("\n");

    return 0;
}