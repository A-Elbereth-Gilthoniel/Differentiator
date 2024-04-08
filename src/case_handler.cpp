#include "differentiator.h"

//========================================================

int index = 0;

//========================================================

void simplification(char* str)
{
    index = 0;
    tree* parser_tree = make_tree();
    double value = 0;
    parser_tree->root = parsing(str);

    node* current_node = parser_tree->root;

    while (str[index] != '\0')
    {
        node* new_node = parsing(str);
        assert(new_node->operation_type != current_node->operation_type);
        if (new_node->operation_type < current_node->operation_type)
        {
            if (current_node->left == NULL)
                insert_into_tree(tree, new_node, current_node, LEFT);
            else
                insert_into_tree(tree, new_node, current_node, RIGHT);

        }
    }
}

//=========================================================

node* parsing(char* str)
{
    double value = 0;

    if ('0' <= str[index] && str[index] <= '9')
    {
        value = get_value(str);

        list_struct* list = make_list(LIST_LEN);
        append_to_list(new_node->list, value);

        return make_node(list, VALUE);
    }
    switch(str[index])
    {
        case '+':
            return make_node(NULL, ADD);
        case ' -':
            return make_node(NULL, SUBTRACT);
        case '*':
            return make_node(NULL, MULTIPLY);
        case '/':
            return make_node(NULL, DIVISION);
        case '^':
            return make_node(NULL, POWER);
        case '(':
            return make_node(NULL, OPENING_BR);
        case ')':
            return make_node(NULL, CLOSING_BR);
        case 'x':
            list_struct* list = make_list(LIST_LEN);
            append_to_list(new_node->list, 0);
            append_to_list(new_node->list, 1);
            return make_node(list, VALUE);
    }
}

//=========================================================

double get_value(char* str)
{
    double value = 0;
    while (str[index] >= '0' && str[index] <= '9')
    {
        value = value * 10 + str[index] - '0';
        index++;
    }
    return value;
}

//=========================================================


