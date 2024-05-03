// This should be an implementation of a merge-sort algorithm in C++.
// Author: Joshua Spingler
// Date: 02.05.2024 

# include <vector>
# include <iostream>
using namespace std;

vector<int> merge_sort(vector<int> v);

int main {

	vector<int> test_array{5, 7, 1, 28, 11, 2, 6, 4};
	int merge_sort(test_array);

	return 0;
}

vector<int> merge_sort(vector<int> v) {
	int vector_size = v.size();
	vector<int> output_v;

	if (vector_size = 2) {
		if (v.front() > v.back()) {
			vector<int> output_v{v.back(), v.front()};
			return output_v;
		}
		else {
			vector<int> output_v{v.front(), v.back()};
			return output_v;
		}
	}
	else {
		int new_index = vector_size / 2;
		merge_sort(vector<int> v(v.begin(), v.begin() + vector_size));
		merge_sort(vector<int> v(v.begin() + vector_size, v.end()));
	}

}
