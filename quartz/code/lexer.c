#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// lexer entry

/**
 * @brief creates temporary token files that are stored in the executing directory and will be cleaned later by parser
 * 
 * @param filepaths the pointer to the array of cstring with the size of filepath_size
 * @param filepath_size the size in bytes of an element of the cstring array
 * @param filepath_count the amount of cstrings
 * @return int error codes
 */
int lexer(char* filepaths, uint16_t filepath_size, uint16_t filepath_count){

    char current_filepath[filepath_size];
    uint16_t filepath_index = 0;
    FILE* current_file = NULL;

    while(filepath_index != filepath_count){

        memcpy(&current_filepath, filepaths + (filepath_size * filepath_index), filepath_size);

        current_file = fopen(current_filepath, "r");

        if(!current_file){
            return 1;
        }

        // tokenizer



        fclose(current_file);
        current_file = NULL;

        filepath_index++;
    }

}