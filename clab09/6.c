#include <stdio.h>
#define inf 1e9 + 2


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

	/*Sorted array (answer) */
	int sorted[1000];
	int added = 0; /*Variable that keeps track of how many elements have been added 
	                 to sorted array */


	/* Algorithm : initialize min to infinity and do nested loop, which finds minimum
	               element in array each time and then add the minimum element to sorted 
	               array. After finding minimum element, change its value to infinity + 2
	               so that it is not minimum anymore, and won't be deteceted in further loops */

	/* Sorting */
	for (int i = 0; i < n; i ++ ) {
		int min = inf; /*initialize min to infinity */

		/*Find minimum */
		for (int j = 0; j < n; j++) {
			if (a[j] <= min) {
				min = a[j];
			}
		}

		/*Loop again to change the value of minimum element found, to infinity + 2
		  so that it is greater than all elements, even min */

		for (int j = 0; j < n; j++) {
			if (a[j] == min) {
				a[j] = inf + 2;
				break;
			}
		}

		/*Add minimum element found in sorted array */
		sorted[added] = min;
		added++;
	}

	/* Answer output */
	for (int i = 0 ; i < added ; ++i) {
		printf("%i ", sorted[i]);
	}

}