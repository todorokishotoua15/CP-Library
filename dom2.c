#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// insert function
void insert(struct linkedlist** head, int index, int data) {
	int count = 0; // to track current position while traversing list
	struct linkedlist* temp = (*head);
	if (index == 0) {
		struct linkedlist* nn = (struct linkedlist*) malloc(sizeof(struct linkedlist)); // new node
		nn->val = data; // assigning value to new node
		nn->next = temp; 
		(*head) = nn; // index == 0 condition
		return;

	}
	// traversing upto the given index point
	while (temp->next) {
		count++; 
		temp = temp->next;
		if (count == index - 1) break;
	}
	struct linkedlist* nn = (struct linkedlist*) malloc(sizeof(struct linkedlist)); // new node

	nn->val = data;
	nn->next = NULL;
	// changing links
	if (temp->next != NULL)nn->next = temp->next; 
	temp->next = nn;

	

 }


int main()
{
	
}