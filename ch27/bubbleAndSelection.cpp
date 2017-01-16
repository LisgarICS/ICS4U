#include <iostream>
#include <algorithm>
using namespace std;

void selectionsort(int *a, int n) {
	int iMin;  // index of minimum 

	for (int i=0; i < n-1; i++) {
	    iMin = i;
		// look for index of smallest number
		for (int j=i+1; j < n; j++) {
		
			if (a[j] < a[iMin])
               iMin = j;
		}
        if (iMin != i) {          
		   	swap(a[iMin], a[i]);
        }
	}
}

void bubblesort( int *a , int n ) {
    int temp; //for swapping
    
    bool swapped = true;
    for (int i = 0 ; i < n - 1 && swapped ; i++) {
    	swapped = false;
        for (int j = 0 ; j < n - 1 ; j++) {
            if ( a[j] > a[j + 1] ) {
            	swapped = true;
            	swap(a[j], a[j+1]);
               // temp = a[j];
               // a[j]=a[j + 1];
               // a[j + 1] = temp;
            }
        }
    }
}

int main()  {
	int  a[] = { 5, 6, 1 , 2, 3, 0};
	bubblesort(a, 6);
	for (int i=0; i<6; i++) 
		cout << a[i] << endl;
	int  b[] = { 5, 6, 1 , 2, 3, 0};	
	selectionsort(b, 6);
	cout << endl << endl << "Selection: " << endl;
	for (int i=0; i<6; i++) 
		cout << b[i] << endl;
	return 0;
	
}
