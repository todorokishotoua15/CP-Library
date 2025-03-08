#include <stdio.h>

int main()
{
	/*Inititalizing input array sizes to a maximum length of 1000 */
	int a[1000];

	/*Initializing input data types and taking input */
	int n;

	scanf("%i", &n);

	for (int i = 0; i < n; i++) {
		scanf("%i", &a[i]);
	}
	

	int ans[1000];

	/* "Added" variable to keep track of elements added in ans */
	int added = 0;

	//Take all odd number out first and put it in ans

	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			ans[added] = a[i];
			added++;
		}
	}

	//Take all even number out  and put it in ans
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			ans[added] = a[i];
			added++;
		}
	}

	/*Answer output */
	for (int i = 0; i < n; i++) {
		printf("%i ", ans[i]);
	}
}