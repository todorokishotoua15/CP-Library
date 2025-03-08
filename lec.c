#include<stdio.h>
int factorial(int num)
{
	/* Base Case */
	if (num == 0 || num == 1){
		return 1;
	}
	else{
		return num*factorial(num-1);  /* Recursive Call */
	}
}
int main()
{
	int num;
	scanf("%i", &num);   /* Taking Input */
	
	int res = factorial(num);   /* Result */
	printf("%i\n", res);  /* Output */
}