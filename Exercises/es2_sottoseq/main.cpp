#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main() {
    int size;
    vector<int> vals;

    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> size;
    for (int i = 0; i < size; i++) {
        int temp;
        in >> temp;
        vals.push_back(temp);
    }


    int maxHere = 0;
    int max = 0;

    for (int i = 0; i < size; i++) {
        int currVal = vals.at(i);

        maxHere += currVal;

        if (maxHere > max) {
            max = maxHere;
        }

        if (maxHere < 0) {
            maxHere = 0;
        }
    }
    out << max << "\n";

    in.close();
    out.close();
    return 0;
}
