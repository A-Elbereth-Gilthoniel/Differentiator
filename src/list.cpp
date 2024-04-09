#include "differentiator.h"

//===================================================

list_struct* make_list(int length)
{
    list_struct* new_list = (list_struct*) calloc(1, sizeof(list_struct));
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
    TYPE_LIST buffer = 0;
    list->size++;
    if (list->size == list->capacity)
    {
        list_realloc(list, list->capacity * 2);
    }
    for (int i = index + 1; i < list->size; i++)
    {
        buffer = list->data[i];
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = value;
}

//===============================================

void remove_from_list(list_struct* list, int index)
{
    list->size--;
    for (int i = index; i < list->size; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->data[list->size] = NULL;

    if (list->size < list->capacity / 3)
    {
        list_realloc(list, list->capacity / 3);
    }
}

//===============================================

void destruct_list(list_struct* list)
{
    for (int i = 0; i < list->size; i++)
        delete_node(list->data[i]);

    free(list->data);
    free(list);
}

//===============================================

void print_list(list_struct* list)
{
    for (int i = 0; i < list->size; i++)
    {
        fprintf(stdout, "%.2lf ", list->data[i]->content.value);
    }
    fprintf(stdout, "\n");
}

//===============================================

// int search_elem_in_list(list_struct* list, node* elem, int direction)
// {
//     int start_i = 0, finish_i = 0, supple = 0;
//     if (direction == STRAIGHT)
//     {
//         start_i = 0;
//         finish_i = list->size - 1;
//         supple = 1;
//     }
//     else if (direction == BACK)
//     {
//         start_i = list->size - 1;
//         finish_i = 0;
//         supple = -1;
//     }
//     for (int i = start_i; i != finish_i; i += supple)
//     {
//         if (list->data[i]->type == elem->type && cmp_with_number(list->data[i]->content.value, elem->content.value))
//         {
//             return i;
//         }
//     }
//     return ELEM_NOT_FOUND;
// }

//===============================================

list_struct* cut_from_list(list_struct* copied_list, int start_i, int finish_i)
{
    list_struct* new_list = make_list((finish_i - start_i) * 2);
    for (int i = start_i; i <= finish_i; i++)
    {
        append_to_list(new_list, copied_list->data[start_i]);
        remove_from_list(copied_list, start_i);
    }
    return new_list;
}
