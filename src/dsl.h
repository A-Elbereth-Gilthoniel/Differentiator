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
#define IS_VALUE            (token_list->data[cur_ind]->type == VALUE_TYPE)
#define IS_VARYABLE         (token_list->data[cur_ind]->type == VARYABLE_TYPE)

#define NOT_FOUND -1
