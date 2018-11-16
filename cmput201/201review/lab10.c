#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define WORD_LEN 20

int read_line(char str[], int n);

int main(){
    char *array[10];
    int count = 0;
    for(;;){
        char word_str[WORD_LEN+1];
        printf("Enter the word: ");
        read_line(word_str,WORD_LEN);
        printf("%s\n",word_str);
        if (word_str[0] == '\0'){
            break;
        }
        *(array + count) = word_str;
        count++;
    }

    return 0;
    
    
}

int read_line(char str[], int n){
    char ch;
    int i = 0;

    while ((ch=getchar())!= '\n'){
        if (i < n){
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}
