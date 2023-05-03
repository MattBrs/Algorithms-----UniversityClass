#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print_list(const vector<int> &list);
void merge_sort(vector<int> &list);
void merge_sort(vector<int> &list, int low, int high);
void merge(vector<int> &list, int low, int mid, int high);

int main() {
	vector<int> unordered_list;

	unordered_list.push_back(3);
	unordered_list.push_back(1);
	unordered_list.push_back(5);
	unordered_list.push_back(6);
	unordered_list.push_back(2);
	unordered_list.push_back(8);
	unordered_list.push_back(3);
	unordered_list.push_back(7);
	unordered_list.push_back(0);
	unordered_list.push_back(10);

	print_list(unordered_list);
	merge_sort(unordered_list);
	print_list(unordered_list);

	return 0;
}

void print_list(const vector<int> &list) {
	for (auto item: list) {
		cout << item << " ";
	}

	cout << endl;
}

void merge_sort(vector<int> &list) {
	merge_sort(list, 0, list.size() - 1);
}

void merge_sort(vector<int> &list, int low, int high) {
	if (low >= high) {
		return;
	}
	int mid = ((low + high) / 2);

	merge_sort(list, low, mid);
	merge_sort(list, mid + 1 , high);
	merge(list, low, mid, high);
}

void merge(vector<int> &list, int low, int mid, int high) {
	int left_subarray_size = mid - low + 1;
	int right_subarray_size = high - mid;

	vector<int> left_subarray (left_subarray_size);
	vector<int> right_subarray (right_subarray_size);

	// popola i sottovettori
	for (int i = 0; i < left_subarray_size; i++) {
		left_subarray[i] = list[low + i];
	}

	for (int i = 0; i < right_subarray_size; i++) {
		right_subarray[i] = list[mid + 1 + i];
	}

	int left_index = 0;
	int right_index = 0;
	int whole_index = low;

	// sostituisci nella lista originale i valori dei sottovettori in ordine crescente
	while (left_index < left_subarray_size && right_index < right_subarray_size) {
		if (left_subarray[left_index] <= right_subarray[right_index]) {
			list[whole_index] = left_subarray[left_index];
			left_index++;
		} else {
			list[whole_index] = right_subarray[right_index];
			right_index++;
		}

		whole_index++;
	}

	// inserisci i rimanenti valori del sottovettore di sinistra nella lista principale
	while (left_index < left_subarray_size) {
		list[whole_index] = left_subarray[left_index];
		left_index++;
		whole_index++;
	}

	// inserisci i rimanenti valori del sottovettore di destra nella lista principale
	while (right_index < right_subarray_size) {
		list[whole_index] = right_subarray[right_index];
		right_index++;
		whole_index++;
	}
}