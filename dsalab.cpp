#include<bits/stdc++.h>

// Macros
#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define ll long long
#define nl "\n"
#define el endl
#define pb push_back
using namespace std;

// Global constants
const ll N = 1e3 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e17 + 2;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;

// Linked list structure 
struct linkedlist
 {
 	int val;
 	struct linkedlist* next;
 	
 };

// Insert function
void insert(struct linkedlist** head, int index, int data) {
	int count = 0;
	struct linkedlist* temp = (*head);
	if (index == 0) {
		struct linkedlist* nn = (struct linkedlist*) malloc(sizeof(struct linkedlist));
		nn->val = data;
		nn->next = temp;
		(*head) = nn;
		return;

	}
	while (temp->next) {
		count++;
		temp = temp->next;
		if (count == index - 1) break;
	}
	struct linkedlist* nn = (struct linkedlist*) malloc(sizeof(struct linkedlist));

	nn->val = data;
	nn->next = NULL;
	if (temp->next != NULL)nn->next = temp->next;
	temp->next = nn;

	

 }


// Display function
void display(struct linkedlist* head) {
	struct linkedlist* temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << nl;
}

// Swap function
void swap(struct linkedlist** head, int n) {

	/* Approach : keep track of prev node and curr node, change link of first node
	   so that it points to fourth node, and change the link of second node so that
	   it points to first node and change link of 2nd node so that it points to 5th node
	   and so on , it will take (n/2) iterations to do this so time complexity : O(n) */

	struct linkedlist* temp = (*head); 
	struct linkedlist* prev = (*head);

	// Single node condition
	if (temp->next == NULL ) {
		return;
	}

	temp = temp->next;
	(*head) = (*head)->next;
	int f = 0;
	int cnt = 1;
	while(cnt <= (int)n/2) {
		struct linkedlist* curr = prev; // one more node for current node
		if (temp->next == NULL) {
			temp->next = prev;
			temp->next->next = NULL;
		}
		if(prev->next && prev->next->next &&prev->next->next->next)prev->next = prev->next->next->next;
		else if (prev && prev->next && prev->next->next) prev->next = prev->next->next;
		else if(prev) prev->next = NULL;
		
		if (temp->next)prev = temp->next;
		if (temp->next)temp->next = curr;
		if (prev->next)temp = prev->next;

		cnt++;
	}


}



 int main()
 {
 	
 	int t;
 	t = 1;
 	while(t--) {
 		struct linkedlist* head = (struct linkedlist*) malloc(sizeof(struct linkedlist));
 		head = NULL;

 		//----- Input -----//
 		int n;
	 	cin >> n;
	 	vector<int>v(n);
	 	for (auto &s : v) cin >> s;
	 	// ----- ------- //

	 	// ----- Creating linked list ----- //
	 	for (int i = 0; i < n; i++) {
	 		insert(&head,i,v[i]);
	 	}
	 	// ------------------------------- //

	 	swap(&head,n); // swapping
	 	display(head); // output
 	}
 	

 	
 }