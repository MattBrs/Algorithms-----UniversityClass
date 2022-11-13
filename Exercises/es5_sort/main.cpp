#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void mergeSort(vector<int> &vect, int begin, int end);
void merge(vector<int> &vect, const int start, const int mid, const int end);
void printArray(const vector<int> &vect, ofstream &out);

int main() {
    // bubble sort, merge sort, insertion sort, selection sort
    ifstream in ("input.txt");
    ofstream  out ("output.txt");

    int size = 0;
    vector<int> numberList;

    in >> size;

    for (int i = 0; i < size; ++i) {
        int tempInput;
        in >> tempInput;

        numberList.push_back(tempInput);
    }

    mergeSort(numberList, 0, numberList.size()-1);
    printArray(numberList, out);

    in.close();
    out.close();
    return 0;
}

void mergeSort(vector<int> &vect, int begin, int end) {

    if (begin >= end) {
        return;
    }

    int mid = (begin+end)/2;

    mergeSort(vect, begin, mid);
    mergeSort(vect, mid+1, end);
    merge(vect, begin, mid, end);
}
void merge(vector<int> &vect, const int left, const int mid, const int right) {
    vector<int> leftVect;
    vector<int> rightVect;
    
    int leftVectStart = left;
    int rightVectStart = mid + 1;

    for (int i = leftVectStart; i < rightVectStart; ++i) {
        leftVect.push_back(vect[i]);
    }
    for (int i = rightVectStart; i <= right; ++i) {
        rightVect.push_back(vect[i]);
    }

    /*
    cout << "start -> " << left << ",  mid -> " << mid << ", end -> " << right << endl;

    cout << "left ->";
    printArray(leftVect);
    cout << "right ->";
    printArray(rightVect);

    cout << "------------------------" << endl;
    */

    int leftIndex = 0;
    int rightIndex = 0;
    int vectIndex = left;

    while (leftIndex < leftVect.size() && rightIndex < rightVect.size()) {
        if (leftVect[leftIndex] <= rightVect[rightIndex]) {
            vect[vectIndex] = leftVect[leftIndex];
            leftIndex++;
        } else {
            vect[vectIndex] = rightVect[rightIndex];
            rightIndex++;
        }

        vectIndex++;
    }

    while (leftIndex < leftVect.size()) {
        vect[vectIndex] = leftVect[leftIndex];
        vectIndex++;
        leftIndex++;
    }

    while (rightIndex < rightVect.size()) {
        vect[vectIndex] = rightVect[rightIndex];
        vectIndex++;
        rightIndex++;
    }
}


void printArray(const vector<int> &vect, ofstream &out) {
    for (auto i:vect) {
        out << i << " ";
    }
    out << endl;
}
