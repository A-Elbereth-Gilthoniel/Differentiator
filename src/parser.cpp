#include "differentiator.h"


//=======================================================

int cur_ind = 0;

tree* parsing(list_struct* token_list)
{
    cur_ind = 0;
    tree* token_tree = make_tree();
    token_tree->root = handle_start(token_list);
    token_tree->size = token_list->size;
    return token_tree;
}

//=======================================================

node* handle_start(list_struct* token_list)
{
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS)
    {
        node* result = handle_plus_minus(token_list);
        return result;
    }

    else
    {
        WRONG_LAST_SYMB
    }
}

//=======================================================

node* handle_plus_minus(list_struct* token_list)
{
    node* cur_node = token_list->data[cur_ind];
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS || IS_FUNCTION)
    {
        node* result = handle_mul_div(token_list);

        if (cur_ind >= token_list->size - 1)
            return result;

        cur_ind++;
        if (IS_PLUS || IS_MINUS)
        {
            cur_node = token_list->data[cur_ind];
            cur_node->right = result;
            cur_ind++;
            cur_node->left = handle_plus_minus(token_list);
        }
        else if IS_CLOSE_BRACKETS
        {
            cur_node = result;
            cur_ind--;
        }
        else
            WRONG_COMB
    }
    else
        WRONG_COMB
    return cur_node;
}

//=======================================================

node* handle_mul_div(list_struct* token_list)
{
    node* cur_node = token_list->data[cur_ind];
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS || IS_FUNCTION)
    {
        node* result = handle_power(token_list);

        if (cur_ind >= token_list->size - 1)
            return result;
        cur_ind++;
        if (IS_MULTIPLY || IS_DIVISION)
        {
            cur_node = token_list->data[cur_ind];
            cur_node->right = result;
            cur_ind++;
            cur_node->left = handle_mul_div(token_list);
        }
        else if (IS_CLOSE_BRACKETS || IS_PLUS || IS_MINUS)
        {
            cur_node = result;
            cur_ind--;
        }
        else
            WRONG_COMB
    }
    else
        WRONG_COMB
    return cur_node;
}

//=============================================================

node* handle_power(list_struct* token_list)
{
    node* ret_node = token_list->data[cur_ind];
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS || IS_FUNCTION)
    {
        node* result = handle_func(token_list);
        if (cur_ind >= token_list->size - 1)
            return result;
        cur_ind++;
        if IS_POWER
        {
            ret_node = token_list->data[cur_ind];
            ret_node->right = result;
            cur_ind++;
            ret_node->left = handle_power(token_list);
        }
        else if (IS_CLOSE_BRACKETS || IS_PLUS || IS_MINUS || IS_MULTIPLY || IS_DIVISION)
        {
            ret_node = result;
            cur_ind--;
        }
        else
            WRONG_COMB
    }
    else
        WRONG_COMB
    return ret_node;
}

//=============================================================

node* handle_func(list_struct* token_list)
{
    node* ret_node = token_list->data[cur_ind];
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS)
    {
        node* result = handle_val_var(token_list);
        if (cur_ind >= token_list->size - 1)
            return result;
        cur_ind++;
        if IS_FUNCTION
        {
            ret_node = token_list->data[cur_ind];
            ret_node->right = result;
            double buf_value = -1;
            ret_node->left = make_node(VALUE_TYPE, &buf_value);
        }
        else if (IS_CLOSE_BRACKETS || IS_PLUS || IS_MINUS || IS_MULTIPLY || IS_DIVISION || IS_POWER)
        {
            ret_node = result;
            cur_ind--;
        }
        else
            WRONG_COMB
    }
    else
        WRONG_COMB
    return ret_node;
}

//=============================================================

node* handle_val_var(list_struct* token_list)
{
    node* buffer = NULL;
    if (IS_VALUE || IS_VARYABLE)
    {
        return token_list->data[cur_ind];
    }
    if (IS_OPEN_BRACKETS)
    {
        cur_ind++;
        buffer = handle_plus_minus(token_list);
        cur_ind++;
        if IS_FUNCTION
        {
            token_list->data[cur_ind]->right = buffer;
            double buf_value = -1;
            token_list->data[cur_ind]->left = make_node(VALUE_TYPE, &buf_value);
            return token_list->data[cur_ind];
        }
    }
    else
        WRONG_COMB

    return buffer;
}
