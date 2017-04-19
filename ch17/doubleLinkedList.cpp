// Double Linked List Example
// NOTE UNDERSTAND THESE TWO LINES. 
//		minPtr->prev->next = minPtr->next;
//		minPtr->next->prev = minPtr->prev;

#include <iostream>
using namespace std;

struct Node { 
	int num;
	Node *prev;
	Node *next;
};

Node *head;
Node *tail;

void addNode(int n, bool front);
void printList(bool front);
void removeMin();
void printdetailList(bool front);

int main() {
	head = NULL;
	tail = NULL;
	for (int i=0; i<10; i+=2)
		addNode(i, true);
//	printdetailList(true)	;
	for (int i=1; i<11; i+=2)
		addNode(i, false);
//	printdetailList(true)	;	
	printList(true);
	printList(false);
	cout << "Removing Minimum " << endl;
	while (head) {
		removeMin();
		printList(true);	
	}
	return 0;
}

// if front == true, push node, otherwise put at back.
void addNode(int n, bool front) {
	// create a node
	Node *newnode = new Node;
	newnode->num = n;
	newnode->next = NULL;
	newnode->prev = NULL;
	
	// check empty list
	if (!head) {
		head = newnode;
		tail = newnode;
		return;
	}
	
	// push
	if (front) { 
		newnode->next = head;
		head->prev = newnode;
		head = newnode;	
	}
	else { // enqueue at back of list
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	return;
}

// remove smallest node, note relatively easy compared
// to singly linked list.
void removeMin() {
	Node *minPtr = head;
	// if empty just read
	if (!head) 
		return;
	if (head == tail) {	// just one node
		head = NULL;
		tail = NULL;
		delete minPtr;
		return;
	}
	
	// find smallest number
	for (Node *t=head; t; t=t->next) 
		if (t->num < minPtr->num)
			minPtr = t;
	cout << "Found " << minPtr->num << endl;
	// remove node
	if (minPtr == head) {  // pop
		head = head->next;
		head->prev = NULL;  // unlink
	}
	else if (minPtr == tail) {  // remove from end.
		tail = tail->prev;
		tail->next = NULL;  // unlink
	}
	else {
		// otherwise middle of list
		// NOTE UNDERSTAND THESE TWO LINES. 
		minPtr->prev->next = minPtr->next;
		minPtr->next->prev = minPtr->prev;
	}
	delete minPtr;	
	return;	
	
}


// print out linked list with address and pointers
void printdetailList(bool front) {
	cout << "From head: ";
	cout << "head: " <<  hex << head << endl;
	cout << "tail: " <<  hex << tail << endl;
	for (Node *t=head; t; t=t->next) {
		cout << "Node: " << t << " Value : " << t->num 
			<< " Prev : " << t->prev 
				<< " Next: " << t->next << endl;
	}
	cout << endl;
}

void printList(bool front) {
	if (front) {
		cout << "From head: ";
		for (Node *t=head; t; t=t->next) 
			cout << t->num << " ";
	}
	else {
		cout << "From tail: ";
		for (Node *t=tail; t; t=t->prev) 
			cout << t->num << " ";
	}
	cout << endl;
}
