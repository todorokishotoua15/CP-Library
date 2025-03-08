#include <stdio.h>

int main()
{
	int n, m;  /* initalizing input data type */

	scanf("%i %i", &n,&m); /*taking input array sizes */

	/*Decalring arrays */
	int a[1000], b[1000];
	int ans[2000];

	/*Taking first array input */
	for (int i = 0; i < n; i++) {
		scanf("%i", &a[i]);
	}

	/*Taking second array input */
	for (int i = 0; i < m; i++) {
		scanf("%i", &b[i]);
	}

	/* added is a variable that keeps track of how many element has 
	added to ans array till now */
	int added = 0;

	/* Taking odd indexed element  from first array
	and even indexed element from second array */
	for (int i = 1; i < n; i+=2) {
		
			

			ans[added] = a[i];

			/*After addition, increment added by 1 */
			added++;
			
		
	
	}
	for (int i = 0; i < m; i+=2) {
		

			ans[added] = b[i];

			/*After addition, increment added by 1 */
			added++;
			
		
		
	}

	/* Ans array out (int a single line) */
	for (int i = 0 ; i < added; i++) {
		printf("%i ", ans[i]);
	}
}