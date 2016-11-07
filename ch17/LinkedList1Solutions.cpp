// Linked List Worksheet 1
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


int main() {
	Node *head = NULL;
	
	for (int i=10; i<=20; i+=2) { // add 10, 12, 14, 16, 18, 20 to list
		addNode(head, i);
	}
	addNode(head, 14);
	addNode(head, 14);
	cout << countNumber(head, 14) << endl;
	cout << countNumber(head, 10) << endl;
	printList(head);
	head = removeAll(head, 14);  // in class I forgot to assign head.
	printList(head);
	head = removeNode(head, 10);
	printList(head);
}

void addNode(Node* &head, int n) {
	// add node to end of list
	// create node
	cout << "Adding " << n << endl;
	Node *newnode = new Node; 
	newnode->num = n;
	newnode->next = NULL;
	if (!head) {	  // attach node to head if empty list
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
	int count = 0;
	for (Node *t= head; t!= NULL; t=t->next) {
		if (t->num == n)
			count++;	
	}
	return count;
}

/* 2.	Precondition:
There exists a linked list containing more than 2 integers (0 < I < 1000).  
Post condition:
The first containing a certain number n is removed from the list.
The head of the new list is returned.  */

Node* removeNode(Node* head, int n) {
	cout << "Removing: " << n << endl;
	Node *t = head;
	Node *prev = NULL;
	while (t && t->num != n) {
		prev = t;
		t = t->next;	
	}
	if (!t)  // not found
		return head;
	// special case to remove first node
	if (t == head) {
		head = head->next;
	}
	else if (t != NULL) { 		
		prev->next = t->next;
	}
	
	delete t;
	return head;
}

/*3.	Precondition:
There exists a linked list containing some number of integers (0 < I < 1000).  
Post condition:
All nodes in the list that are equal to the number n have been removed.
The function returns the new head, or NULL if all numbers have been deleted.*/

Node* removeAll(Node* head, int n) {
	while (countNumber(head, n) > 0)
		head = removeNode(head, n);	
	return head;
}
