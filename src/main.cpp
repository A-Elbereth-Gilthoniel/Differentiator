#include "differentiator.h"

//=====================================================

int main(int argc, char *argv[])
{
    srand ( time(NULL) );
    int derivative_num = 0;
    char* file_name = argv[1];
    file_validation(file_name);
    char* str = read_and_handle_file(file_name);

    if (argc == 3)
        sscanf(argv[2], "%d", &derivative_num);
    else
    {
        fprintf(stderr, "What's number of derivative?\n");
        scanf("%d", &derivative_num);
    }

    make_tex();

    list_struct* token_list = lexical_analysis(str);
    token_list = reversed_list(token_list);                 // WARNING: parsing from right to left

    tree* token_tree = parsing(token_list);
    draw_graph(token_tree, "Tree_graph.dot");

    take_n_derivatives(token_tree, derivative_num);

    draw_graph(token_tree, "Tree_graph3.dot");
    finish_tex_file();
    fprintf(stderr, "SUCCESS\n");

    return 0;
}


//=====================================================

