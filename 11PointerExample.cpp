// Pointer examples from Chapter 11
// search stanford blinky pointers for video. 
#include <iostream>
using namespace std;

int main() {
	double *dPtr = new double;			// declare and allocate memory for a pointer
	short *sPtr;						// declare pointer
	sPtr = new short;					// allocate memory
	
	*sPtr = 4;							// deference pointer to assign value
	
	cout << "value at " << hex << sPtr << " is " << *sPtr << endl;
	cout << endl;
	
	delete dPtr;		// free memory
	delete sPtr;
	
	// Looping through an array using a point 
	short array[5] = {4, 5, 6, 7, 8};
	short *iPtr;
	
	// pointer arthimetic 
	iPtr = array;
	for (int i=0; i<5; i++)
		cout << *(iPtr + i) << endl;	
	cout << endl;
	
	// increment pointer in loop
	for (iPtr = array; iPtr<array+5; iPtr++)
	 	cout << *iPtr << endl;
	
}
