#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> quicksort(vector<int> unsorted_values);

int main() {
    return 0;
}

vector<int> quicksort(vector<int> unsorted_values, int* l, int* r) {
    if (unsorted_values.size() == 2) {
        if (unsorted_values[0] > unsorted_values[1]) {
            swap(unsorted_values[0], unsorted_values[1]);
            return unsorted_values;
        }
        else {
            return unsorted_values;
        }
    }

    int p = unsorted_values.back();

    return output;
}

