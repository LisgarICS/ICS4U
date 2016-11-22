#include <iostream>
using namespace std;

struct Node {
	int n;
	Node *next;
	Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

void printListForward(Node *);
void printListBackward(Node *);

// push new node at top of stack
void push(int num) {
	// create a new node
	Node *newNode = new Node;
	newNode->n = num;
	newNode->next = head;
	newNode->prev = NULL;
	
	if (head)
		head->prev = newNode;
	head = newNode;
	if (!tail)  // or tail == NULL
		tail = newNode;
}

// add to end of linked list
void enqueue(int num) {
	// create a new node
	Node *newNode = new Node;
	newNode->n = num;
	newNode->next = NULL;
	newNode->prev = tail;
	if (tail)
		tail->next = newNode;
	tail = newNode;
	if (!head)
		head = newNode;
}

// find first occurance of num and 
// delete it
void deleteNum(int num) {
	Node *t;
	for (t = head; t; t=t->next)
		if (t->n == num)
			break;
	if (!t) // not found
		return;
	// delete last item from list
	if (head == tail) {
		delete t;
		head = NULL;
		tail = NULL;
		return;
	}
	if (t == head)  { // pop	
		head->next->prev = NULL;
		head = head->next;
		delete t;
		return;
	}
	if (t == tail) {	// dequeue
		tail->prev->next = NULL;
		tail = tail->prev;
		delete t;
		return;
	}
	t->prev->next = t->next;
	t->next->prev = t->prev;
	delete t;
}

int main(){
	for (int i=1; i<=10; i++) 
		push(i);
	printListForward(head);
	printListBackward(tail);
	deleteNum(5);
	printListForward(head);
	printListBackward(tail);
	deleteNum(1);		
	printListForward(head);
	printListBackward(tail);
	deleteNum(10);		
	printListForward(head);
	printListBackward(tail);
}

void printListForward(Node *head) {
	for (Node *t = head; t; t=t->next)
		cout << t->n <<  " ";
	cout << endl;
}

void printListBackward(Node *tail) {
	for (Node *t = tail; t; t=t->prev)
		cout << t->n <<  " ";
	cout << endl;
}
