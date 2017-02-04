// Demorgan's Law Example
#include <iostream> 
using namespace std;
/* De'Morgans Laws
	!a || !b = !(a && b)
	!a && !b = !(a || b)
*/
	
int main() { 
	cout << " print numbers between 3 and 8 exclusive" << endl;
	// and condition 
	for (int i=0; i< 10; i++) {
		if (i > 3 && i < 8) 
			cout << i << " ";
	}
	cout << endl;
	cout << " Or " << endl;
	// equilavent or condition 
	for (int i=0; i< 10; i++) {
		if (!(i <= 3 || i >= 8))
			cout << i << " ";
		
	}
	cout << endl;
	
	// Second Example
	cout << " print numbers evenly divisible by 7 or 11" << endl;
	for (int i=0; i< 100; i++) {
	
		if (!(i % 7) || !(i % 11))
			cout << i << " ";
	}
	cout << endl;
	for (int i=0; i< 100; i++) {
	
		if (!(i % 7 && i % 11))
			cout << i << " ";
	}
	cout << endl;
}
