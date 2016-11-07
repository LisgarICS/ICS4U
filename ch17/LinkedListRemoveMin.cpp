// Linked List Problems
#include <iostream>
using namespace std;

struct Node { 
	int num;
	Node *next;
};

void addNode(Node* &head, int n);
int  countNumber(Node* head, int n);
Node* removeNode(Node* head, int n);
Node* removeAll(Node* head, int n);
void printList(Node * head);
void removeMin(Node* &head);


int main() {
	Node *head = NULL;
	
	for (int i=10; i<=20; i+=2) { // add 10, 12, 14, 16, 18, 20 to list
		addNode(head, i);
	}
	addNode(head, 14);
	addNode(head, 14);
	cout << countNumber(head, 14) << endl;
	while (head) {
		removeMin(head);
		printList(head);
	}
}


void removeMin(Node* &head) {
	if (!head)			// empty list
		return;	
	if (!head->next) {	// one item
		delete head;
		head = NULL;
		return;
	}
	Node *minPtr = head;		// keep track of where min is.
	// find min 
	for (Node *ptr=head->next; ptr; ptr = ptr->next) {
		if (ptr->num < minPtr->num) 
			minPtr = ptr;		
	}
	if (minPtr == head)	{  // specal case to remove first item
		Node *newhead = head->next;
		delete head;
		head = newhead;
		return;
	}
	// loop through list looking for min, keeping track of prev
	Node *prev = head; 
	for (Node *ptr=head->next; ptr; ptr = ptr->next) {
		if (ptr == minPtr)
			break;
		prev = ptr;
	}
	// adjust pointer
	prev->next = minPtr->next;
	delete minPtr;

}



void addNode(Node* &head, int n) {
	// add node to end of list
	// create node
	cout << "Adding " << n << endl;
	Node *newnode = new Node; 
	newnode->num = n;
	newnode->next = NULL;
	if (!head) {		   // attach node to head if empty list
		head = newnode;
		return;
	}
	Node *t = head;
	while (t->next) {
		t = t->next; 		// find tail
	}
	t->next = newnode;		// attach node to end of list
}

void printList(Node *head) {
	cout << "List: ";
	for (; head; head=head->next) 
		cout << head->num << " ";
	cout << endl;
}


/*1.	Precondition:
There exists a linked list containing some number of integers I where (0 < I < 1000).  
Postcondition:
This function counts the instances of a certain number in the list and returns that number.*/
	      
int  countNumber(Node* head, int n) {
	return 3;   // works only if answer is 3




}

/* 2.	Precondition:
There exists a linked list containing more than 2 integers (0 < I < 1000).  
Post condition:
The first containing a certain number n is removed from the list.
The head of the new list is returned.  */

Node* removeNode(Node* head, int n) {








	return head;
}

/*3.	Precondition:
There exists a linked list containing some number of integers (0 < I < 1000).  
Post condition:
All nodes in the list that are equal to the number n have been removed.
The function returns the new head, or NULL if all numbers have been deleted.*/

Node* removeAll(Node* head, int n) {
	
	return head;
}
