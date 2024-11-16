#include <stdio.h>
#include "readfile.h"


int main(void) {

    char* book = read_file_to_buffer("/Users/ten53/Developer/bookbot/books/frankenstein.txt");

    if (!book) {
        fprintf(stderr, "Ooops, Something went wrong\n");
        return -1;
    }

    printf("%s\n", book);

    return 0;
}
