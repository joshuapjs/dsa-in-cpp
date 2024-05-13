// This is implementation of a Merge-Sort-Algorithm.
// Author: Joshua Spingler
// Date: 02.05.2024 

# include <vector>
# include <iostream>
using namespace std;

vector<int> merge_sort(vector<int> v);

int main() {
    // Testing the Algorithm.
    vector<int> test_array{6, 27, 12, 3, 42, 25, 7, 1};
    vector<int> output = merge_sort(test_array);
    // Printing the values in the Array.
    for (const auto& element : output) {
    cout << element << " ";
    }
    cout << std::endl;
    return 0;
}

vector<int> merge_sort(vector<int> v) {
    int vector_size = v.size();
    // The base case of the Recursion.
    if (vector_size == 2 && v[0] > v[1]) {
        swap(v[1],v[0]);
        return v;
    }
    else if (vector_size > 2) {
        vector<int> next_v_1 = vector<int>(v.begin(), v.begin() + vector_size / 2);
        vector<int> next_v_2 = vector<int>(v.begin() + vector_size / 2, v.end());
        vector<int> v_1 = merge_sort(next_v_1);
        vector<int> v_2 = merge_sort(next_v_2);

        vector<int> output_v;

        while ((not v_1.empty()) && (not v_2.empty())) {
            // While the case of trying to do calculations without values in the vectors
            // is ruled out, they can be merged, comparing the first values one by one.
            if (v_1.front() < v_2.front()) {
                output_v.push_back(v_1.front());
                v_1.erase(v_1.begin());
            }
            else {
                output_v.push_back(v_2.front());
                v_2.erase(v_2.begin());
            }
        }
        // If one of the vectors is bigger than the other, the values have to be added to 
        // the output as well, by adding them to the end.
        if (not v_1.empty()) {
        	output_v.reserve(output_v.size() + distance(v_1.begin(),v_1.end()));
			output_v.insert(output_v.end(),v_1.begin(),v_1.end());
            }
        else if (not v_2.empty()) {
        	output_v.reserve(output_v.size() + distance(v_2.begin(),v_2.end()));
			output_v.insert(output_v.end(),v_2.begin(),v_2.end());
        }
        return output_v;}
    else {
        return v;
    }
}
