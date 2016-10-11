#include <iostream>
#include <apstring.h>
#include <apstring.cpp>
using namespace std;

int main() {
	apstring mathStr;
	apstring mathStr1("404 71 +");
	apstring mathStr2(mathStr1);
	apstring s = "JEllo";
	apstring filename ="te.dat";
	
	// get last three digits of an apstring
	cout << s.substr(s.length()-3, s.length()) << endl;
	
	// get an apstring from the user that can include space	
	cout << "Enter an equation: ";	
	getline(cin, mathStr); 
//	cout << mathStr << endl;
	cout << mathStr1 << endl;
//	cout << mathStr2 << endl;
	
	// find location of first space
	int n = mathStr1.find(" ");
	cout << n << endl;
	// copy two characters starting at position 4
	apstring number = mathStr1.substr(4, 2);
	cout << number << endl; 
	// copy the first n characters
	apstring number2 = mathStr1.substr(0, n);
	cout << number2 << endl;
	// convert an apstring to an integer
	int num = atoi(number.c_str());
	cout << num + 10 << endl;
		
}
