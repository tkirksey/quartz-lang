#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "structs.h"

extern bool WERROR;
extern void WERROR_EXIT();

static inline bool areStringsEqual(const char* str1, const char* str2){
    return strcmp(str1, str2) == 0;
}

void print_help(){

    printf("Usage: qzc [options] file...\n");
    printf("Options:\n");
    printf("    --help      Prints this message.\n");
    printf("    --output    Name the output file.\n");
    printf("    --Werror    Treat all warnings as errors.\n");
    printf("\n");

} 

void parse_args(int argc, char** argv, flag_values_t* flag_values, input_filepaths_t* input_filepaths){

    for(uint64_t argv_index = 1; argv_index < (uint64_t)(argc); argv_index++){

        char* current_argument = argv[argv_index];

        // handle '--Werror'
        if(areStringsEqual(current_argument, "--Werror")){

            WERROR = true;

        }

        // handle '--output' flag
        if(areStringsEqual(current_argument, "--output")){

            // if no output filepath is passed (aka '--output' is the last argument)
            if(argv_index == (uint64_t)(argc - 1)){

                printf("[Warning]: No output filepath passed for '--output'. Using default value ('a.out').\n");

                if(WERROR){
                    WERROR_EXIT();
                } 

                break;

            }

            flag_values->output_filename = argv[argv_index + 1];    // set output file name to passed argument for flag
            argv_index += 1;                                        // increments index to avoid trying to read passed argument as a flag or input filepath

            continue;
        }

        // handle '--help' flag
        if(areStringsEqual(current_argument, "--help")){

            print_help();
            exit(EXIT_SUCCESS);

        }

        /*

            if no flag was found, assume its an input filepath

        */
        input_filepaths->input_filepaths_array[input_filepaths->input_filepaths_count] = current_argument;
        input_filepaths->input_filepaths_count += 1;
        
    }

}

bool has_qz_extension(const char* str){

    size_t str_length = strlen(str);

    if(str_length < 4){
        return false;
    }

    bool z_check = (str[str_length - 1] == 'z'); 
    bool q_check = (str[str_length - 2] == 'q');
    bool dot_check = (str[str_length - 3] == '.');

    return z_check && q_check && dot_check;

}

void filter_input_filepaths(input_filepaths_t* input_filepaths){

    for(uint64_t input_filepaths_index = 0; input_filepaths_index < input_filepaths->input_filepaths_count; input_filepaths_index += 1){

        char* current_input_filepath = input_filepaths->input_filepaths_array[input_filepaths_index];

        if(!has_qz_extension(current_input_filepath)){

            /*  
                pseudocode: 

                copy last filepath to current index
                set last filepath == null
                decrement count and index
            */

            input_filepaths->input_filepaths_array[input_filepaths_index] = input_filepaths->input_filepaths_array[input_filepaths->input_filepaths_count - 1];
            input_filepaths->input_filepaths_array[input_filepaths->input_filepaths_count - 1] = NULL;
            input_filepaths->input_filepaths_count -= 1;
            input_filepaths_index -= 1;

        }

    }

    // if no potential input filepaths were found
    if(input_filepaths->input_filepaths_count == 0){
        printf("[Error]: No input filepaths passed. Aborting execution.\n");
        exit(EXIT_FAILURE);
    }

}