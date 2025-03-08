#include <iostream>
using namespace std;

typedef struct node{
	int data;
	node* next;
	node(int val){
		data = val;
		next = NULL;
	}
};
void insertAtTail(node* &head, int val)
{

	node* n = new node(val);

	if (head == NULL) {
		head = n;
		return;
	}

	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = n;

}
void display(node* head){
	node* temp = head;
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
void insertAtHead(node* &head, int val)
{
	node* n = new node(val);
	n->next  = head;
	head = n;

}
bool search(node* head, int key){
	node* temp = head;
	while(temp != NULL){
		if (temp->data == key) {
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}
int main()
{
	node* head = NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtHead(head,4);
	insertAtHead(head,5);
	insertAtHead(head,6);
	display(head);
	cout << search(head,6);
	return 0;
}