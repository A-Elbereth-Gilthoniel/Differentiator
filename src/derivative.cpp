#include "differentiator.h"

double ONE = 1.0;
double M_ONE = -1.0;
double ZERO = 0.0;
double TWO = 2.0;

tree* take_tree_of_derivative(tree* handled_tree)
{
    tree* new_tree = make_tree();
    handled_tree->root = take_derivative(handled_tree->root);
    handled_tree->size = handled_tree->size;
    return handled_tree;
}

//=====================================================

node* take_derivative(node* handled_node)
{
    if (NODE_IS_VALUE(handled_node))
    {
        return make_node(VALUE_TYPE, &ZERO);
    }
    if NODE_IS_VARYABLE(handled_node)
    {
        return make_node(VALUE_TYPE, &ONE);
    }

    return do_der_oper(handled_node);
}

//===========================================================

node* do_der_oper(node* oper_node)
{
    enum tokens div_tok = DIVISION, sub_tok = SUBTRACT, mul_tok = MULTIPLY, pow_tok = POWER, cos_tok = COS, sin_tok = SIN, ln_tok = LN;
    node* new_node = copy_node(oper_node);
    node* left_node = NULL;
    node* right_node = NULL;
    node* buffer_node = NULL;
    switch (oper_node->content.token)
    {
        case ADD:
            new_node->left = take_derivative(oper_node->left);
            new_node->right = take_derivative(oper_node->right);
            break;
        case SUBTRACT:
            new_node->left = take_derivative(oper_node->left);
            new_node->right = take_derivative(oper_node->right);
            break;
        case MULTIPLY:
            new_node = get_der_mul(oper_node);
            break;
        case DIVISION:
            new_node = make_node(OPER_TYPE, &div_tok);

            left_node = make_node(OPER_TYPE, &sub_tok);
            left_node->left = make_node(OPER_TYPE, &mul_tok);
            left_node->right = make_node(OPER_TYPE, &mul_tok);
            left_node->left->right = copy_node(oper_node->right);
            left_node->left->left = take_derivative(oper_node->left);
            left_node->right->left = copy_node(oper_node->left);
            left_node->right->right = take_derivative(oper_node->right);
            new_node->left = copy_node(left_node);

            right_node = make_node(OPER_TYPE, &pow_tok);
            right_node->left = copy_node(oper_node->right);
            right_node->right = make_node(VALUE_TYPE, &TWO);
            new_node->right = copy_node(right_node);

            break;
        case POWER:
            new_node = make_node(OPER_TYPE, &mul_tok);
            new_node->left = copy_node(oper_node);
            buffer_node = make_node(OPER_TYPE, &mul_tok);
            buffer_node->left = copy_node(oper_node->right);
           // buffer_node->right = get_der_log(oper_node->left);
            buffer_node->right = make_node(OPER_TYPE, &ln_tok);
            buffer_node->right->left = make_node(VALUE_TYPE, &M_ONE);
            buffer_node->right->right = copy_node(oper_node->left);
            new_node->right = get_der_mul(buffer_node);
            break;
        case COS:
            new_node = make_node(OPER_TYPE, &mul_tok);
            new_node->right = take_derivative(oper_node->right);
            //left_node = new_node->left;
            left_node = make_node(OPER_TYPE, &mul_tok);
            left_node->left = make_node(VALUE_TYPE, &M_ONE);
            left_node->right = make_node(OPER_TYPE, &sin_tok);
            left_node->right->left = make_node(VALUE_TYPE, &M_ONE);
            left_node->right->right = copy_node(oper_node->right);
            new_node->left = copy_node(left_node);
            break;
        case SIN:
            new_node = make_node(OPER_TYPE, &mul_tok);
            new_node->left = make_node(OPER_TYPE, &cos_tok);
            new_node->left->left = make_node(VALUE_TYPE, &M_ONE);
            new_node->left->right = copy_node(oper_node->right);

            new_node->right = take_derivative(oper_node->right);
            break;
        case TAN:
            new_node = make_node(OPER_TYPE, &mul_tok);
            new_node->right = take_derivative(oper_node->right);
            new_node->left = make_node(OPER_TYPE, &div_tok);
            new_node->left->left = make_node(VALUE_TYPE, &ONE);
            new_node->left->right = make_node(OPER_TYPE, &pow_tok);
            new_node->left->right->right = make_node(VALUE_TYPE, &TWO);
            new_node->left->right->left = make_node(OPER_TYPE, &cos_tok);
            new_node->left->right->left->left = make_node(VALUE_TYPE, &M_ONE);
            new_node->left->right->left->right = copy_node(oper_node->right);
            break;
        case CTAN:
            new_node = make_node(OPER_TYPE, &mul_tok);
            new_node->right = take_derivative(oper_node->right);
            new_node->left = make_node(OPER_TYPE, &mul_tok);
            new_node->left->left = make_node(VALUE_TYPE, &M_ONE);
            buffer_node = make_node(OPER_TYPE, &div_tok);
            buffer_node->left = make_node(VALUE_TYPE, &ONE);
            buffer_node->right = make_node(OPER_TYPE, &pow_tok);
            buffer_node->right->right = make_node(VALUE_TYPE, &TWO);
            buffer_node->right->left = make_node(OPER_TYPE, &sin_tok);
            buffer_node->right->left->left = make_node(VALUE_TYPE, &M_ONE);
            buffer_node->right->left->right = copy_node(oper_node->right);
            new_node = buffer_node;
            break;
        case LN:
            new_node = get_der_log(oper_node->right);
            break;
        default:
            assert(NULL);
    }
    return new_node;
}

//===========================================================

node* get_der_mul(node* oper_node)
{
    enum tokens mul_tok = MULTIPLY, add_tok = ADD;
    node* new_node = make_node(OPER_TYPE, &add_tok);
    new_node->left = make_node(OPER_TYPE, &mul_tok);
    new_node->right = make_node(OPER_TYPE, &mul_tok);
    new_node->left->right = copy_node(oper_node->right);
    new_node->left->left = take_derivative(oper_node->left);
    new_node->right->left = copy_node(oper_node->left);
    new_node->right->right = take_derivative(oper_node->right);
    return new_node;
}

//===========================================================

node* get_der_log(node* oper_node)
{
    enum tokens mul_tok = MULTIPLY, div_tok = DIVISION;
    node* new_node = make_node(OPER_TYPE, &mul_tok);
    new_node->left = make_node(OPER_TYPE, &div_tok);
    new_node->left->left = make_node(VALUE_TYPE, &ONE);
    new_node->left->right = copy_node(oper_node);
    new_node->right = take_derivative(oper_node);
    return new_node;
}

//==========================================================

void take_n_derivatives(tree* token_tree, int derivative_qty)
{
    tree* token_tree2 = simplify_tree(token_tree);
   // add_tex_file(start_str, rand() % 12 + 1);
    draw_graph(token_tree2, "Tree_graph2.dot");
    char start_str[1000];
    handle_operation(token_tree2->root, start_str);
    add_tex_file(start_str, rand() % 12 + 1);

    for (int i = 1; i < derivative_qty; i++)
    {
        token_tree2 = take_tree_of_derivative(token_tree2);
        token_tree2 = simplify_tree(token_tree2);
        handle_operation(token_tree2->root, start_str);
        add_tex_file(start_str, rand() % 12 + 1);
    }
}
