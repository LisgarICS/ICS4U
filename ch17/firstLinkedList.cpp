// Mr. Creelman   November 2016
// first linked list program
#include <iostream>
using namespace std;

// define the node structure
struct Node {
	int data;
	Node *next;  // pointer to node
};

// pointer to first node in list
Node *head = NULL;  
void printList(Node *hello); 

int main() {
	// create a new node
	Node *newnode = new Node;
	newnode->data = 34;
	newnode->next = NULL;
	// set head to point to this new node
	head = newnode;
	printList(head); 

	// push another node on list
	Node *newnode2 = new Node;
	newnode2->data = 72;
	newnode2->next = head; // point to previous head
	head = newnode2;
	printList(head);
	
	// free memory	
	while (head) {
		// temp pointer keep track of next node
		Node *t = head->next;
		cout << "deleting " << head->data << endl;
		delete head;
		head = t;
	}
}

// pass in head by value
void printList(Node *hello) {
	cout << "list starts at " << 
			hex << head << endl;
	for (; hello; hello=hello->next) 
		cout << dec << hello->data << " ";
	cout << endl;
}
