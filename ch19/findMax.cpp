// Mr. Creelman Nov. 21 2016
// find local maximum of
// a function between two bounds
// Example of tail recursion
#include <iostream> 
#include <algorithm>    // std::max
using namespace std;

const int lowerBound = -10;
const int upperBound = 10;
float localMax(float u);

// find the maximum of this function from
// -10 to 10
float f(float x) {
	return -x*x + 6*x - 2; 
}

int main() {
	cout << localMax(upperBound) << endl;
	return 0;
}

// recursive function	
float localMax(float upperBound) {
	if (upperBound <= lowerBound)
		return f(lowerBound); 
	return max(f(upperBound), localMax(upperBound-.1));
}

