#include "libr.h"
#include "structures.h"
#include "constants.h"


// file.cpp
char* read_file(char* file_name, size_t* symbols_num);
void file_validation(char* file_name);
size_t find_file_size(FILE* fp);
// string.cpp
int delete_n_and_r(char* str);
