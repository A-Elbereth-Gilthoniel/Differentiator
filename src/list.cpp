#include "differentiator.h"

#define TYPE_LIST double

list_struct* make_list(int length)
{
    list_struct* new_list = (list_struct*) calloc(1, sizeof(list));
    new_list->capacity = length;
    new_list->size = 0;
    new_list->data = (TYPE_LIST*) calloc(length, sizeof(TYPE_LIST));
}

//===================================================

void list_realloc(list_struct* list, int new_capacity)
{
    list->data = (TYPE_LIST*) realloc(list->data, new_capacity * sizeof(TYPE_LIST));

    memset(list->data + list->capacity, 0, (new_capacity - list->capacity) * sizeof (TYPE_LIST));

    list->capacity = new_capacity;
}

//===================================================

void append_to_list(list_struct* list, TYPE_LIST value)
{
    if (list->size == list->capacity)
    {
        list_realloc(list, list->capacity * 2);
    }
    list->data[list->size] = value;
    list->size++;
}

//===================================================

void insert_into_list(list_struct* list, TYPE_LIST value, int index)
{
    double buffer = 0;
    if (list->size == list->capacity)
    {
        list_realloc(list, list->capacity * 2);
    }
    for (int i = index + 1; i <= list->size; i++)
    {
        buffer = list->data[i];
        list->data[i] = list->data[i - 1]
    }
    list->data[index] = value;
    list->size++;
}

//===============================================

void destruct_list(list_struct* list)
{
    free(list->data);
    free(list);
}

//===============================================

void print_list(list_struct* list)
{
    for (int i = 0; i < list->size; i++)
    {
        fprintf(stdin, "%.2lf ", list->data[i]);
    }
    fprintf(stdin, "\n");
}
