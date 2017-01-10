// Calculate how long it takes to run a program
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	
	const clock_t starttime = clock();
	cout << "Enter a char " << endl;
	getchar();
	const clock_t endtime = clock();	
	cout << endl;
	cout << "This took " << float( endtime - starttime ) /  CLOCKS_PER_SEC << " seconds " << endl;
	
}
