#include "differentiator.h"

#define DIR_MAX_NAME_LEN 50
#define DIRECTORY_NAME "./tests/"

//==========================================================

char* read_file(char* file_name, size_t* symbols_num)
{
    char dirf[DIR_MAX_NAME_LEN] = DIRECTORY_NAME;
    strncat (dirf, file_name, DIR_MAX_NAME_LEN);
    FILE *fp = fopen(dirf, "rb");

    *(symbols_num) = find_file_size(fp);

    char* text_from_file = (char*) calloc(*symbols_num + 1, sizeof(char));
    fread(text_from_file, sizeof(char), *symbols_num, fp);

    fclose(fp);

    return text_from_file;
}

//=========================================================

void file_validation(char* file_name)
{
    char dirf[DIR_MAX_NAME_LEN] = DIRECTORY_NAME;
    strncat (dirf, file_name, DIR_MAX_NAME_LEN);

    FILE* fp = fopen(dirf, "r");
    if (!fp)
    {
        fprintf(stderr, red(File doesn`t exist!)"\n");
        fclose(fp);
        exit(1);
    }
    if (find_file_size(fp) < 2)
    {
        fprintf(stderr, red(File is empty!)"\n");
        fclose(fp);
        exit(1);
    }
    fclose(fp);
}

//==========================================================

size_t find_file_size(FILE* fp)
{
    fseek(fp, 0, SEEK_END);
    size_t n = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return n;
}

