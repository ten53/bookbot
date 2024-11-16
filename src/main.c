#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"
#include "count.h"


int main(void) {

    char* book = read_file_to_buffer("/Users/ten53/Developer/bookbot/books/frankenstein.txt");

    if (!book) {
        fprintf(stderr, "Ooops, Something went wrong\n");
        return -1;
    }

    int total_words = word_count(book);

    printf("Total words counted: %d\n", total_words);

    free(book);

    return 0;
}
