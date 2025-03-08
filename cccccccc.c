#include<stdio.h>

struct defenders {
	char n; int b; float s;
};


int main()
{
	defenders netflix[] ={
	{'A', 23, 4000.5},
	{'B', 24, 500000.5}
};
	display(netflix[0].n);
	
}