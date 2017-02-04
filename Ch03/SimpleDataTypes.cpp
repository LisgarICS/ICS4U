/*****************************************************************************
 *	Name:      Mr. Creelman                                                  *
 *	Course:    ICS4U                                                         *  
 *	Date:      Feb 1st, 2017                                                 * 
 *	                                                                         * 
 *	Purpose:  Demonstrate simple data types and i/o,
 *            sizeof function    
              scope
 *	                                                                         *
 *	Usage:                                                                   *
 *	                                                                         *
 *	Revision History: Need more examples of formatting,                      *  
 *	                                                                         *
 *	Known Issues:                                                            *
 *	                                                                         *  
 *****************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;
// global variable  (leads tight coupling)


int main() {
	bool b;
	char c;		// 1 byte
	double d;
	const double e = 2.71;
	float f;
	short s;	// 2 bytes  2^16  from -2^15 to 2^15-1
	int i;		// 4 bytes
	long lo;	// 4 bytes    max 2^31-1
	long long llo;	 /// 8 bytes	
	unsigned int ui;  // 4 bytes
	
	cout << "bool " << sizeof(bool) << endl;   	// same as sizeof(b)
	cout << "char " << sizeof(char) << endl;
	cout << "double " << sizeof(double) << endl;
	cout << "float " << sizeof(float) << endl;
	cout << "int " << sizeof(i) << endl;		// same as sizeof(int)
	cout << "short " << sizeof(s) << endl;
	cout << "long " << sizeof(lo) << endl;
	cout << "long long " << sizeof(llo) << endl; 
	cout << "unsigned int " << sizeof(ui) << endl;
	
	// range of values
	// math 
	for (char ch='A'; ch<='Z'; ch++) {
		cout << ch << " " << char(ch + 'a' - 'A') << endl;
		cout << char(tolower(ch));
	}
	cout << endl;
	f = 1.3634241434;
	cout << fixed << setprecision(2) << f << endl;
	
	return 0;
}
