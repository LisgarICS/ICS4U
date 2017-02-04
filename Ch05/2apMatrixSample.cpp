/*****************************************************************************
 *	Mr. Creelman   ICS4U     September 2016                                  *
 *	Course:                                                                  *  
 *	Date:                                                                    * 
 *	                                                                         * 
 *	Purpose:  Show usage of apvector, apmatrix                               *
 *			  Show overloading of print function                             *
 *	                                                                         *
 *	Usage:                                                                   *
 *	                                                                         *
 *	Revision History:                                                        *  
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *  
 *****************************************************************************/
#include <iostream>
#include <iomanip>
#include <apmatrix.h>

using namespace std;
void print(const apmatrix<int> &m1);
void print(const apvector<char> &v);

int main() {
	apvector<char> v;
	apmatrix<int> m(5, 10, 0);
	
	// add alphabet to vector v	
	for (char ch='a'; ch<='z'; ch++) {
		v.push_back(ch);
	}
	
	// initialize m to look like times table
	for (int i=0; i<m.numrows(); i++) {
		for (int j=0; j<m.numcols(); j++) {
		//	cout << i << " " << j << endl;
			m[i][j] = (i+1) * (j+1);
		}
	}
	print(v);
	cout << endl << endl;
	print(m);
}

// print vector of characters
void print(const apvector<char> &v1) {
	for (int i=0; i<v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
}

// print matrix of integers
void print(const apmatrix<int> &m1) {
	for (int r=0; r<m1.numrows(); r++) {
		for (int c=0; c<m1.numcols(); c++) {
			cout << fixed << setw(4) << m1[r][c] << " ";
		}
		cout << endl;
	}
}
