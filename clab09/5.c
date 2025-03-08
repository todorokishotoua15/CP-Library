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

	/*Initializing answer */
	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		

		if (i == 0 && a[i] != 13) {
			ans += a[i];
		}
		if (i!= 0 && a[i] != 13 && a[i-1] != 13) {
			ans += a[i];
		}
	}

	if (a[n-1] != 13 && a[n-2] != 13) {
		ans += a[n-1];
	}

	/*Output */
	printf("%i \n", ans);
}