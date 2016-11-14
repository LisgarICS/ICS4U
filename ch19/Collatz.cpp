// Find the Collatz number of a given integer.
#include <iostream> 

using namespace std;
int Collatz(int n);

int main() {
	int n;
	cout << "Enter a number: "; // insert
	cin >> n;  // extraction
	int count = Collatz(n);
	cout << "Collatz Number is " << count << endl;
	
}

int Collatz(int n) {
	static int c = 0;

	cout << n << " " << endl;
	if (n == 1) {
		cout << "Finished" << endl;
		return c;
	}
	c++;
	if (n % 2 == 0) 
		Collatz(n/2);
	else
		Collatz(3*n+1);
}
