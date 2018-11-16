#include <stdio.h>
#include "bubble_sort.h"
#include "util.h"

void bubble_sort(int array[], int start, int end){
    if (start==end){
        return;
    }
    int index ;
    for (index = 0; index < end; index++){
        if (array[index]>array[index+1]){
            swap(array ,index, index+1);
        }
    }
    bubble_sort(array ,start ,end - 1);
}



