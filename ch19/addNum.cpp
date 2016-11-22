// note the order of the recursive calls.
// from https://www.youtube.com/watch?v=eU5QCoR5uxg
#include <iostream> 
using namespace std;

int addNum(int n);

int main() {
	cout << addNum(8) << endl;
}

int addNum(int x) {
	cout << "Calling addNum(" << x << ")" << endl;
	if (x == 0) 
		return 1;
	if (x == 1)
		return 2;
	if (x % 2 == 0)  // even
		return addNum(x/2) + addNum(x/2) + 1;
	return addNum((x+1)/2) + addNum((x+1)/2);
}
	
