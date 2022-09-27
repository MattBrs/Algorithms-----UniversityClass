#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n;
    int m;

    vector<vector<ll>> matrix;
    vector<vector<ll>> rowSumMatrix;

    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n >> m;

    for (int i = 0; i < n; i++) {
        vector<ll> tempArray;
        vector<ll> sums;
        ll rowSum = 0;

        for (int j = 0; j < m; ++j) {
            ll tempVal = 0;
            in >> tempVal;

            rowSum += tempVal;

            sums.push_back(rowSum);
            tempArray.push_back(tempVal);
        }

        matrix.push_back(tempArray);
        rowSumMatrix.push_back(sums);
    }

     /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << rowSumMatrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;
    */


    ll sol = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            ll tempMax = 0;
            for (int k = 0; k < n; ++k) {
                ll curr = rowSumMatrix[k][j];

                if (i > 0) {
                    curr -= rowSumMatrix[k][i-1];
                }

                tempMax += curr;

                if (tempMax < 0) {
                    tempMax = 0;
                }

                // tempMax = std::max(tempMax, curr+tempMax);
                sol = std::max(sol, tempMax);

                // cout << rowSumMatrix[k][j] << " - " << (i > 0 ? rowSumMatrix[k][i-1]:0) << " -> " << curr << " , tempMax: "<< (tempMax) <<  "    ";
            }
            // cout << endl << endl;
        }
        // cout << endl;
    }

    out << sol << endl;

    in.close();
    out.close();
    return 0;
}