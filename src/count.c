#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "count.h"

bool is_delimiter(char c) {
    return (isspace(c) || strchr(".?!,;:()[]{}-\"/", c));
}

int  word_count(char* file_content) {

    if (!file_content) {
        fprintf(stderr, "Error: Empty buffer\n");
        return 0;
    }

    int word_count = 0;
    bool IN_WORD = false;

    for (int i = 0; file_content[i] != '\0'; i++) {
        // allow apostrophe inside word e.g. don't
        if (isalpha(file_content[i]) || (file_content[i] == '\'' && i > 0 && isalpha(file_content[i - 1]) && isalpha(file_content[i + 1]))) {
            if (!IN_WORD) IN_WORD = true;
        } else if (is_delimiter(file_content[i])) {
            if (IN_WORD) {
                word_count++;
                IN_WORD = false;
            }
        }
    }

    // account for last word
    if (IN_WORD) word_count++;

    return word_count;
}


