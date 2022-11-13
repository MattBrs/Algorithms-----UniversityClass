#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

struct triangle {
    int pos;
    bool direction;
};
set<int> sols;

void find_solitary(vector<triangle> triangles);

int main() {
    int size;
    vector<triangle> triangles;  // se s -> true, se d -> false

    ifstream in ("input.txt");
    ofstream out ("output.txt");

    in >> size;

    for (int i = 0; i < size; ++i) {
        char temp;
        in >> temp;

        triangle t {i, temp == 's'};
        triangles.push_back(t);

        cout << temp << " ";
    }
    cout << endl;

    find_solitary(triangles);

    out << sols.size() << endl;
    for (int solution : sols) {
        out << solution << " ";
    }
    out << endl;


    in.close();
    out.close();
    return 0;
}

void find_solitary(vector<triangle> triangles) {
    if (triangles.size() <= 1) {
        // solutions.push_back(triangles[0].pos);
        sols.insert(triangles[0].pos);
        return;
    }

    for (int i = 1; i < triangles.size()-1; ++i) {
        vector<triangle> localTriangles = triangles;
        int currIndex = i + (-localTriangles[i].direction);
        int nextIndex = i + (1 - (localTriangles[i].direction*2));
        localTriangles.erase(localTriangles.begin() + nextIndex);
        localTriangles.erase(localTriangles.begin() + currIndex);
        find_solitary(localTriangles);
    }


}