#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "count.h"


bool is_delimiter(char c) {
    return (isspace(c) || strchr(".?!,;:()[]{}-\"/", c));
}

/**
 * Iterates through a null-terminated string sequence and counts
 * the number of words based on alphabetic sequences (A-Z, a-z) separated by
 * delimiters (space, punctution).
 * Targets English language texts (apostrophes are included e.g don't, it's).
*/
int  word_count(char* text) {

    if (!text) {
        fprintf(stderr, "Error: Empty text buffer\n");
        return 0;
    }

    int word_count = 0;
    bool IN_WORD = false;

    for (int i = 0; text[i] != '\0'; i++) {
        // allow apostrophe inside word e.g. don't
        if (isalpha(text[i]) || (text[i] == '\'' && i > 0 && isalpha(text[i - 1]) && isalpha(text[i + 1]))) {
            if (!IN_WORD) IN_WORD = true;
        } else if (is_delimiter(text[i])) {
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


