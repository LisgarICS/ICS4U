// Remove a word from an apstring
// Demonstrating the methods find and substr of the apstring class
#include <iostream>
#include <apstring.h>
#include <apstring.cpp>

using namespace std;


int main() {
	apstring str = "fool me once, fool me twice fool me chicken soup with rice";
	apstring word = "fool";
	int n = str.find(word);
	
	// loop while n is a position in the string,  npos means it failed to find the word
	while (n != npos ) {
		cout << word << " found at position "  << n << endl;
		str = str.substr(0, n) + str.substr(n + word.length(), str.length());
		cout << str << endl;
		n = str.find(word);
 	}
}
