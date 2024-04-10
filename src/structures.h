enum tokens
{
    OPENING_BR,
    CLOSING_BR,
    POWER,
    MULTIPLY,
    DIVISION,
    ADD,
    SUBTRACT,
    COS,
    SIN,
    TAN,
    CTAN,
    LN,
    UNKNOWN
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
