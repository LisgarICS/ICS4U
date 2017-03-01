// Loop through a string using a character pointer

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

int main() {
	//view content and addresses of a integer array
	char hello[] = "Hello World";

	// note how we terminate the loop, end of string is 0  (false).	
	for (char *pch = hello; *pch; pch++) {
		cout << *pch << endl;
	}
}
