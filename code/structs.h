#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdint.h>

typedef struct {

    char* output_filename;

} flag_values_t;

typedef struct {

    char** input_filepaths_array;
    uint64_t input_filepaths_count;

} input_filepaths_t;

#endif