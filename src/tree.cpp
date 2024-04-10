#include "differentiator.h"

//===============================================

node* make_node(int type, void* content)
{
    node* new_node = (node*) calloc(1, sizeof(node));
    new_node->type = type;
    if (type == VALUE_TYPE)
        new_node->content.value = *(double*)(content);
    else if (type == VARYABLE_TYPE)
        new_node->content.variable = *(char*)(content);
    else if (type == OPER_TYPE)
        new_node->content.token = *(enum tokens*)(content);
   // printf("%d\n", (int)new_node->content.token);

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->prev = NULL;
}

//===============================================

node* copy_node(node* copied_node)
{
    node* new_node = (node*) calloc(1, sizeof(node));
    new_node->type = copied_node->type;
    if (copied_node->type == VALUE_TYPE)
        new_node->content.value = copied_node->content.value;
    else if (copied_node->type == VARYABLE_TYPE)
        new_node->content.variable = copied_node->content.variable;
    else if (copied_node->type == OPER_TYPE)
        new_node->content.token = copied_node->content.token;
    if (copied_node->left)
    {
        new_node->left = copy_node(copied_node->left);
    }
    if (copied_node->right)
    {
        new_node->right = copy_node(copied_node->right);
    }
    // new_node->left = NULL;
    // new_node->right = NULL;
    // new_node->prev = NULL;
    return new_node;
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

node* append_to_tree(tree* tree, node* new_node, node* current_node, int indicator)
{
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

// node* insert_into_tree(tree* tree, node* new_node, node* current_node, int indicator)
// {
//    // node* new_node = make_node(new_val, type);
//     tree->size++
//
//     if (tree->size == 1)
//     {
//         tree->root = new_node;
//         return new_node;
//     }
//
//     if (indicator == PREV)
//     {
//         if (current_node == tree->root)
//         {
//             new_node->left = tree->root;
//             tree->root->prev = new_node;
//             tree->root = new_node;
//         }
//         else
//         {
//             if (current_node->prev->left == current_node)
//             {
//                 current_node->prev->left = new_node;
//             }
//             else if (current_node->prev->right == current_node)
//             {
//                 current_node->prev->right = new_node;
//             }
//             current_node->prev = new_node;
//         }
//     }
//
//     else if (indicator == LEFT)
//     {
//         new_node->right = current_node->left;
//         current_node->left = new_node;
//         new_node->prev = current_node;
//     }
//
//     else if (indicator == RIGHT)
//     {
//         new_node->left = current_node->right;
//         current_node->right = new_node;
//         new_node->prev = current_node;
//     }
//
//     return new_node;
// }

//=======================================================

void delete_node(node* deleted_node)
{
    if (!deleted_node)
        return;

    if (deleted_node->left)
        delete_node(deleted_node->left);

    if (deleted_node->right)
        delete_node(deleted_node->right);

    free(deleted_node);
}

//==============================================

void destruct_tree(tree* deleted_tree)
{
    if (!deleted_tree)
        return

    delete_node(deleted_tree->root);
}

//===============================================
char str2[20];

char* take_str_from_node(node* cur_node)
{
    switch (cur_node->type)
    {
        case OPER_TYPE:
            return decode_operation(cur_node);
        case VALUE_TYPE:
            sprintf(str2, "%.2lf", cur_node->content.value);
            return str2;
        case VARYABLE_TYPE:
            return &cur_node->content.variable;
    }
}

//================================================

char* decode_operation(node* cur_node)
{
    switch (cur_node->content.token)
    {
        case ADD:
            return (char*)"+";
        case SUBTRACT:
            return (char*)"-";
        case MULTIPLY:
            return (char*)"*";
        case DIVISION:
            return (char*)"/";
        case POWER:
            return (char*)"^";
        case COS:
            return (char*)"cos";
        case SIN:
            return (char*)"sin";
        case TAN:
            return (char*)"tg";
        case CTAN:
            return (char*)"ctg";
        case LN:
            return (char*)"ln";
        case OPENING_BR:
            return (char*)"(";
        case CLOSING_BR:
            return (char*)")";
        default:
            return (char*)"hui";
    }
}
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

