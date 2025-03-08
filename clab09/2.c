#include <stdio.h>

int main()
{
	/* Initializing input array to a maximum size of 100 */
	int a[1000];

	/*Initializing array size and taking input */
	int n;
	scanf("%i", &n);

	/*Taking array in input */
	for (int i = 0; i <n; i++) {
		scanf("%i", &a[i]);
	}

	/*Initializing array "checkd" to add those element which is checked of its occurence */
	int checked[1000];

	/* initializing variable to keep track of how many element is added to checked array */
	int added_in_checked  = 0;

	/*Chceking for occurence and printing answers */
	for (int i =0; i < n; i++) {

		/*Proceed variable that is checked afterward to check that element or not
		  if it is already checked, then proceed is set to 0 and it is not checked
		  again */

		int proceed = 1;

		/* Count variable , to keep count of element occurence */
		int count = 0;

		/*Checking if element is already added */
		if (added_in_checked != 0) {
			for (int e = 0; e < added_in_checked; e++) {
				if (checked[e] == a[i]){
					proceed = 0;
				}
			}
		}
		
		/*Check if we can proceed to count occurence or not */
		if (proceed == 1) {
			for (int j = 0; j < n; j++) {
				if (a[j] == a[i]) {
					count++;
				}
			}
			/*Output occurence */
			printf("%i occurs %i times in given array \n", a[i], count);

			checked[added_in_checked] = a[i];

			/*Increment the element added count in checked by 1 */
			added_in_checked++;

			/*Set count to 0 again to use it again */
			count = 0;
			}
		/* Set proceed to 1 again to use it again */
		proceed = 1;
	}
}