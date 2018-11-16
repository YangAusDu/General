
#include<stdio.h>
#include "selection_sort.h"
#include "util.h"

void selectionsort(int a[], int left, int right) {
	if (left == right){
		return;
	}
	int index = left;
	while(index <= right){
        if (a[index] < a[left]){
            swap(a,left,index);
            index ++;
        }
        else{
            index++;
        }
    }
    selectionsort(a,left+1,right);
    
}

