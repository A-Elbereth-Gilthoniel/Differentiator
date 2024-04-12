#include "differentiator.h"

//=====================================================

int main(int argc, char *argv[])
{
    char* file_name = argv[1];
    file_validation(file_name);

    size_t num_of_symbols = 0;

    char* str = read_and_handle_file(file_name);

    list_struct* token_list = lexical_analysis(str);
    token_list = reversed_list(token_list);

    tree* token_tree = parsing(token_list);

    fprintf(stderr, "SUCCESS\n");
    draw_graph(token_tree, "Tree_graph.dot");

    tree* new_tree = simplify_tree(token_tree);
    draw_graph(new_tree, "Tree_graph2.dot");

    char start_str[1000];
    handle_operation(token_tree->root, start_str);

   // fprintf(stderr, "\n\n\n\n\n\n\n\n\n\n");

    tree* derivative_tree = take_tree_of_derivative(new_tree);
    draw_graph(derivative_tree, "Tree_graph3.dot");

    tree* new_tree2 = simplify_tree(derivative_tree);
    draw_graph(new_tree2, "Tree_graph4.dot");

    char final_str[1000];
    handle_operation(new_tree2->root, final_str);

    make_tex_file(start_str, final_str);

    fprintf(stderr, "SUCCESS4!!!\n");

    return 0;
}


//=====================================================

