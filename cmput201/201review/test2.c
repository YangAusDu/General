#include <stdio.h>
int main(void) {
int n;
printf("Enter the (odd) number of integers: ");
scanf("%d", &n);
if (n <= 0 || n % 2 == 0) return 0;
int a[n];
int single = 0;
printf("Enter %d integers, should be %d pairs among them: ", n, n/2);
for (int i = 0; i < n; i++) {
scanf("%d", &a[i]);
single = single ^ a[i];
printf("single is %d\n",single);
}
printf("%d is single!\n", single);
return 0;
}