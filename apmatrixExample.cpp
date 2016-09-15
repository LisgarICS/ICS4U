// Test of apmatrix.h installed 
// Example of out of range error
#include <iostream>
#include <iomanip>
#include <apmatrix.h>
using namespace std;

int main() {
	apmatrix<int> m(3, 5, 50);
	
	for (int i= 0; i<m.numrows(); i++) {
		for (int j= 0; j<m.numcols(); j++) {
			cout << setw(4) << m[i][j];
		}
		cout << endl;
	}
	cout << m[3][1];
}
