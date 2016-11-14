// Print first 100 Fibonacci Numbers.
// Save intermediate results for efficiency.
#include <iostream> 
unsigned long long Fib(int n);
using namespace std;

int main() {

	for (int i= 0; i < 100; i++)
 		cout << Fib(i) << " ";	
 	cout << endl;
	
}

unsigned long long Fib(int n) {
	static unsigned long long f[100] = {1, 1, 0};
	
	if (f[n] != 0)
	  return f[n];
	f[n-1] = Fib(n-1);
	f[n-2] = Fib(n-2);
	return f[n-1] + f[n-2];
}
	
