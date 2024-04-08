#include "differentiator.h"

//===============================================

node* make_node(list_struct* values, enum operations type)
{
    node* new_node = (node*) calloc(1, sizeof(node));
    if (type == VALUE)
    {
        new_node->list = values;
    }
    else
    {
        new_node->list = make_list(LIST_LEN);
    }
    new_node->operation_type = type;


    new_node->left = NULL;
    new_node->right = NULL;
    new_node->prev = NULL;
}

//===============================================

tree* make_tree()
{
    tree* new_tree = (tree*) calloc(1, sizeof(tree));
    new_tree->root = NULL;
    new_tree->size = 0;

    return new_tree;
}

//===============================================

node* append_to_tree(tree* tree, list_struct* new_val, enum operations type, node* current_node, int indicator)
{
    node* new_node = make_node(new_val, type);
    tree->size++;

    if (tree->size == 1)
    {
        tree->root = new_node;
        return new_node;
    }

    new_node->prev = current_node;

    if (indicator == RIGHT)
    {
        current_node->right = new_node;
    }
    else if (indicator == LEFT)
    {
        current_node->left = new_node;
    }

    return new_node;
}

//=======================================================

node* insert_into_tree(tree* tree, node* new_node, node* current_node, int indicator)
{
   // node* new_node = make_node(new_val, type);
    tree->size++

    if (tree->size == 1)
    {
        tree->root = new_node;
        return new_node;
    }

    if (indicator == PREV)
    {
        if (current_node == tree->root)
        {
            new_node->left = tree->root;
            tree->root->prev = new_node;
            tree->root = new_node;
        }
        else
        {
            if (current_node->prev->left == current_node)
            {
                current_node->prev->left = new_node;
            }
            else if (current_node->prev->right == current_node)
            {
                current_node->prev->right = new_node;
            }
            current_node->prev = new_node;
        }
    }

    else if (indicator == LEFT)
    {
        new_node->left = current_node->left;
        current_node->left = new_node;
        new_node->prev = current_node;
    }

    else if (indicator == RIGHT)
    {
        new_node->right = current_node->right;
        current_node->right = new_node;
        new_node->prev = current_node;
    }

    return new_node;
}

//=======================================================

void delete_node(node* deleted_node)
{
    if (!deleted_node)
        return;

    if (deleted_node->left)
        delete_node(deleted_node->left);

    if (deleted_node->right)
        delete_node(deleted_node->right);

    if (new_node->list)
        free(new_node->list);
    free(deleted_node);
}

//==============================================

void tree_desructor(tree* deleted_tree)
{
    if (!deleted_tree)
        return

    delete_node(deleted_tree->root);
}

//===============================================

// void print_tree(Node* root, FILE* file)
// {
//     if (!root)
//     {
//         fprintf(file, "null ");
//         return;
//     }
//
//     fprintf(file, "( ");
//     fprintf(file, "\"%s\" ",root->val);
//     print_tree(root->left, file);
//     print_tree(root->right, file);
//     fprintf(file, " )");
// }

//===============================================

//
// int tree_search(Node* root, Stack* stack, char* desired)         // return deep of the element
// {
//     if (!root)
//     {
//         return VALUE_IS_NOT_FOUND;
//     }
//
//     if (strcmp(root->val, desired) == 0)
//     {
//         root->path_to_def = FOUND;
//         StackPush(stack, *root);
//         return 1;
//     }
//
//     int deep_left = TreeSearch(root->left, stack, desired);
//     if (deep_left != VALUE_IS_NOT_FOUND)
//     {
//         root->path_to_def = LEFT;
//         StackPush(stack, *root);
//         return deep_left + 1;
//     }
//
//     int deep_right = TreeSearch(root->right, stack, desired);
//     if (deep_right != VALUE_IS_NOT_FOUND)
//     {
//         root->path_to_def = RIGHT;
//         StackPush(stack, *root);
//         return deep_right + 1;
//     }
//
//     return VALUE_IS_NOT_FOUND;
// }

//=====================================================================
