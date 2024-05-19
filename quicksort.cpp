#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> quicksort(vector<int> v);

int main() {
    vector<int> test_array = {4, 6, 1, 76, 4, 5, 8, 1, 2, 4};
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
    if (v.size() == 2) {
        if (v[0] > v[1]) {
            swap(v[0], v[1]);
            return v;
        }
    }
    int p = v.back();
    int l = 0;
    int r = 0;
    while (&v[r] != &p) {
        if (v[l] <= p) {
            l += 1;
        }
        else if ((v[r] <= p) && (l != r)) {
            swap(v[l], v[r]);
            r += 1;
        }
        else if (r < l) {
            r = l;
        }
        else {
            r += 1;
        }
    }
    if (l < v.size() - 1) {
        swap(v[l], v[v.size() - 1]);
        vector<int> lower_values = vector<int>(v.begin(), v.begin() + l);
        vector<int> higher_values = vector<int>(v.begin() + l + 1, v.end());
        vector<int> sorted_lower = quicksort(lower_values);
        vector<int> sorted_higher = quicksort(higher_values);
        sorted_lower[sorted_lower.size() + 1] = v[l];
        sorted_lower.insert(sorted_lower.end(), sorted_higher.begin(), sorted_higher.end());
        return sorted_lower;
    }
    return v;
}

