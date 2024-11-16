#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readfile.h"


/*
 * reads content into dynamically allocated buffer
 * null-terminated to be used as a string
 * caller is responsible for freeing allocated buffer!
 * supports text-files only (at least for now)
 */

char* read_file_to_buffer(const char* filename) {
    if (!filename) {
        fprintf(stderr, "Error: Filename is NULL\n");
        return NULL;
    }

    // ----- OPEN FILE ----
    FILE* file = fopen(filename, "r");

    if (!file) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }

    // ----- DETERMINE SIZE -----
    if (fseek(file, 0, SEEK_END) != 0) {
        fprintf(stderr, "Error seeking end of file\n");
        fclose(file);
        return NULL;
    }

    long file_size = ftell(file);
    if (file_size == -1) {
        fprintf(stderr, "Error determining file size\n");
        fclose(file);
        return NULL;
    }

    // return empty string if file is empty
    if (file_size == 0) {
        fclose(file);
        char* empty_buffer = malloc(1);
        if (empty_buffer) {
            empty_buffer[0] = '\0'; // add null-terminator (empty string)
        }
        if (!empty_buffer) {
            fprintf(stderr, "Error allocating memory for empty file\n" );
        }
        return empty_buffer;
    }

    rewind(file);   // reset file ptr to beginning

    // ----- ALLOCATE MEMORY -----
    char* buffer = malloc(file_size + 1); // +1 byte for null-terminator
    if(!buffer) {
        fprintf(stderr, "Error allocating memory");
        fclose(file);
        return NULL;
    }
    memset(buffer, 0, file_size + 1); // init buffer

    // ----- READ FILE CONTENT -----
    size_t bytes_read = fread(buffer, sizeof(char), file_size, file);
    if (bytes_read != file_size) {
        fprintf(stderr, "Error: Could only read %zu of %ld bytes\n", bytes_read, file_size);
        free(buffer);
        fclose(file);
        return NULL;
    }
    buffer[file_size] = '\0'; // add null-terminator to buffer

    fclose(file);

    return buffer; // read file content successfully
}
