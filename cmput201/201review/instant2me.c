#include <stdio.h>

void merge_sort(int array[], int left, int right);
void merge(int array[], int left1, int right1, int left2, int right2);
void Merge(int array[], int left1, int right1, int left2, int right2);

int main(){
    int num_int;
    printf("Enter the number of integers: ");
    scanf("%d",&num_int);
    int array[num_int];
    printf("ENter the %d integers to be sorted: ", num_int);
    int i;
    for (i = 0; i< num_int; i++){
        scanf("%d",&array[i]);
    }
    merge_sort(array,0,num_int-1);
    printf("the sorted order is: ");
    int j;
    for (j = 0; j< num_int; j++){
        printf("%d ", array[j]);
    }
    printf("\n");

    return 0;
}

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

//
void merge(int a[], int left1, int right1, int left2,int right2)
{
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