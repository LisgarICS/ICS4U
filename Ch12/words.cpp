/*****************************************************************************
 *	Mr. Creelman                                                             *
 *	Course: ICS 4U                                                           *  
 *	Date: March 2, 2017                                                  * 
 *	                                                                         * 
 *	Purpose:  Demonstrate apstring methods       *
 *	                                                                         *
  *                                                                           *
 *	Revision History:                                                        *  
 *	                                                                         *
 *	Known Issues:                         *
 *                                                                           *
 *	                                                                         *  
 *****************************************************************************/
#include <iostream>
#include <apstring.h>
#include <apstring.cpp>

using namespace std;

int main() {
	apstring s = "Pennsylvania Ave has turned into Slytherin House";
	
	// put words on one per line
	int n;
	while ((n = s.find(' ')) != npos) {
		cout << s.substr(0, n) << endl;
		s = s.substr(n+1, s.length()); 
	}
	
	// remove vowels 
	apstring v = "aeiouAEIOU";
	s = "Pennsylvania Ave has turned into Slytherin House";
	for (int i=0; i<s.length(); i++) {
		if (v.find(s[i]) != npos) {
			s = s.substr(0, i) + s.substr(i+1, s.length()); 	
			i--;
		}
	}	
	cout << s << endl;
	return 0;
}


