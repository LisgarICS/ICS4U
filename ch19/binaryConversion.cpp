// Convert decimal to binary number
#include <iostream>
using namespace std;
long binary(int dec);
int main() {
	int number;
	
	cout << "Enter decimal number: ";	
	cin >> number;
	cout << "Number in Binary is " << binary(number) << endl;
	cout << "Number in Hex is " << hex << number << endl;
	return 0;
}


long binary(int dec) {
	if (dec != 0) {
		if (dec % 2 == 0) 
			return 10 * binary(dec / 2);
		else
			return 10 * binary(dec / 2) + 1;
	}
	return 0;
		 		
}
