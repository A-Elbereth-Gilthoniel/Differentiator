#include "differentiator.h"

struct whore {
    char str[100];
};

char final_str[1000];

void make_tex_file(tree* start_tree, tree* final_tree)
{
    char full_file_name[100] = FILE_REPOSITORY;
    strcat(full_file_name, "differentiator.tex");
    FILE* tex = fopen(full_file_name, "w");

    fprintf(tex, "\\documentclass{article}\n\
\\usepackage{graphicx}\n\
\\usepackage{amsmath,amsfonts,amssymb,amsthm,mathtools}\n\
\\usepackage[fontsize=10pt]{fontsize}\n\
\\title{Differentiation}\n\
\\author{Rakhmetoff Rinat }\n\
\\date{April 2024}\n\
\\begin{document}\n\
\\maketitle\n\
\\section{Introduction}\n");

    fprintf(tex, "In the beggining we had\n");

    fprintf(tex, "\\begin {equation}\n");
    handle_operation(start_tree->root, final_str);
    fprintf(tex, "%s\n", final_str);
    fprintf(tex,"\\end {equation}\n");
    fprintf(tex, "\n\nIn the end it doesnt even matter\n");
    fprintf(tex, "\\begin {equation}\n");
    handle_operation(final_tree->root, final_str);
    fprintf(tex, "%s\n", final_str);
    fprintf(stderr, "%d\n", strlen(final_str));
    fprintf(tex,"\\end {equation}\n");

    fprintf(tex, "\\end{document}\n");
}

//====================================================

char line[1000];

struct whore get_expr(node* handled_node)
{
    struct whore mmm;
    switch (handled_node->type)
    {
        case VALUE_TYPE:
        case VARYABLE_TYPE:
            strcpy(mmm.str, take_str_from_node(handled_node));
            return mmm;
        case OPER_TYPE:
            handle_operation(handled_node, mmm.str);
    }
    return mmm;
}

//=======================================================

// char* line2[100];
//
// char* get_expr(node* handled_node)
// {
//     switch (handled_node->type)
//     {
//         case VALUE_TYPE:
//         case VARYABLE_TYPE:
//             return take_str_from_node(handled_node);
//         case OPER_TYPE:
//             handle_operation(handled_node, line2);
//     }
//     return line2;
// }

void handle_operation(node* cur_node, char* str)
{
    switch (cur_node->content.token)
    {
        case ADD:
            sprintf(str, "%s + %s", get_expr(cur_node->left).str, get_expr(cur_node->right).str);
            break;
           //return str
        case SUBTRACT:
            sprintf(str, "%s - %s", get_expr(cur_node->left).str, get_expr(cur_node->right).str);
            break;
           //return str
        case MULTIPLY:
            sprintf(str, "%s * %s", get_expr(cur_node->left).str, get_expr(cur_node->right).str);
            break;
           //return str
        case DIVISION:
            sprintf(str, "\\frac {%s} {%s}", get_expr(cur_node->left).str, get_expr(cur_node->right).str);
            break;
           //return str
        case POWER:
            sprintf(str, "(%s) ^ {%s}", get_expr(cur_node->left).str, get_expr(cur_node->right).str);
            break;
           //return str
        case COS:
            sprintf(str, "\\cos{%s}", get_expr(cur_node->right).str);
            break;
           //return str
        case SIN:
            sprintf(str, "\\sin{%s}", get_expr(cur_node->right).str);
            break;
           //return str
        case TAN:
            sprintf(str, "\\tan{%s}", get_expr(cur_node->right).str);
            break;
           //return str
        case CTAN:
            sprintf(str, "\\cot{%s}", get_expr(cur_node->right).str);
            break;
           //return str
        case LN:
            sprintf(str, "\\ln{%s}", get_expr(cur_node->right).str);
            break;
           //return str
        default:
            assert(NULL);
    }
}

//=========================================================
