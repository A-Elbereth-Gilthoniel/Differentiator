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
    token_list = reversed_list(token_list);
    for (int cur_ind = 0; cur_ind < token_list->size; cur_ind++)
        printf("%s ", take_str_from_node(token_list->data[cur_ind]));
    printf("\n");

    tree* token_tree = parsing(token_list);

    fprintf(stderr, "SUCCESS\n");
    draw_graph(token_tree, "Tree_graph.dot");

    tree* new_tree = simplify_tree(token_tree);
    draw_graph(new_tree, "Tree_graph2.dot");

   // fprintf(stderr, "\n\n\n\n\n\n\n\n\n\n");

    tree* derivative_tree = take_tree_of_derivative(new_tree);
    draw_graph(derivative_tree, "Tree_graph3.dot");

    tree* new_tree2 = simplify_tree(derivative_tree);
    draw_graph(new_tree2, "Tree_graph4.dot");

    fprintf(stderr, "SUCCESS4!!!\n");
    return 0;
}


//=====================================================

