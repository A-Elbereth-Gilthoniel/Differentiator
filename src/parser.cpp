#include "differentiator.h"


//=======================================================

int cur_ind = 0;

tree* parsing(list_struct* token_list)
{
    cur_ind = 0;
    tree* token_tree = make_tree();
    token_tree->root = stmt(token_list);
    fprintf(stderr, "SUCCESS!\n");
    token_tree->size = token_list->size;
    return token_tree;
}

//=======================================================

node* stmt(list_struct* token_list)
{
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS)
    {
        node* result = expr(token_list);
        return result;
    }

    else
    {
        assert(NULL);   // TODO
    }
}

//=======================================================

node* expr(list_struct* token_list)
{
    fprintf(stderr, "expr\t%s\n", take_str_from_node(token_list->data[cur_ind]));
    node* our_node = token_list->data[cur_ind];
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS)
    {
        node* result = term(token_list);
        fprintf(stderr, "from term to expr\t%s\n", take_str_from_node(result));
        if (cur_ind >= token_list->size - 1)
            return result;
        cur_ind++;
       // fprintf(stderr, "and2\t%s\n", take_str_from_node(token_list->data[cur_ind]));
        if (IS_PLUS || IS_MINUS)
        {
             fprintf(stderr, "we plus\n");
            our_node = token_list->data[cur_ind];
            our_node->left = result;
            cur_ind++;
            our_node->right = expr(token_list);
        }
        else if IS_CLOSE_BRACKETS
        {
            our_node = result;
            cur_ind--;
           // our_node = token_list->data[cur_ind];
        }
        else
        {
            assert(NULL);   // TODO
        }
    }
    else
    {
        assert(NULL);       // TODO
    }
   // fprintf(stderr, "and2\t%s\n", take_str_from_node(token_list->data[cur_ind]));
    return our_node;
}

//=======================================================

node* term(list_struct* token_list)
{
    fprintf(stderr, "term\t%s\n", take_str_from_node(token_list->data[cur_ind]));
    // printf("%s\n", take_str_from_node(token_list->data[cur_ind]));
    node* our_node = token_list->data[cur_ind];
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS)
    {
        node* result = fact(token_list);
         fprintf(stderr, "from fact to term\t%s\n", take_str_from_node(result));
        if (cur_ind >= token_list->size - 1)
            return result;
        cur_ind++;
        if (IS_MULTIPLY || IS_DIVISION)
        {
            our_node = token_list->data[cur_ind];
            our_node->left = result;
            cur_ind++;
            our_node->right = term(token_list);
        }
        else if (IS_CLOSE_BRACKETS || IS_PLUS || IS_MINUS)
        {
            our_node = result;
            cur_ind--;
        }
        else
            assert(NULL);
    }
    else
        assert(NULL);
   // fprintf(stderr, "and\t%s\n", take_str_from_node(token_list->data[cur_ind]));
    return our_node;
}

//=============================================================

// node* power(list_struct* token_list, int cur_ind)

//=============================================================

node* fact(list_struct* token_list)
{
    fprintf(stderr, "fact\t%s\n", take_str_from_node(token_list->data[cur_ind]));
    node* buffer = NULL;
    if (IS_VALUE || IS_VARYABLE)
    {
        return token_list->data[cur_ind];
    }
    if (IS_OPEN_BRACKETS)
    {
        cur_ind++;
        buffer = expr(token_list);
        cur_ind++;
    }
    else
        assert(NULL);

    return buffer;
}
