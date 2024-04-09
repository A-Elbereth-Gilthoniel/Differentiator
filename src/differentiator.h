#include "libr.h"
#include "dsl.h"
#include "structures.h"


// file.cpp
char* read_file(char* file_name, size_t* symbols_num);
void file_validation(char* file_name);
size_t find_file_size(FILE* fp);
// string.cpp
int delete_n_and_r(char* str);
// list.cpp
list_struct* make_list(int length);
void list_realloc(list_struct* list, int new_capacity);
void append_to_list(list_struct* list, TYPE_LIST value);
void insert_into_list(list_struct* list, TYPE_LIST value, int index);
void destruct_list(list_struct* list);
void print_list(list_struct* list);
int search_elem_in_list(list_struct* list, node* elem, int direction);
list_struct* cut_from_list(list_struct* copied_list, int start_i, int finish_i);
void remove_from_list(list_struct* list, int index);
// tree.cpp
node* make_node(int type, void* content);
tree* make_tree();
node* append_to_tree(tree* tree, node* new_node, node* current_node, int indicator);
void delete_node(node* deleted_node);
void destruct_tree(tree* deleted_tree);
char* decode_operation(node* cur_node);
char* take_str_from_node(node* cur_node);
// checking_values.cpp
int cmp_with_number(double number1, double number2);
// stack.cpp
stack* make_stack(int length);
void push_stack(stack* st, int value);
void destruct_stack(stack* st);
int pop_stack(stack* st);
void print_stack(stack* st);
void realloc_stack(stack *st, int new_capacity);
char* stack_verification(stack *st);
// graph.cpp
void draw_graph(tree* cur_tree);
void print_node_in_graph(FILE* fp, node* cur_node);
void print_edge_in_graph(FILE* fp, node* cur_node);
// lex_analysis.cpp
list_struct* lexical_analysis(char* str);
node* encode(char* str);
double get_value(char* str);
// parser.cpp
tree* parsing(list_struct* token_list);
node* stmt(list_struct* token_list);
node* expr(list_struct* token_list);
node* term(list_struct* token_list);
node* fact(list_struct* token_list);
