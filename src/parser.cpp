#include "differentiator.h"


//=======================================================

int cur_ind = 0;

tree* parsing(list_struct* token_list)
{
    cur_ind = 0;
    tree* token_tree = make_tree();
    token_tree->root = handle_start(token_list);
    fprintf(stderr, "SUCCESS!\n");
    token_tree->size = token_list->size;
    return token_tree;
}

//=======================================================

node* handle_start(list_struct* token_list)
{
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS)
    {
        node* result = handle_plus_minus(token_list);
        fprintf(stderr, "FINAL???\n");
        return result;
    }

    else
    {
        assert(NULL);   // TODO
    }
}

//=======================================================

node* handle_plus_minus(list_struct* token_list)
{
    fprintf(stderr, "handle_plus_minus\t%s\n", take_str_from_node(token_list->data[cur_ind]));
    node* our_node = token_list->data[cur_ind];
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS || IS_FUNCTION)
    {
        node* result = handle_mul_div(token_list);
        fprintf(stderr, "from handle_mul_div to handle_plus_minus\t%s\n", take_str_from_node(result));
        if (cur_ind >= token_list->size - 1)
            return result;
        cur_ind++;
       // fprintf(stderr, "and2\t%s\n", take_str_from_node(token_list->data[cur_ind]));
        if (IS_PLUS || IS_MINUS)
        {
            fprintf(stderr, "we plus\n");
            our_node = token_list->data[cur_ind];
            our_node->right = result;
            cur_ind++;
            our_node->left = handle_plus_minus(token_list);
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

node* handle_mul_div(list_struct* token_list)
{
    fprintf(stderr, "handle_mul_div\t%s\n", take_str_from_node(token_list->data[cur_ind]));
    // printf("%s\n", take_str_from_node(token_list->data[cur_ind]));
    node* our_node = token_list->data[cur_ind];
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS || IS_FUNCTION)
    {
        node* result = handle_power(token_list);
         fprintf(stderr, "from handle_val_var to handle_mul_div\t%s\n", take_str_from_node(result));
        if (cur_ind >= token_list->size - 1)
            return result;
        cur_ind++;
        if (IS_MULTIPLY || IS_DIVISION)
        {
            our_node = token_list->data[cur_ind];
            our_node->right = result;
            cur_ind++;
            our_node->left = handle_mul_div(token_list);
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

node* handle_power(list_struct* token_list)
{
    fprintf(stderr, "handle_power\t%s\n", take_str_from_node(token_list->data[cur_ind]));
    node* ret_node = token_list->data[cur_ind];
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS || IS_FUNCTION)
    {
        node* result = handle_func(token_list);
        fprintf(stderr, "from 'func' to 'power'\t%s\n", take_str_from_node(token_list->data[cur_ind]));
        if (cur_ind >= token_list->size - 1)
            return result;
        cur_ind++;
        fprintf(stderr, "Next is\t%s\n", take_str_from_node(token_list->data[cur_ind]));
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
            assert(NULL);
    }
    else
    {
        assert(NULL);
    }
    return ret_node;
}

//=============================================================

node* handle_func(list_struct* token_list)
{
    fprintf(stderr, "handle_func\t%s\n", take_str_from_node(token_list->data[cur_ind]));
    node* ret_node = token_list->data[cur_ind];
    if (IS_VARYABLE || IS_VALUE || IS_OPEN_BRACKETS)
    {
        node* result = handle_val_var(token_list);
        if (cur_ind >= token_list->size - 1)
            return result;
        cur_ind++;
        fprintf(stderr, "NEXT in 'func'\t%s\n", take_str_from_node(token_list->data[cur_ind]));
        if IS_FUNCTION
        {
            ret_node = token_list->data[cur_ind];
            ret_node->right = result;
           // cur_ind++;
            double buf_value = -1;
            ret_node->left = make_node(VALUE_TYPE, &buf_value);
        }
        // else if IS_CLOSE_BRACKETS
        // {
        //     cur_ind++;
        //     if (cur_ind >= token_list->size - 1)
        //         return result;
        //     if IS_FUNCTION
        //     {
        //         ret_node = token_list->data[cur_ind];
        //         ret_node->right = result;
        //        // cur_ind++;
        //         double buf_value = -1;
        //         ret_node->left = make_node(VALUE_TYPE, &buf_value);
        //     }
        //     else
        //     {
        //         ret_node = result;
        //         cur_ind-= 2;
        //     }
        // }
        else if (IS_CLOSE_BRACKETS || IS_PLUS || IS_MINUS || IS_MULTIPLY || IS_DIVISION || IS_POWER)
        {
            ret_node = result;
            cur_ind--;
        }
        else
            assert(NULL);
    }
    else
    {
        assert(NULL);
    }
    return ret_node;
}

//=============================================================

node* handle_val_var(list_struct* token_list)
{
    fprintf(stderr, "handle_val_var\t%s\n", take_str_from_node(token_list->data[cur_ind]));
    node* buffer = NULL;
    if (IS_VALUE || IS_VARYABLE)
    {
        return token_list->data[cur_ind];
    }
    if (IS_OPEN_BRACKETS)
    {
        cur_ind++;
        buffer = handle_plus_minus(token_list);
       // fprintf(stderr, "FINAL???\n");
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
        assert(NULL);

    return buffer;
}
