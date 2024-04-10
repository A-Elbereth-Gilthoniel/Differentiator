
// indicators for 'tree'
#define LEFT    -1
#define PREV    0
#define RIGHT   1

#define FILE_REPOSITORY "./files/"

// structures.h (23 LINE)- 'int type' in 'node'
#define OPER_TYPE       0
#define VALUE_TYPE      1
#define VARYABLE_TYPE   2

// list.cpp (main settings of struct 'list')
#define TYPE_LIST       node*
#define LIST_LEN        10

// list.cpp, function 'search_elem_in_list' (LINE 78)
#define STRAIGHT    1
#define BACK        -1

#define ELEM_NOT_FOUND -2

// stack.cpp
#define STACK_LEN 8

// structures.h (LINE 22) - 'status'
#define IN_BRACKETS     1
#define NOT_IN_BRACKETS -1

// analysis.cpp - function 'parsing' (LINE 60)
#define IS_OPEN_BRACKETS    (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == OPENING_BR)
#define IS_CLOSE_BRACKETS   (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == CLOSING_BR)
#define IS_PLUS             (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == ADD)
#define IS_MINUS            (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == SUBTRACT)
#define IS_MULTIPLY         (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == MULTIPLY)
#define IS_DIVISION         (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == DIVISION)
#define IS_POWER            (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == POWER)
#define IS_COS              (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == COS)
#define IS_SIN              (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == SIN)
#define IS_TAN              (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == TAN)
#define IS_CTAN             (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == CTAN)
#define IS_LN               (token_list->data[cur_ind]->type == OPER_TYPE && token_list->data[cur_ind]->content.token == LN)
#define IS_VALUE            (token_list->data[cur_ind]->type == VALUE_TYPE)
#define IS_VARYABLE         (token_list->data[cur_ind]->type == VARYABLE_TYPE)
#define IS_FUNCTION         (IS_COS || IS_SIN || IS_TAN || IS_CTAN || IS_LN)

#define NOT_FOUND -1

// optimization.cpp
#define NODE_IS_PLUS(NODE)             (NODE->type == OPER_TYPE && NODE->content.token == ADD)
#define NODE_IS_MINUS(NODE)            (NODE->type == OPER_TYPE && NODE->content.token == SUBTRACT)
#define NODE_IS_MULTIPLY(NODE)         (NODE->type == OPER_TYPE && NODE->content.token == MULTIPLY)
#define NODE_IS_DIVISION(NODE)         (NODE->type == OPER_TYPE && NODE->content.token == DIVISION)
#define NODE_IS_POWER(NODE)            (NODE->type == OPER_TYPE && NODE->content.token == POWER)
#define NODE_IS_COS(NODE)              (NODE->type == OPER_TYPE && NODE->content.token == COS)
#define NODE_IS_SIN(NODE)              (NODE->type == OPER_TYPE && NODE->content.token == SIN)
#define NODE_IS_TAN(NODE)              (NODE->type == OPER_TYPE && NODE->content.token == TAN)
#define NODE_IS_CTAN(NODE)             (NODE->type == OPER_TYPE && NODE->content.token == CTAN)
#define NODE_IS_LN(NODE)               (NODE->type == OPER_TYPE && NODE->content.token == LN)
#define NODE_IS_VALUE(NODE)            (NODE->type == VALUE_TYPE)
#define NODE_IS_VARYABLE(NODE)         (NODE->type == VARYABLE_TYPE)
#define NODE_IS_ZERO(NODE)             (NODE->type == VALUE_TYPE && cmp_with_number(NODE->content.value, (double)0))

