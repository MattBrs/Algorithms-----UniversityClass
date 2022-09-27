#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct triangle {
    int pos;
    bool direction;
};

int main() {
    int size;
    vector<triangle> triangles;  // se d -> true, se s -> false
    vector<int> solutions;

    ifstream in ("input.txt");
    ofstream out ("output.txt");

    in >> size;

    for (int i = 0; i < size; ++i) {
        char temp;
        in >> temp;

        triangle t {i, temp == 'd'};
        triangles.push_back(t);

        cout << temp << " ";
    }
    cout << endl;



    for (int i = 1; i < size-1; ++i) {
        vector<triangle> tempVect = triangles;
        int tempIndex = i;
        size_t tempSize = tempVect.size();

        while (tempSize > 1 && tempIndex > -1 && tempIndex != tempSize) {
            bool tempDir = tempVect[tempIndex].direction;

            tempVect.erase(tempVect.begin() + tempIndex);
            tempSize--;

            if (tempSize == 1) {
                solutions.push_back(tempVect.at(0).pos);
                break;
            }

            if (!tempDir) { // se true e' destra, altrimenti sinistra
                tempIndex--;
            }
        }
        // cout << tempIndex << " ";
    }

    // cout << endl << endl;

    for (int i = 0; i < solutions.size(); ++i) {
        cout << solutions[i] << " ";
    }

    cout << endl;

    return 0;
}
