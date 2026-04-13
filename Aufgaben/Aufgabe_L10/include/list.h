#ifndef LIST
#define LIST
#define MAX_VALUE 200
// Struct Value and List
typedef struct Value
{
    int value;
    struct Value *next;
} Value;
typedef struct List
{
    Value *head;
} List;
// Functions
void init_rand_time();
int init_list(List *l);
int add_value(List *l, int value);
int fill_list_random(List *l, int amount);
void cpy_list(List *newList, List *l);
void print_list(List *l);
void insertion_sort(List *l);
void quick_sort(List *l);
void delete_list(List *l);
#endif