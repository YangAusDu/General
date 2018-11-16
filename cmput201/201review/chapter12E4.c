#include <stdio.h>

int main(){
    char a[100];
    printf("Enter a message: ");
    int count = 0,i;
    for (;;){
        scanf("%c",&a[count]);
        if(a[count]=='\n'){
            break;
        }
        count++;
    }
    printf("the reverse order is: ");
    for (i=count;i>=0;i--){
        printf("%c",a[i]);
    }
    printf("\n");

}