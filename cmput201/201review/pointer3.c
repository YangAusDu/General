#include <stdio.h>
#define N 10
void store_ones(int a[], int number);    //functions change array but does not change variables, unless you assign a pointer to that variable and change through the pointer//
void assign(int variable);
void assign2(int *pointer);
void assign3(int variable);

int main(){
    int a[N],i,*pointer;
    int variable1 = 10;
    
    store_ones(a,N);
    while(i<N){
        printf(" %d",a[i]);
        i++;
    }
    printf("\n");
    assign(variable1);
    printf("The value of variable 1 is: %d \n",variable1);
    pointer = &variable1;
    assign2(pointer);
    printf("The value of variable 1 is: %d\n",variable1);
    assign3(variable1);
    printf("The value of variable 1 is: %d\n",variable1);
}

void store_ones(int a[], int number){
    int i;
    for (i=0;i<number;i++){
        a[i] = 1;
    }
}

void assign(int variable){
    variable = 5;
}

void assign2(int *pointer){
    *pointer = 5;
}

void assign3(int variable){
    int *pointer2;              //define the pointer inside of a function will not change the value of x//
    pointer2 = &variable;
    *pointer2 = 3;
}