// Sept 2017  Vector Sample
// Mr. Creelman
// ICS4U
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
const char *fileName = "list1.dat";

int main() {
    vector<int> v; //array

    ifstream inFile(fileName);
    if (! inFile.is_open()) {
        cerr << "Can't open " << fileName << endl;
        return 1;
    }

    int number;
    while (inFile >> number) {
        // if using apvector, need to explicitly resize
        v.push_back(number);
    }

    return 0;
}

// want to change v
void sample(vector<int> &v) {
}

// don't want to change v
void sample(const vector<int> &v) {
//    v[0] = 0;
}
