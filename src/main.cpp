#include "differentiator.h"

//=====================================================

int main(int argc, char *argv[])
{
    char* file_name = argv[1];
    file_validation(file_name);

    size_t num_of_symbols = 0;

    char* str = read_file(file_name, &num_of_symbols);
    num_of_symbols -= delete_n_and_r(str);

    simplification(str);
}


//=====================================================

