#include<stdio.h>


int is_prime(int num)
{
	int flag = 0
	for (int i = 2; i < num/2 + 1; ++i){
		if (num % i == 0){
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		return 1;
	if (flag == 1)
		return 0;
}

int main()
{
	
}