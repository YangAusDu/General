#include <stdio.h>
#include "insertion_sort.h"

void insertion_sort(int a[], int length){
   if (length <= 1){
       return;
   }
   insertion_sort(a,length-1);
   int last = a[length - 1];
   int index = length - 2;

   while(index >= 0 && a[index] > last){
       a[index+1] = a[index];
       index--;
   }
   a[index+1] = last;
}



