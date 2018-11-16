#include <stdio.h>

#define N 10
int main(){
    int a[N],i;
    int * pointer;
    pointer = &a[0];
    for (i=0;i<N;i++){
        *(pointer+i) = i;
        printf("%d \n",a[i]);
    }
    

}