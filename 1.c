#include <stdio.h>
struct Employee
	{
		int code = -1;  // Default value, changes when structure is created 
		// Predefining array max size to be 1000
		char name[1000];
		char  date[1000];
		float salary;
	}alldata[1000]; // alldata stores all structures

// Display function, which prints all structure having salary greater than
// threshold salary
void display(struct Employee alldata[1000], int salary) {
	for (int i = 0; i < 1000; i++) {
		// If code is -1 (default), then break, because no structure where created after that
		if (alldata[i].code == -1) {
			break;
		}
		// Compare salary with given threshold salary
		if (alldata[i].salary > salary) {
			printf("name : %s Employee code : %i\n", alldata[i].name, alldata[i].code);
		}
	}
	
}

int main()
{
	// Creatung structures for testing purposes
	struct Employee harsh = {001, "Harsh Kumar", "08/03/2022", 1000000};
	struct Employee dany = {002, "Danniel Rand", "09/03/2022", 50000};
	struct Employee matt = {003, "Matthew Murdock", "10/03/2022", 431549};
	struct Employee jessica = {004, "Jessica Jones", "11/03/2022", 120354};
	struct Employee luke = {005, "Luke cage", "12/03/2022", 123456};

	// Storing structures in alldata array
	alldata[0] = harsh;
	alldata[1] = dany;
	alldata[2] = matt;
	alldata[3] = jessica;
	alldata[4] = luke;
	
	// Testing 
	display(alldata,123456);

	return 0;
	
}