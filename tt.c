#include<stdio.h>
fun(int b)
{
	if (b == 0)
		return 0;
	else{
		printf("a");
		fun(b--);
	}
}
int main()
{
	int a;
	a = fun(10);
	printf("%d", a);
}

