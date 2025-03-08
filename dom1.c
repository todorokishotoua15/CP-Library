#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// linked list structure 
struct linkedlist
 {
 	int val;
 	struct linkedlist* next;
 	
 };

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

// update function
 void update(struct linkedlist** head, int index, int data) {
 	struct linkedlist* temp = (*head); // temp node
 	int cnt = 0; // to track current position while traversing the linked list
 	while(temp) {
 		if (cnt == index) {
 			temp->val = data; // updating value
 			return;
 		}
 		cnt++;
 		temp = temp->next;
 	}

 }

// delete function
void del(struct linkedlist** head, int index) {
	struct linkedlist* temp = (*head); // current node
	struct linkedlist* prev = (*head); // to keep track of previous node

	// head is NULL condition
	if (temp == NULL) {
		return;
	}

	// head is only node condition
	if (temp->next == NULL) {
		free(temp);
	}

	// need to remove head condition
	if (index == 0) {
		*head = temp->next;
		free(temp);
	}
	int cnt = 1; // keep track of position while traversing the linked list
	temp = temp->next; // increment temp so prev points head and temp points head->next
	while (temp) {
 		if (cnt == index) {
			if (temp->next == NULL) {
				prev->next = NULL;
				free(temp);

			}
			else {
				prev->next = temp->next;
				free(temp);
				
			}
			break;
		}
		temp = temp->next;
		prev = prev->next;
		cnt++;
	}

}

// display function
void display(struct linkedlist* head) {
	struct linkedlist* temp = head;
	while (temp != NULL) {
		printf("%i ", temp->val); // printing node value
		temp = temp->next;
	}
	printf("\n");
}

 int main()
 {
 	struct linkedlist* head = (struct linkedlist*) malloc(sizeof(struct linkedlist));
 	head = NULL; // creating null head
 	int n; // number of queries
 	scanf("%i", &n);
 	
 	// query solving
 	while(n--) {
 		int x,y,z;
 		scanf("%i", &x);
 		
 		// Query conditions
 		if (x == 4) {
 			
 			display(head);
 			continue;
 		}
 		else if (x == 1 || x == 3) {
 			scanf("%i %i", &y ,&z);
 			if (x == 1) {
 				insert(&head,y,z);
 			}
 			if (x == 3) {
 				update(&head, y,z);
 			}
 		}
 		else if (x == 2) {
 			scanf("%i", &y);
 			del(&head,y);
 		}
 	}
 	
 		

 	
 }