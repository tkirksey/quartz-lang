#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUARTZ_VERSION 42025

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

    return 0;
}