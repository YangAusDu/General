#include<stdio.h>
int convert_int(int a, char ch[]);
void convert_frac(float f, int intDigits,char ch[], int size);
int get_size(float a);
int main()
{
    float a;
    printf("Enter the floating-point number: ");
    scanf("%f",&a);
    
    int size = get_size(a);
    printf("the size is %d \n",size);
    int int_part = (int) a;
    float frac_part = a - int_part;
    
    char conversion[size];
    
    int c = convert_int(int_part, conversion);
    convert_frac(frac_part, c, conversion, size);
    
    printf("In binary format: %s\n",conversion);
    return 0;
    
}
//
int get_size(float a)
{
    int count =24;
    while(a<1)
    {
        a*=2;
        count++;
    }
    return count +2;
}
//
int convert_int(int a, char ch[])
{
    int count = 0;
    char temp[24];
    
    do
    {
        if(a%2)
            temp[count++] = '1';
        else
            temp[count++] = '0';
        a/=2;
    }while(a);
    
    for(int i=0; i< count; i++)
        ch[i] = temp[count -i -1];
    
    ch[count] = '.';
    
    return count;
}

void convert_frac(float f, int intDigits, char ch[], int size)
{
    int start = intDigits+1;
    while(f>0 && start < size-1)
    {
        f *=2;
        if(f >= 1)
        {
            ch[start++]='1';
            f-=1;
        }
        else
        {
            ch[start++]='0';
        }
    }
    ch[start]='\0';
}