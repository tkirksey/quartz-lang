#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define QUARTZ_VERSION 62025

extern int lexer(char* filepaths, uint16_t filepath_size, uint16_t filepath_count);

void print_usage(){

    printf("Usage: quartz [options] file...\n");
    printf("Options:\n");
    printf("  --help  Prints this message.       \n");
    printf("\n");

}

int main(int argc, char** argv){

    if(argc == 1){
        printf("Quartz -- version %06d\n", QUARTZ_VERSION);
        exit(EXIT_SUCCESS);
    }

    if(strncmp(argv[1], "--help", 7) == 0){
        print_usage();
    }

    // get filepaths that end in '.qz'

    // call lexer
    //
    // LEXER CONTRACT:
    // Filepaths shall end in '.qz'
    // NULL will never be passed into "filepaths"
    //
    // Breach of contract causes unknown behaviors

    switch(lexer(NULL, 0, 0)){
        case 1:
            // File failed to open
            break;
        default:
            // operation successful
    }

    return 0;
}