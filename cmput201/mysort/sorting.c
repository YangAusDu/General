#include "sorting.h"

int main(){
    int num_int;
    printf("Enter the number of integers: ");
    scanf("%d",&num_int);
    int array[num_int] ,array1[num_int] ,array2[num_int] ,array3[num_int] ,array4[num_int];
    printf("Enter the %d integers to be sorted: ", num_int);
    int i;
    for (i = 0; i< num_int; i++){
        scanf("%d",&array[i]);
        array1[i] = array2[i] = array3[i] =array4[i]= array[i];
    }

    bubble_sort(array1,0,num_int-1);
    printf("the bubble_sorted order is: ");
    print_array(array1,num_int);

    selectionsort(array2,0,num_int-1);
    printf("the selection_sorted order is: ");
    print_array(array2,num_int);

    merge_sort(array3,0,num_int-1);
    printf("the merge_sorted order is: ");
    print_array(array3,num_int);

    insertion_sort(array4,num_int);
    printf("the insertion_sorted order is: ");
    print_array(array4,num_int);
    
    return 0;
}

