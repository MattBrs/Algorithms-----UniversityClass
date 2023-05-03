#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool distinct_numbers(int a[], int n);
bool distinct_numbers_rec(int a[], int low, int high, unordered_set<int> &found_numbers);

int main() {
	int n = 7;
	int a[] = {3, 1, 3, 4, 1, 4, 5}; 
	int b[] = {1, 3, 7, 9, 5, 2, 8};

	bool are_numbers_distinct_a = distinct_numbers(a, n);
	bool are_numbers_distinct_b = distinct_numbers(b, n);

	cout << ( are_numbers_distinct_a ? "yes" : "no" ) << endl;
	cout << ( are_numbers_distinct_b ? "yes" : "no" ) << endl;

	return 0;
}

bool distinct_numbers(int a[], int n) {
	unordered_set<int> found_numbers;
	return distinct_numbers_rec(a, 0, n, found_numbers);
}

bool distinct_numbers_rec(int a[], int low, int high, unordered_set<int> &found_numbers) {
	if (low >= high) {
		return true;
	}

	int m = (low + high) / 2;

	if (!found_numbers.insert(a[m]).second) {
		return false;
	}

	return distinct_numbers_rec(a, low, m - 1, found_numbers) && distinct_numbers_rec(a, m + 1, high, found_numbers);
}
