#include <stdio.h>

int romanize(int m,int n, char c)
{
	int quo = m/n;
	if (m - n*quo == 4) {
		printf("iv");
		return m - n*quo;
	}
	if (m - n*quo == 9) {
		printf("ix");
		return m - n*quo;
	}
	for (int i = 0; i < quo; i++) {
		printf("%c",c);
	}
	return m - n*quo;

}

int main()
{
	int input;
	scanf("%i",&input);
	input = romanize(input,1000,'m');
	input = romanize(input,500,'d');
	input = romanize(input,100,'c');
	input = romanize(input,50,'l');
	input = romanize(input,10,'x');
	input = romanize(input,5,'v');
	input = romanize(input,1,'i');
}