#include "differentiator.h"

double ONE2 = 1.0;
double ZERO2 = 0.0;

int new_tree_size = 0;

tree* simplify_tree(tree* handled_tree)
{
    new_tree_size = 0;
    tree* new_tree = make_tree();
    handled_tree->root = simplify(handled_tree->root);
    handled_tree->size = new_tree_size;
    return handled_tree;
}

//========================================================

node* simplify(node* handled_node)
{
    node* new_node = NULL;
    if (NODE_IS_VALUE(handled_node) || NODE_IS_VARYABLE(handled_node))
    {
        new_tree_size++;
        return copy_node(handled_node);
    }
    node* left_node = simplify(handled_node->left);
    node* right_node = simplify(handled_node->right);

    if NODE_IS_ZERO(left_node)
    {
        new_node = optimizate_if_left_zero(handled_node, right_node);
        if (new_node)
            return new_node;
    }
    if NODE_IS_ZERO(right_node)
    {
        new_node = optimizate_if_right_zero(handled_node, left_node);
        if (new_node)
            return new_node;
    }

    if (NODE_IS_VALUE(left_node) && NODE_IS_VALUE(right_node))
    {
        new_tree_size--;
        return do_operation(handled_node, left_node, right_node);
    }
    new_node = copy_node(handled_node);
    new_node->left = left_node;
    new_node->right = right_node;
    new_tree_size++;
    return new_node;
}

//========================================================

node* do_operation(node* oper_node, node* left_node, node* right_node)
{
    node* new_node = copy_node(left_node);
    switch (oper_node->content.token)
    {
        case ADD:
            new_node->content.value += right_node->content.value;
            break;
        case SUBTRACT:
            new_node->content.value -= right_node->content.value;
            break;
        case MULTIPLY:
            new_node->content.value *= right_node->content.value;
            break;
        case DIVISION:
            new_node->content.value /= right_node->content.value;
            break;
        case POWER:
            new_node->content.value = pow(new_node->content.value, right_node->content.value);
            break;
        case COS:
            new_node->content.value = cos(right_node->content.value);
            break;
        case SIN:
            new_node->content.value = sin(right_node->content.value);
            break;
        case TAN:
            new_node->content.value = tan(right_node->content.value);
            break;
        case CTAN:
            new_node->content.value = 1/tan(right_node->content.value);
            break;
        case LN:
            new_node->content.value = log(right_node->content.value);
            break;
        default:
            assert(NULL);
    }
    return new_node;
}

//=====================================================

node* optimizate_if_left_zero(node* oper_node, node* right_node)
{
    switch (oper_node->content.token)
    {
        case ADD:
            return right_node;
        case MULTIPLY:
        case DIVISION:
        case POWER:
            return make_node(VALUE_TYPE, &ZERO2);

        default:
            return NULL;
    }
}

//=======================================================

node* optimizate_if_right_zero(node* oper_node, node* left_node)
{
    switch (oper_node->content.token)
    {
        case ADD:
            return left_node;
        case SUBTRACT:
            return left_node;
        case MULTIPLY:
            return make_node(VALUE_TYPE, &ZERO2);
        case DIVISION:
            assert(NULL);
        case POWER:
            return make_node(VALUE_TYPE, &ONE2);
        default:
            return NULL;
    }
}

//============================================================
