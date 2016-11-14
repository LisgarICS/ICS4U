#include <iostream> 
#include <apstring.h>
// Print a sentence with the words in reverse order.
#include <apstring.cpp>

using namespace std;
void printBack(apstring str);

int main() {
	apstring sentence;
	
//	getline(cin, sentence);
	sentence = "First we take Manhatten then we take Berlin";
	printBack(sentence);

 	cout << endl;
	
}

void printBack(apstring str) {
	int n = str.find(" ");
	if (n == npos)  {
		cout << str << " ";
		return;
	}	
	printBack(str.substr(n+1, str.length()));
	cout << str.substr(0, n) << " ";	
	return;
}
