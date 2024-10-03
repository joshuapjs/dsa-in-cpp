#include <iostream>
#include <vector>

using namespace std;

vector<int> quicksort(vector<int> v);

int main() {
    vector<int> test_array = {4, 5, 7, 1, 6, 74, 2, 56, 7, 2, 654};
    // Sorting the values.
    vector<int> output_v = quicksort(test_array);
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

vector<int> quicksort(vector<int> v) {
    if (v.size() == 1 || v.empty()) {
            return v;
        }
    if (v.size() == 2 && v[0] > v[1]) {
            swap(v[0], v[1]);
            return v;
        }
    int l = 0;
    int r = v.size() - 2;
    int pivot = v.back();

    while(l < r) {
        while (v[l] <= pivot && l <= r) {
            l++;
        }
        while (v[r] > pivot && l <= r) {
            r--;
        }
        if (l < r) {
            swap(v[r], v[l]);
        }
        }
    if (v[l] > pivot) {
            swap(v[l], v.back());
    }
    vector<int> lower_val = vector<int>(v.begin(), v.begin() + l);
    vector<int> higher_val = vector<int>(v.begin() + l + 1, v.end());

    vector<int> sorted_lower = quicksort(lower_val);
    vector<int> sorted_higher = quicksort(higher_val);

    sorted_lower.push_back(v[l]);
    sorted_lower.insert(sorted_lower.end(), sorted_higher.begin(), sorted_higher.end());

    return sorted_lower;
}

