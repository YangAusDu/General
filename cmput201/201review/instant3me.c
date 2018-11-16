#include <stdio.h>
#include<stdlib.h>

int get_size(float input_number);
int convert_int(int integer_part,char binary[]);
void convert_frac(float float_part, char binary[], int count, int size);


int main(){
    float input_number;
    int integer_part,count;
    float float_part;
    printf("Enter the number : ");
    scanf("%f",&input_number);
    integer_part = (int)input_number;
    float_part = input_number - integer_part;
    int size = get_size(input_number);
    char binary[size];
    count = convert_int( integer_part, binary);
    convert_frac(float_part,binary, count, size);
    printf("the binary form of this number is %s\n",binary);
    return 0;
}

int get_size(float input_number){
    int count = 0;
    while (input_number < 1){
        input_number *= 2;
        count++;
    }
    return count+26;
}

int convert_int (int integer_part, char binary[]){
    int count = 0, i;
    char temp[26];
    if (integer_part == 0 ){
        binary[0] = '0';
        binary[1] = '.';
        return 2;
    }
    while (integer_part >= 1){
        if (integer_part%2 == 1){
            temp[count++] = '1';
        }
        else{
            temp[count++] = '0';
        }
        integer_part /= 2;
    }
    for (i = 0; i < count;i++){
        binary[i] = temp[count-1-i];
    }
    binary[count] = '.';
    return count+1;
}

void convert_frac(float float_part, char binary[], int count, int size){
    while (float_part > 0 && count < size-1){
        float_part *= 2;
        if (float_part >= 1 ){
            binary[count++] = '1';
            float_part -= 1;
        }
        else{
            binary[count++] = '0';
        }
    }
    if (count < size){
        int i;
        for (i = count; i <= size; i++){
            binary[i] = '\0';
        }
    }
}