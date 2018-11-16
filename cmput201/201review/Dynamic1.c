/*DynamicAlloc.c*/
#include <stdio.h>
#include<stdlib.h>
#define SIZE 3

int * insert(int * list, int *index , int * plen);
void print_list(int *p , int n);
void print_sum(int *p , int n);

int main()
{
    int * list = malloc(SIZE*sizeof(int));
    /*
     len: is the maximum length of the current list
     index: The number of stored elements inside the list
     */
    int len = SIZE, index = 0;
    
    if(list == NULL)
    {
        printf("An error while memory allocation\n");
        exit(EXIT_FAILURE);
    }
    
    while(1)
    {
        char mode;
        printf("Enter the mode of operation:");
        scanf(" %c",&mode);
        while(getchar() != '\n');
        switch(mode)
        {
            case 'i':
                list = insert(list, &index , &len);
                break;
            case 'p':
                print_list(list , index);
                printf("Number of elements: %d\n",index);
                printf("Max list size:%d\n",len);
                break;
            case 's':
                print_sum(list , index);
                break;
            case 'q':
                free(list);
                printf("Program terminates\n");
                return 0;
        }
    }
    return 0;
}
//
int * insert(int * list, int *index , int * plen)
{
    if(*index >= *plen)
    {
        *plen *= 2;
        list = realloc(list, *plen * sizeof(int));
        if(list == NULL)
        {
            printf("An error while memory allocation\n");
            exit(EXIT_FAILURE);
        }
    }
    printf("Enter an integer value:");
    scanf("%d", list + *index);
    (*index)++;
    return list;
}
//
void print_list(int *p , int n)
{
    printf("List:");
    for(int i=0; i<n; i++)
        printf("%-5d",p[i]);
    printf("\n");
}
void print_sum(int *p , int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
        sum+=p[i];
    printf("The sum of list elements = %d\n",sum);
}