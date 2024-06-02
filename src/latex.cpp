#include "differentiator.h"

struct copy_str {
    char str[1000];
};

FILE* tex;
int cur_n_der = 1;

void add_tex_file(char* der_str, int picture)
{
    fprintf(tex, " \\begin{figure}[h]\n\
\\centering\n\
\\caption{DERIVATIVE %d}\n\
\\end{figure}", cur_n_der);
    cur_n_der++;

    fprintf(tex, "\n\\begin {equation}\n");
    fprintf(tex, "%s\n", der_str);
    fprintf(tex,"\\end {equation}\n\n");
}

//====================================================

char line[1000];

struct copy_str get_expr(node* handled_node)
{
    struct copy_str str_copy;
    switch (handled_node->type)
    {
        case VALUE_TYPE:
        case VARYABLE_TYPE:
            strcpy(str_copy.str, take_str_from_node(handled_node));
            return str_copy;
        case OPER_TYPE:
            handle_operation(handled_node, str_copy.str);
    }
    return str_copy;
}

//=======================================================

void handle_operation(node* cur_node, char* str)
{
    switch (cur_node->content.token)
    {
        case ADD:
            sprintf(str, "%s + %s", get_expr(cur_node->left).str, get_expr(cur_node->right).str);
            break;
        case SUBTRACT:
            sprintf(str, "%s - %s", get_expr(cur_node->left).str, get_expr(cur_node->right).str);
            break;
        case MULTIPLY:
            sprintf(str, "%s * %s", get_expr(cur_node->left).str, get_expr(cur_node->right).str);
            break;
        case DIVISION:
            sprintf(str, "\\frac {%s} {%s}", get_expr(cur_node->left).str, get_expr(cur_node->right).str);
            break;
        case POWER:
            sprintf(str, "(%s) ^ {%s}", get_expr(cur_node->left).str, get_expr(cur_node->right).str);
            break;
        case COS:
            sprintf(str, "\\cos(%s)", get_expr(cur_node->right).str);
            break;
        case SIN:
            sprintf(str, "\\sin(%s)", get_expr(cur_node->right).str);
            break;
        case TAN:
            sprintf(str, "\\tan(%s)", get_expr(cur_node->right).str);
            break;
        case CTAN:
            sprintf(str, "\\cot(%s)", get_expr(cur_node->right).str);
            break;
        case LN:
            sprintf(str, "\\ln(%s)", get_expr(cur_node->right).str);
            break;
        default:
            sprintf(str, "%s", get_expr(cur_node).str);
    }
}

//=========================================================

void make_tex()
{
    char full_file_name[100] = FILE_REPOSITORY;
    strcat(full_file_name, "differentiator.tex");
    tex = fopen(full_file_name, "w");

    fprintf(tex, "\\documentclass{article}\n\
\\usepackage{graphicx}\n\
\\usepackage{amsmath,amsfonts,amssymb,amsthm,mathtools}\n\
\\usepackage[fontsize=10pt]{fontsize}\n\
\\usepackage{graphicx}\n\
\\usepackage{float}\n\
\\usepackage{wrapfig}\n\
\\title{Differentiation}\n\
\\author{Rakhmetoff Rinat }\n\
\\date{April 2024}\n\
\\begin{document}\n\
\\maketitle\n\
\\section{Introduction}\n");
}

//===============================================

void finish_tex_file()
{
    fprintf(tex, "\\end{document}\n");
    fclose(tex);
}
