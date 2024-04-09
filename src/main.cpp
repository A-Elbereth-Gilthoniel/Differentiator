#include "differentiator.h"

//=====================================================

int main(int argc, char *argv[])
{
    char* file_name = argv[1];
    file_validation(file_name);

    size_t num_of_symbols = 0;

    char* str = read_file(file_name, &num_of_symbols);
    num_of_symbols -= delete_n_and_r(str);

    list_struct* token_list = lexical_analysis(str);
    for (int cur_ind = 0; cur_ind < token_list->size; cur_ind++)
        printf("%s ", take_str_from_node(token_list->data[cur_ind]));
    printf("\n");
    tree* token_tree = parsing(token_list);

    fprintf(stderr, "SUCCESS\n");
    draw_graph(token_tree);

    return 0;
}


//=====================================================

