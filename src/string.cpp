#include "differentiator.h"

int delete_n_and_r(char* str)
{
    int char_difference = 0;
    char* slash_r = strchr(str, '\r');
    if (slash_r != NULL)
    {
        *(slash_r) = '\0';
        char_difference += 1;
    }
    char* slash_n = strchr(str, '\n');
    if (slash_n != NULL)
    {
        *(slash_n) = '\0';
        char_difference += 1;
    }
    return char_difference;
}
