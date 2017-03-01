// code for blinky video from Stanford. 

#include <iostream>

using namespace std;

int main() {
	// declare pointers
	int *x;
	int *y;
		
	x = new int;		// create pointee for x
	*x = 42;
	y = x;				// same pointee as x
	*y = 13;
	
	// print locations where the pointers are stored.
	cout << "In RAM there are two 4 byte int pointers " << endl;
	cout << &x << " " << &y << endl << endl;
	// print addresses (same)
	cout << "They point to the same allocated int " << endl;
	cout << x << " " << y << endl << endl;
	// print values , note x and y point to the value of 13 
	cout << "Therefore the values are the same " << endl;
	cout << *x << " " << *y << endl;
	return 0;	
}
