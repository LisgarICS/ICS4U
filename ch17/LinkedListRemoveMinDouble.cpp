// Doubly Linked list
// add items to list
// delete mininum item until list is emptied. 
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node { 
	int num;
	Node *prev;
	Node *next;
};

void addNode(Node* &head, Node* &tail, int n);
void printList(Node * head);
void printListTail(Node *tail);
void removeMin(Node* &head,Node* &tail);
void printListDetail(Node *head, Node *tail); 


int main() {
	Node *head = NULL;
	Node *tail = NULL;
	
	srand(time(0));
	for (int i=0; i<12; i++) { // add 12 random numbers
		addNode(head, tail, rand() % 20);
	}
		
	printList(head);
	printListDetail(head, tail);
	printListTail(tail);
	while (head && tail) {
		removeMin(head, tail);
		printList(head);
		//printListTail(tail);
	 	//printListDetail(head, tail);
	}
}


void removeMin(Node* &head, Node* &tail) {
	if (!head)			// empty list
		return;	
	if (!head->next) {	// one item
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	
	Node *minPtr = head;		// set min to first item.
	// search rest of list.
	for (Node *ptr=head->next; ptr; ptr = ptr->next) {
		if (ptr->num < minPtr->num)
			minPtr = ptr;		
	}

	// special case last item
	if (minPtr == tail) {
		tail = tail->prev;
		minPtr->prev->next = minPtr->next;
		return;
	}
	
	// specal case to remove first item
	if (minPtr == head)	{  
		Node *temp = head->next;
		delete head;
		head = temp;
		temp->prev = NULL;
		return;
	}

	// adjust pointer when middle of list
	minPtr->prev->next = minPtr->next;
	minPtr->next->prev = minPtr->prev;
	delete minPtr;
}

void addNode(Node* &head, Node* &tail, int n) {
	// add node to end of list
	// create node
	cout << "Adding " << n << endl;
	Node *newnode = new Node; 
	newnode->num = n;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (!head) {		   // attach node to head if empty list
		head = newnode;
		tail = newnode;
		return;
	}
	Node *t = head;
	while (t->next) {
		t = t->next; 		// find tail
	}
	t->next = newnode;		// attach node to end of list
	newnode->prev = t;
	tail = newnode;
}

// print out all locations, value, head and tail.
void printListDetail(Node *head, Node *tail) {
	cout << "Details: " << endl;
	cout << "head : " << head << endl;
	for (; head; head=head->next) 
		cout << hex << "cur: " << head << dec << " " << head->num << hex 
			<< " next: " << head->next << " prev:  " << head->prev << endl;
	cout << endl;
	cout << "tail : " << tail << endl;
	cout << dec;
}

// regular print list
void printList(Node *head) {
	cout << "List from Head: ";
	for (; head; head=head->next) 
		cout << head->num << " ";
	cout << endl;
}

// traverse backwards through tail. 
void printListTail(Node *tail) {
	cout << "List from Tail: ";
	for (; tail; tail=tail->prev) 
		cout << tail->num << " ";
	cout << endl;
}



