enum tokens
{
    OPENING_BR = 1,
    CLOSING_BR = 2,
    POWER = 3,
    MULTIPLY = 4,
    DIVISION = 5,
    ADD = 6,
    SUBTRACT = 7,
    UNKNOWN = 8
};

union node_data {
    double value;
    enum tokens token;
    char variable;
};

typedef struct node {
    union node_data content;
    int type;
    int status = NOT_IN_BRACKETS;
    struct node* left;
    struct node* right;
    struct node* prev;
} node;

typedef struct {
    TYPE_LIST* data;
    int capacity;
    int size;
} list_struct;

typedef struct {
    node* root;
    int size;
} tree;

typedef struct stack {
    int* data;
    int size;
    int capacity;
} stack;
