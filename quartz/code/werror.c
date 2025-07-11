#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool WERROR = false;

void WERROR_EXIT(){
    printf("[Error]: Warning detected. Aborting execution.\n");
    exit(EXIT_FAILURE);
}