#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n1, n2;
    ifstream in("input.txt");
    in >> n1 >> n2;
    ofstream out("output.txt");
    out << (n1+n2) << "\n";
    in.close();
    out.close();
    return 0;
}
