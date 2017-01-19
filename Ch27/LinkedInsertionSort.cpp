#include <iostream>
/*****************************************************************************
  *	Name:  Mr. Creelman                                                      *
  *	Course: ICS4U                                                            *  
  *	Date: January 2017    			See page 493 in text                     * 
  *	                                                                         * 
  *	Purpose: demonstrate problem with sorting a sorted linked list using
  * insertion sort. This is a modified insertion sort due to using a linked  *
  *	 list, it checks to insert from the front, rather than shift back        *
  *	Usage:                                                                   *
  *	                                                                         *
  *	Revision History:                                                        *  
  *	                                                                         *
  *	Known Issues:  Linked list may be lacking some error checking            *
  *	                                                                         *  
 + *****************************************************************************/
using namespace std;

struct Node { 
	int num;
	Node *next;
};

class List {
	private:
		Node *head;
		int swaps;			// number of swaps
		int traverses;		// cost of going through linked list
		int length;
		Node *findNode(int pos); 
	public:
	 	List(){ head = NULL; swaps = 0; traverses = 0; length = 0; }
		void push(int n); 			
		int pop();
		bool isEmpty() {return head == NULL;}
		int compare(int first, int second);
		void swap(int first, int second);
		void shift(int second);
		int getLength() {return length;}
		int getSwaps() {return swaps;}
		int getTraveres() {return traverses;}
		int getNum(int pos);
		void setNum(int pos, int num);
		void emptyList();
		Node *getNode(int pos); 
		void print();
		~List();
};

Node *List::getNode(int pos) {
	Node *node = head; 
	if (pos > length) return NULL;
	int i;
	for (i=0; i<pos; i++) {
		if (node->next) {
			node = node->next;
			traverses++;
		}
	}	
	return node;
}

void List::setNum(int pos, int n) {
	Node *t = getNode(pos);
	t->num = n;
}

// shift the number from pos1, to previous number
void List::shift(int pos) {
	Node *node1 = getNode(pos-1); 
	Node *node2 = node1->next;
	swaps++;
	int temp;
//	cout << "swap    " << node1->num << " " << node2->num << " swaps: " << swaps << endl;
	temp = node1->num;
	node1->num = node2->num;
	node2->num = temp;
//	cout << "swapped " << node1->num << " " << node2->num << endl;
	return;
}

// swap data of nodes at pos1, and pos2 
void List::swap(int pos1, int pos2) {
	Node *node1 = head; 
	Node *node2 = head;
	int temp;
	if (pos1> length || pos2 >length) return;
	int i;
	for (i=0; i<pos1; i++) {
		if (node1->next) {
			node1 = node1->next;
			traverses++;
		}
	}	
	for (; i<pos2; i++) {
		if (node2->next) {
			node2 = node2->next;
			traverses++;
		}
	}	

	swaps++;
	
//	cout << "swap    " << node1->num << " " << node2->num << " swaps: " << swaps << endl;
	temp = node1->num;
	node1->num = node2->num;
	node2->num = temp;
//	cout << "swapped " << node1->num << " " << node2->num << endl;
	return;
}

// add number to beginning of list
void List::push(int n) {
	Node *newnode = new Node;
	newnode->num = n;
	newnode->next = head;
	head = newnode;
	length++;
}

// remove and return value of first node
int List::pop() {
	if (isEmpty())		// just return 0 for now 
		return 0;
	int n = head->num;
	Node *temp = head->next;
	delete head;
	head = temp;
	length--;
	return n;
}

// pass in head by value
void List::print() {
//	cout << hex << "head: " << head << endl;
	for (Node *t=head; t; t=t->next) 
		cout << dec << t->num << " ";
	if (getTraveres() != 0)
		cout << endl << "swaps: " << getSwaps() << " traverses: " << getTraveres() << endl;
	cout << endl;
}

// really depending on pos being <= length 
int List::getNum(int pos) {
	Node *temp = head; 
	if (isEmpty()) return 0;	
	for (int i=0; i<pos; i++) {
		if (temp->next) {
			traverses++;
			temp = temp->next;
		}
	}	
	return temp->num;
}

void List::emptyList() {
	while (!isEmpty()) 
		pop();
	swaps = 0; 
	traverses = 0;	
} 

List::~List() {
	while (!isEmpty()) 
		pop();
}

// ideally this would be in a separate file, but to avoid multiple files, just insert here
void insertionSort(List &ll);  // prototype

int main() {
	List list;
	const int size = 50;
	// reversed list, (note it's a stack 
	cout << "reverse order list: " << endl;
	for (int i=0; i<size; i++)
		list.push(i);
	list.print();
	insertionSort(list);
	list.print();
	list.emptyList();
	cout << endl << endl << "ordered list: " << endl;
	for (int i=size-1; i>=0; i--)
		list.push(i);
	list.print();
	insertionSort(list);
	list.print();
}

void insertionSort(List &ll) {
	int i, j, n = ll.getLength();
	int vCurrent;
	
	for (int i=1; i<n; i++) {
		vCurrent = ll.getNum(i);
///		cout << "vCurrent = " << vCurrent << endl;
		for (j =0; j<i; j++) 
			if (ll.getNum(j) >= vCurrent)
				break;
	
		for (int k=i-1; k >=j; k--) {		
		//	cout << "shift  " << ll.getNum(k+1) << " "  << ll.getNum(k ) << endl;
			ll.shift(k+1);
		}
	//	cout << "j = " << j << endl;
		ll.setNum(j, vCurrent);
	//	ll.print();
	}
}
