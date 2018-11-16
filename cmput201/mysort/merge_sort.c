 
 #include <stdio.h>
 #include "merge_sort.h"
 
 
void merge_sort(int array[], int left, int right){
    int middle;
    middle = left + (right - left)/2;
    if (left >=  right){
        return;
    }
    merge_sort(array, left, middle);
    merge_sort(array, middle+1, right);
    merge(array, left, middle, middle+1, right);
}

void merge(int a[], int left1, int right1, int left2,int right2){
    int size = right2-left1+1;
    int start = left1;
    int temp[size];
    for(int i=0; i < size; i++)
    {
        if(left1 > right1)
        {
            temp[i] = a[left2++];
        }
        //
        else if(left2 > right2)
        {
            temp[i] = a[left1++];
        }
        else if(a[left1] <= a[left2])
            temp[i] = a[left1++];
        else
            temp[i] = a[left2++];
    }
    for(int i=0; i< size; i++)
        a[i+start] = temp[i];
}