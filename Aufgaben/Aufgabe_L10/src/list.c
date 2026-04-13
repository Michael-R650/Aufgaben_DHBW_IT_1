#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/list.h"
void init_rand_time()
{
    srand(time(NULL));
}

int init_list(List *l)
{
    l->head = NULL;
    return 0;
}
int add_value(List *p, int value)
{
   Value *newValue = malloc(sizeof(Value));
    if (newValue == NULL)
    {
        return 1;
    }
    newValue->value = value;
    newValue->next = NULL;
    if (p->head == NULL)
    {
        p->head = newValue;
    }
    else
    {
        Value *temp = p->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newValue;
    }
    return 0;
}

int fill_list_random(List *l, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        add_value(l, (rand()%MAX_VALUE));
    }
    return 0;
}
void cpy_list(List *newList, List *l)
{
    Value *temp = l->head;
    Value *temp2 = newList->head;
    if (temp == NULL)
    {
        printf("No List avaliable\n");
    }
    
    if (newList == l)
    {
        printf("Same List");
    }
    while (temp != NULL)
    {
        add_value(newList, temp->value);
        temp = temp->next;
    }
}
void print_list(List *l)
{
    Value *temp = l->head;
    while (temp != NULL)
    {
        printf("%d, ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
void insertion_sort(List *l) {
    if (l->head == NULL) return;

    Value *i, *j;
    for (i = l->head->next; i != NULL; i = i->next) {
        int key = i->value;
        // Wir suchen rückwärts (simuliert), indem wir von vorne prüfen
        Value *temp = l->head;
        while (temp != i) {
            if (temp->value > key) {
                // Tausche Werte
                int swap = temp->value;
                temp->value = key;
                key = swap;
            }
            temp = temp->next;
        }
        i->value = key;
    }
}
void quick_sort(List *l) { // Ich nenne ihn so, damit du deine main nicht ändern musst
    if (l->head == NULL) return;
    int swapped;
    Value *ptr1;
    Value *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = l->head;

        while (ptr1->next != lptr) {
            if (ptr1->value > ptr1->next->value) { 
                // Nur Werte tauschen!
                int temp = ptr1->value;
                ptr1->value = ptr1->next->value;
                ptr1->next->value = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void delete_list(List *l){
    if(l== NULL){
        return;
    }
    Value *current = l->head;
    Value *next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    l->head = NULL;
}