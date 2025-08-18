#include <cstdlib>
#include <cstring>
#include <cstdio>

#include <vector>
using std::vector;

#include "flags.hpp"

/* === [ Declarations ] === */

bool is_quartz_file(const char *filepath);
void process_flag(const char *flag, const char* flag_argument);

static inline bool are_strings_equal(const char *str1, const char *str2);
static inline bool is_flag(const char *str);
static inline void print_help();

/* === [ Initializations ] === */

void process_args(int ARGC, char **ARGV, vector<char*>* input_filepaths){

    for(int argument_index = 1; argument_index < ARGC; argument_index += 1){

        // found a flag
        if(is_flag(ARGV[argument_index])){

            if((argument_index + 1) == ARGC){
                process_flag(ARGV[argument_index], NULL);
            } else {
                process_flag(ARGV[argument_index], ARGV[argument_index + 1]);
            }

            continue;

        }
        
        // found a quartz file
        if(is_quartz_file(ARGV[argument_index])){

           input_filepaths->push_back(ARGV[argument_index]);

           continue;

        }

    }

}

void process_flag(const char *flag, const char *flag_argument){

    // process output flag
    if(are_strings_equal("--output", flag) || are_strings_equal("-o", flag)){

        if(flag_argument == NULL){

            printf("[Warning]: no output filepath passed with '--output/-o' flag.\n");

        } else {

            OUTPUT_FILEPATH = flag_argument;

        }

        return;

    }

    // process werror flag
    if(are_strings_equal("--werror", flag)){

        ENABLE_WERROR = true;

        printf("[Todo]: warnings as errors functionality\n");

        return;

    }

    // process help flag
    if(are_strings_equal("--help", flag) || are_strings_equal("-h", flag)){

        print_help();
        exit(EXIT_SUCCESS);

    }

}

bool is_quartz_file(const char *filepath){

    const char *file_extension = strrchr(filepath, '.');

    if(file_extension == NULL){
        return false;
    }

    return are_strings_equal(file_extension, ".qz");

}

static inline bool are_strings_equal(const char *str1, const char *str2){

    return strcmp(str1, str2) == 0;

}

static inline bool is_flag(const char *str){

    return str[0] == '-';

}

static inline void print_help(){

    printf("Usage: qzc [Options] file...\n");
    printf("\n");
    printf("Options:\n");
    printf("  --output  -o    changes the filepath of the output file.\n");
    printf("  --werror        enables treating warnings as errors (NOT FUNCTIONAL)\n");
    printf("  --help    -h    displays this menu\n");
    printf("\n");

}
