// This is a module to learn C++ by creating functions enabling me to do iterative mathematical calculations.
// Author: Joshua Spingler
// Date: 09.02.2024

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// This is just a small function to start - As the name suggests will the input just be printed out.
int print_input(int a) {

  printf("%d is the number printed!\n", a);

  return a;
}

// This function models the functionality of a sum sign.
int sum(int* arr, int size) {
  int output_value = 0;

  for (int* p = arr; p <= &arr[4]; p++) {
    output_value += *p;
  }

  printf("Die Summe ist: %d", output_value);

  return output_value;
}

// This function enables the user to perform simple multiplications of two quadratic matrices.
// Yes of course the counting of rows and columns follow zero indexing.
vector< vector<int>> matrix_prod(vector<vector<int>> matA, vector<vector<int>> matB, int n) {

  vector<vector<int>> output_mat(n, vector<int>(n, 0));

  // Perform the calculation
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        int element_a = matA[i][k];
        int element_b = matB[k][j];
        output_mat[i][j] += element_a * element_b;
      }
    }
  }
  return output_mat;
}


int main() {
    vector<vector<int>> matA = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> matB = {
        {2, 0},
        {1, 2}
    };

    int n = 2; // Size of the matrices

    vector<vector<int>> result = matrix_prod(matA, matB, n);

    // Output the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
