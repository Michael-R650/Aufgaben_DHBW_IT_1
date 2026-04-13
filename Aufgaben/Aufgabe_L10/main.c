#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/list.h"

int main()
{
    double time_ins = 0;
    double time_quick = 0;
    clock_t start_t, end_t;
    init_rand_time();
    List nr1;
    List nr2;
    List nr3;
    init_list(&nr1);
    init_list(&nr2);
    init_list(&nr3);
    fill_list_random(&nr1, 200000);
    cpy_list(&nr2, &nr1);
    cpy_list(&nr3, &nr1);
    //printf("Unsortiert:\n");
    //print_list(&nr1);
    //print_list(&nr2);
    //print_list(&nr3);
    start_t = clock();
    quick_sort(&nr2);
    end_t = clock();
    time_quick=(double)(end_t-start_t)/CLOCKS_PER_SEC;
    start_t = clock();
    insertion_sort(&nr3);
    end_t = clock();
    time_ins=(double)(end_t-start_t)/CLOCKS_PER_SEC;
    //printf("Sortiert:\n");
    //print_list(&nr2);
    //print_list(&nr3);
    printf("Time Inseration:%f S\n",time_ins);
    printf("Time Quicksort:%f S\n",time_quick);
    delete_list(&nr1);
    delete_list(&nr2);
    delete_list(&nr3);
    
    return 0;
}