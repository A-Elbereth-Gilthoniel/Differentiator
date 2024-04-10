#include "differentiator.h"

//=============================================================

void draw_graph(tree* cur_tree, const char* file_name)
{
    char full_file_name[100] = FILE_REPOSITORY;
    strcat(full_file_name, file_name);
    FILE* fp = fopen(full_file_name, "w");

    fprintf(fp, "digraph G {\
                \n  tree [shape=box ; stryle=rounded ; label=\"size : %d\"];\
                \n  edge [color=black];\
                \n  node [shape=record ; style=rounded ; color=green];\n", cur_tree->size);

    print_node_in_graph(fp, cur_tree->root);
    print_edge_in_graph(fp, cur_tree->root);

    fprintf(fp, "}");
    fclose(fp);
}

//============================================================

void print_node_in_graph(FILE* fp, node* cur_node)
{
    if (!cur_node->left && !cur_node->right)
    {
        fprintf(fp, "%d [label=\"{%s}\"];\n", cur_node, take_str_from_node(cur_node));
        return;
    }
    fprintf(fp, "%d [label=\"{%s|{<YES>LEFT|<NO>RIGHT}}\"];\n", cur_node, take_str_from_node(cur_node));
    if (cur_node->left)
        print_node_in_graph(fp, cur_node->left);
    if (cur_node->right)
        print_node_in_graph(fp, cur_node->right);
}

//===========================================================

void print_edge_in_graph(FILE* fp, node* cur_node)
{
    if (cur_node->left)
    {
        fprintf(fp, "%d:<YES> -> %d [color=green];\n", cur_node, cur_node->left);
        print_edge_in_graph(fp, cur_node->left);
    }
    if (cur_node->right)
    {
        fprintf(fp, "%d:<NO> -> %d [color=red];\n", cur_node, cur_node->right);
        print_edge_in_graph(fp, cur_node->right);
    }
}
