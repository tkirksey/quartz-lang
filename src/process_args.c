#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* === [ Declarations ] === */

extern char* OUTPUT_FILEPATH;
extern bool ENABLE_WERROR;

bool SKIP_NEXT_ARGUMENT = false;

bool are_strings_equal(char* str1, char* str2);
bool is_flag(char* str);
bool is_quartz_file(char* filepath);

void print_help();
void process_flag(const int CURRENT_ARGUMENT_INDEX, int ARGC, char **ARGV);

/* === [ Initializations ] === */

void process_args(int ARGC, char **ARGV, char** input_filepaths){

    unsigned int num_of_input_fps = 0;

    for(int argument_index = 1; argument_index < ARGC; argument_index += 1){

        char* current_arg = ARGV[argument_index];

        // found a flag
        if(is_flag(current_arg)){

            process_flag(argument_index, ARGC, ARGV);

            if(SKIP_NEXT_ARGUMENT){
                argument_index += 1;
                SKIP_NEXT_ARGUMENT = false;
            }

            continue;

        }
        
        // found a quartz file
        if(is_quartz_file(current_arg)){

           input_filepaths[num_of_input_fps] = current_arg;
           num_of_input_fps += 1;

        }

    }

}

void process_flag(const int CURRENT_ARGUMENT_INDEX, int ARGC, char **ARGV){

    char* flag = ARGV[CURRENT_ARGUMENT_INDEX];

    // process output flag
    if(are_strings_equal("--output", flag) || are_strings_equal("-o", flag)){

        // if there is no argument passed for the flag
        if((CURRENT_ARGUMENT_INDEX + 1) == ARGC || is_flag(ARGV[(CURRENT_ARGUMENT_INDEX + 1)])){

            printf("[Warning]: No addtional argument passed for the '--output'/'-o' flag\n");
            return;

        }

        OUTPUT_FILEPATH = ARGV[(CURRENT_ARGUMENT_INDEX + 1)];

        SKIP_NEXT_ARGUMENT = true;

        return;

    }

    // process werror flag
    if(are_strings_equal("--werror", flag)){

        ENABLE_WERROR = true;

        printf("[Todo]: treat warnings as errors functionality\n");

        return;

    }

    // process help flag
    if(are_strings_equal("--help", flag) || are_strings_equal("-h", flag)){

        print_help();
        exit(EXIT_SUCCESS);

    }

}

bool is_quartz_file(char* filepath){

    if(filepath == NULL){
        return false;
    }

    char* file_extension = strrchr(filepath, '.');

    if(file_extension == NULL){
        return false;
    }

    return are_strings_equal(file_extension, ".qz");

}

bool are_strings_equal(char* str1, char* str2){

    if(strcmp(str1, str2) != 0){
        return false;
    }

    return true;

}

bool is_flag(char* str){

    if(str[0] == '-'){
        return true;
    }

    return false;

}

void print_help(){

    printf("Usage: qzc [Options] file...\n");
    printf("\n");
    printf("Options:\n");
    printf("  --output  -o    changes the filepath of the output file.\n");
    printf("  --werror        enables treating warnings as errors (NOT FUNCTIONAL)\n");
    printf("  --help    -h    displays this menu\n");
    printf("\n");

}
