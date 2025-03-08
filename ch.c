#include <stdio.h>
#include <string.h>

int sum(int a, int b)
{
int total = 0;
for (;a<=b;a++)
total = total + a;
return total;
}
int main()
{
	int data[2][2] = { { 1,2 },{ 3,4 } };
int (*p)[2];
p = &data[1];
printf("%i",*p);
}