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

//==============================================================

char* space_replace(char *orig, int size)
{
    char* result;
    char* new_str = result = (char*) calloc(size + 1, sizeof(char));
    char* insert_point;
    int n = 0;

    while (insert_point = strchr(orig, ' '))
    {
        n = insert_point - orig;
        new_str = strncpy(new_str, orig, n) + n;
        orig = orig + n + 1;
    }

    strcpy(new_str, orig);
    return result;
}
