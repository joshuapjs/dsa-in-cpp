#include <iostream>
#include <vector>

using namespace std;

int bubble_sort(vector<int> unsorted_v);

int main() {
    vector<int> test_array = {4, 6, 1, 76, 4, 5, 8, 1, 2, 4};
    bubble_sort(test_array);
    for (const auto& element : test_array) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}

int bubble_sort(vector<int> unsorted_v) {
    int* upper_bound = &unsorted_v.back();
    bool sorted = false;
    while (sorted == false) {
        int i = 0;
        sorted = true;
        for (int element : unsorted_v) {
           if (&element != upper_bound && element > *(&element + 1)) {
               sorted = false;
               swap(element, *(&element + 1));
           }
        }
    }
    return 0;
}

