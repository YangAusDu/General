#include "util.h"
#include <stdio.h>
void swap(int array[], int first_index, int second_index){
    int temp;
    temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
}

void print_array(int array[],int num_int){
    int j;
    for (j = 0; j< num_int; j++){
        printf("%d ", array[j]);
    }
    printf("\n");
}