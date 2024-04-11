#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

// A implementation of binary search in C++.

int binary_search(vector<int> v, int param, int index);

int main(int argc, char const *argv[])
{
	// Testing the algorithm.
	vector<int> test_array{1, 3, 4, 5, 7};
	binary_search(test_array, 4, 4);

	return 0;
}

int binary_search(vector<int> v, int value, int index) {

		int vector_size = v.size();

		if (vector_size == 1) {
			cout << "The Element is on position: " << index << "\n";
			return index;
		}
		if (vector_size == 2) {
			if (value == v[0]) {
				cout << "The Element is on position: " << (index - 1) << "\n";
				return index - 1;
			}
			else if (value == v[1]) {
				cout << "The Element is on position: " << index << "\n";
				return index;
			}
			else {
				cout << "The Element is not in the list." << "\n";
				return index;
			}
		}

		int middle_index = (vector_size - 1) / 2;

		if (v[middle_index] > value)
		{
			int delta = (vector_size - 1) - (middle_index + 1);
			int new_index = index - (middle_index + 1);
			vector<int> new_v2 = vector<int>(v.begin(), v.begin() + delta);
			binary_search(new_v2, value, new_index);
		}
		else if (v[middle_index] == value) {
			int new_index = index / 2;
			cout << "The Element is on position: " << new_index << "\n";
			return 1;
		}
		else {
			vector<int> new_v1 = vector<int>(v.begin() + (middle_index + 1), v.end());
			binary_search(new_v1, value, index);}
		}
