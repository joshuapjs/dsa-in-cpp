#include <iostream>
#include <vector>

using namespace std;

vector<int> bubble-sort;

int main() {
    vector<int> test_array = {4, 6, 1, 76, 4, 5, 8, 1, 2, ,4};
    vector<int> output = bubble-sort;
    for (const auto& element : output) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}

vector<int> bubble-sort(vector<int> unsorted_v) {
    int* upper_bound = &v.back();
    while (&v[0] != upper_bound) {
        int i = 0;
        bool end_reached = false;
        while (v[i] > v[i + 1] && end_reached != true) {
            v[i].swap(v[i + 1]);
            i += 1;
            if (&v[i + 1] == upper_bound) {
                end_reached = true;
            }
        }
        upper_bound -= 1;
    }
}

