#include "differentiator.h"

enum operations
{
    VALUE = 0,
    OPENING_BR = 1,
    CLOSING_BR = 2,
    POWER = 3,
    MULTIPLY = 4,
    DIVISION = 5,
    ADD = 6,
    SUBTRACT = 7,
    UNKNOWN = 8
};

typedef struct {
    double* data;
    int capacity;
    int size;
} list_struct;

typedef struct node {
    list_struct* list;
    enum operations operation_type;
    struct node* left;
    struct node* right;
    struct node* prev;
} node;

typedef struct {
    node* root;
    int size;
} tree;

// typedef struct {
//     stack_t* data;
//     int size;
//     int capacity;
// } stack;
