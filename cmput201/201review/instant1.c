#include <stdio.h>
#include <stdlib.h>

struct balance
{
    float principal_outstanding, payment, interest, principal_paid;
};
//
float check(float principal, float monthly_rate, int nummonths, float payment, struct balance info[nummonths]);
void print(int nummonths, struct balance info[nummonths]);
//
int main() {
    float principal, annualrate, monthrate;
    int nummonths;
    printf("Enter the loan amount ($):"); scanf("%f",&principal);
    printf("Enter the annual interest rate (%%):"); scanf("%f",&annualrate);
    monthrate = annualrate/(12*100);
    printf("Enter the number of months to pay back:"); scanf("%d",&nummonths);
    
    struct balance info[nummonths];
    float lb = 0, ub = principal, payment;
    while(lb<=ub){
        payment =  (lb + ub)/2;
        float net =  check(principal, monthrate, nummonths, payment, info);
        if(abs((int) net) < nummonths) break;
        if(net > 0)
            lb = payment;
        else
            ub = payment;
    }
    print(nummonths, info);
    return 0;
}
float check(float principal, float monthly_rate, int nummonths, float payment,struct balance info[nummonths])
{
    for(int i=0; i < nummonths-1 ; i++)
    {
        info[i].principal_outstanding = principal;
        info[i].payment = payment;
        info[i].interest =  monthly_rate*info[i].principal_outstanding;
        //
        if(info[i].payment <= monthly_rate*info[i].principal_outstanding) return (-1-nummonths);
        info[i].principal_paid =  info[i].payment - monthly_rate*info[i].principal_outstanding;
        principal -= info[i].principal_paid;
    }
    info[nummonths-1].principal_outstanding = info[nummonths-1].principal_paid = principal;
    info[nummonths-1].interest =  monthly_rate * info[nummonths-1].principal_outstanding;
    info[nummonths-1].payment =  info[nummonths-1].interest + info[nummonths-1].principal_outstanding;
    
    return (info[nummonths-1].payment - payment);
}

void print(int nummonths, struct balance info[nummonths])
{
    printf("Your monthly payment = %.2f \n",info[0].payment);
    printf("%30s%13s%15s%15s\n","principal_outstanding","payment","interest","principal_paid");
    float totalInt = 0;
    for(int i=0; i<nummonths ; i++)
    {
        printf("Payment No.%d :%16.2f%13.2f%15.2f%15.2f\n",i+1,info[i].principal_outstanding,info[i].payment,info[i].interest,info[i].principal_paid);
        totalInt += info[i].interest;
    }
    printf("\n Total interest paid = %.2f\n",totalInt);
}