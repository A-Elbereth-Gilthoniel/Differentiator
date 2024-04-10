#include "differentiator.h"

//========================================================

int index = 0;

//========================================================

list_struct* lexical_analysis(char* str)
{
    list_struct* token_list = make_list(LIST_LEN);
    index = 0;
    while (str[index] != '\0')
    {
        node* new_node = encode(str);
        append_to_list(token_list, new_node);
        index++;
    }
    return token_list;
}

//=========================================================

node* encode(char* str)
{
    double value = 0;

    if ('0' <= str[index] && str[index] <= '9')
    {
        value = get_value(str);
        return make_node(VALUE_TYPE, &value);
    }

    node* func = check_func(str);
    if (func)
        return func;

    if ('a' <= str[index] && str[index] <= 'z')
    {
        return make_node(VARYABLE_TYPE, &str[index]);
    }
    enum tokens right_token = UNKNOWN;

    switch(str[index])
    {
        case '+':
            right_token = ADD;
            return make_node(OPER_TYPE, &right_token);
        case '-':
            right_token = SUBTRACT;
            return make_node(OPER_TYPE, &right_token);
        case '*':
            right_token = MULTIPLY;
            return make_node(OPER_TYPE, &right_token);
        case '/':
            right_token = DIVISION;
            return make_node(OPER_TYPE, &right_token);
        case '^':
            right_token = POWER;
            return make_node(OPER_TYPE, &right_token);
        case '(':
            // right_token = OPENING_BR;
            right_token = CLOSING_BR;
            return make_node(OPER_TYPE, &right_token);
        case ')':
            // right_token = CLOSING_BR;
            right_token = OPENING_BR;
            return make_node(OPER_TYPE, &right_token);
        default:
            return make_node(OPER_TYPE, &right_token);
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
    index--;
    return value;
}

//=========================================================

node* check_func(char* str)
{
    enum tokens right_token = UNKNOWN;
    if (strncmp(&str[index], "cos", 3) == 0)
    {
        index += 2;
        right_token = COS;
        return make_node(OPER_TYPE, &right_token);
    }
    if (strncmp(&str[index], "sin", 3) == 0)
    {
        index+= 2;
        right_token = SIN;
        return make_node(OPER_TYPE, &right_token);
    }
    if (strncmp(&str[index], "tg", 2) == 0)
    {
        index++;
        right_token = TAN;
        return make_node(OPER_TYPE, &right_token);
    }
    if (strncmp(&str[index], "ctg", 3) == 0)
    {
        index+= 2;
        right_token = CTAN;
        return make_node(OPER_TYPE, &right_token);
    }
    if (strncmp(&str[index], "ln", 2) == 0)
    {
        index++;
        right_token = LN;
        return make_node(OPER_TYPE, &right_token);
    }
    return NULL;
}
