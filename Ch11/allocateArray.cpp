/*****************************************************************************
 *	Name:   Mr. Creelman                                                     *
 *	Course: ICS4U                                                            *  
 *	Date:   March 1, 2016                                                    *  
 *	                                                                         * 
 *	Purpose: Demonstrate allocating an array dynamically.
 *   		 Demonstrate checking if successfuly allocated.
 *	    	 And free the memory                                             *
 *	                                                                         *
 *	Usage:  Enter size of array to allocate
 *																			 *
 *	Revision History:  None                                                  *  
 *	                                                                         *
 *	Known Issues:  												             *
 *	                                                                         *  
 *****************************************************************************/

#include <iostream>

using namespace std;

int main() {
	//view content and addresses of a integer array
	double *data;
	int n;
	
	cout << "How many data items? " << endl;
	cin >> n;
	data = new double[n];
	if (! data) {
		cout << "Memory allocation error " << endl;
	}
	// initialize array
	for (int i=0; i<n; i++) 
		data[i] = i;
		
	// free memory allocated. Note syntax. 	
	delete [] data;	
	return 0;
}
