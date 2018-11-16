#include <stdio.h>


void change_x(int * pointer);

void change_x(int * pointer){
    * pointer = 2; 
}

int main(){
    int x, *pointer;
    x = 0;
    pointer = &x;
    change_x(pointer);
    printf("the value is %d\n",x);
}