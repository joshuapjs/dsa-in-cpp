// This is an implementation of a Bubble-Sort-Algorithm.
// Author: Joshua Spingler
// Date: 10.05.2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bubble_sort(vector<int> unsorted_v);

int main() {
    // Defining an Array with test values.
    vector<int> test_array = {4, 6, 1, 76, 4, 5, 8, 1, 2, 4};
    // Sorting the values.
    vector<int> output_v = bubble_sort(test_array);
    cout << "unsorted array:" << endl;
    // Printing each of the values out separately.
    for (const auto& element : test_array) {
        cout << element << " ";
    }
    cout << endl;
    cout << "sorted array:" << endl;
    for (const auto& element : output_v) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}

vector<int> bubble_sort(vector<int> unsorted_v) {
    // upper_bound to not iterate beyond the vector.
    int* upper_bound = &unsorted_v.back();
    // Defining the start point for the iteration.
    int* lower_bound = &unsorted_v[0];
    // Sorted will become true if no value in the list is preceeded
    // by a bigger value.
    bool sorted = false;
    while (sorted == false) {
        sorted = true;
        for (int* i = lower_bound ; i != upper_bound; i++) {
            // If a value is preceeded by a bigger value they need to be swapped.
            if (i != upper_bound && *i > *(i + 1)) {
               sorted = false;
               swap(*i, *(i + 1));
            }
           }
        }
    return unsorted_v;
}

