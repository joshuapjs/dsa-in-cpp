// This should be an implementation of a merge-sort algorithm in C++.
// Author: Joshua Spingler
// Date: 02.05.2024 

# include <vector>
# include <iostream>
using namespace std;

vector<int> merge_sort(vector<int> v);

int main() {
    vector<int> test_array{5, 7, 1, 28, 11, 2, 6, 4};
    vector<int> output = merge_sort(test_array);
    for (const auto& element : output) {
    cout << element << " ";
    }
    cout << std::endl;

    return 0;
}

vector<int> merge_sort(vector<int> v) {
    int vector_size = v.size();
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
            if (v_1.front() < v_2.front()) {
                output_v.push_back(v_1.front());
                v_1.erase(v_1.begin());
            }
            else {
                output_v.push_back(v_2.front());
                v_2.erase(v_2.begin());
            }
        }
        if (not v_1.empty()) {
            int v_1_size = v_1.size();
            for (int i; i < v_1_size; i++) {
                output_v.push_back(v_1[i]);
            }}
        else if (not v_2.empty()) {
            int v_2_size = v_2.size();
            for (int i; i < v_2_size; i++) {
                output_v.push_back(v_2[i]);
            }
        }
        return output_v;}
    else {
        return v;
    }
}
