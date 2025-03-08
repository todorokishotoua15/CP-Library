#include <stdio.h>

int main()
{
	/*Inititalizing input array sizes to a maximum length of 1000 */
	int a[1000], b[1000];

	/*Initializing input data types and taking input */
	int n,m;

	scanf("%i %i", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%i", &a[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%i", &b[i]);
	}

	/* "Common" array, to store common element of both arrays */
	int common[1000];

	/* "Added" variable to keep track of elements added in common */
	int added = 0;

	/*Finding common in both array */
	for (int i = 0; i < n; i++) {

		/*Variable "addable", if it is 1, then common element found is added to common
		  otherwise not, to filter out duplicates */
		int addable = 1;

		for (int j = 0; j<m; j++) {
			if (a[i] == b[j]) {

				/*Chcek if it is already present in common */
				for (int k =0; k< added-1; k++) {
					if (a[i] == common[k]) {
						addable = 0;
					}
				}

				/*If not present in common then add it */
				if (addable == 1) {
					common[added] = a[i];
					added++;
				}
				break;
			}

		}

	}

	/* Answer output */
	for (int i = 0 ; i < added - 1; ++i) {
		printf("%i ", common[i]);
	}
}