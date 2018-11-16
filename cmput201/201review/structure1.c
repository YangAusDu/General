#include <stdio.h>
#include <string.h>

#define N 3


struct people{
    char name[50];
    int age;
    char sex;
};

void print_people(struct people p){
    printf("The name is : %s\n",p.name);
    printf("The age is : %d\n",p.age);
    printf("The sex is : %c\n",p.sex);
}

struct people create_people(char name[], int age, char sex){
    struct people p;
    strcpy(p.name, name);
    p.age = age;
    p.sex = sex;
    return p;
}

int main(){
    struct people people1;
    struct people information[N]={
        {"Ace",8,'M'},
        {"Alice",26,'S'},
        {"God",88,'M'}
    };
    int i;
    for (i=0;i<N;i++){
        print_people(create_people(information[i].name,information[i].age,information[i].sex));
        printf("\n");
    }        

    return 0;
}

