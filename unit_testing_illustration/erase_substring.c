#include "erase_substring.h"

void erase_substring(char* string, const char* erase) {

    if ((NULL != string) && (NULL != erase) && (0 != strlen(string)) && (0 != strlen(erase))) {

        char* suffix = NULL;

        while (NULL != (suffix = strstr(string, erase))) {

            size_t string_length = strlen(string);
            size_t erase_length  = strlen(erase);
            size_t suffix_length = strlen(suffix);
            size_t leftover_tail_length  = suffix_length - erase_length;
            size_t new_length = string_length - erase_length;
                
            memmove(suffix, suffix + erase_length, leftover_tail_length);
            memset(string + new_length, 0, erase_length);
        }
    }
}
