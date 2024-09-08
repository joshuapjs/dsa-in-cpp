/*This is an exploratory implementation of a Heap in C++.
* Every step is documented in a vary detailed manner as it is intended for educational purposes.
*
* Author: Joshua Spingler
* Date: 30.08.2024
*/

#include <iostream>
#include <cstring>
using namespace std;

class Heap {

	// As we use the class keyword, as a default, members will be initialized as private.
	// I use the keyword anyway for better readability.
	// As private I declare all variables and functions that will be called and used only internally.
	private:
	int heap_size;
	
	// We set two pointers for both arrays to later create two full arrays.
	int* data_array;
	int* not_empty_array;

	// We declare two basic functions, necessary to repair the heap-structure if there is a violation
	// after a new value was added via add_data.
	void repair_up();
	void repair_down();
	public:

	// As Public we first declare the Constructor and the Destructor of the class.
	// After those to specifications we declare public functions such as delete_max.
		Heap(int s) : heap_size(s) {

			// Here we create the new arrays.
			data_array = new int[heap_size];
			not_empty_array = new int[heap_size];

			// The values of the arrays must be zero.
			memset(data_array, 0, heap_size * sizeof(int));
			memset(not_empty_array, 0, heap_size * sizeof(int));
		}
		~Heap() {

			// When the Heap is destructed the memory of the arrays must be freed.
			delete[] data_array;
			delete[] not_empty_array;
		}
		void add_data(int data_point) {

			// A new data point is added to the next possible position of the array.
			// TODO Better understand how a Heap works and if necessary do a correction.
			if (data_point == 0) {
				// TODO An error should be thrown here.
				cout << "Zero values are not allowed." << endl;
			}
			else {

				// If the value is not zero which is not a valid data_point 
				// Find in the not_empty_array the next empty place.
				for (int i = 0; i <= heap_size; i++) {
					if (not_empty_array[i] == 0) {
						data_array[i] = data_point;
						not_empty_array[i] = 1;
						break;
					}
					else {
						continue;
					}
					}
				}
		}
		int delete_max();
	};

int main() {
	cout << "Just a test" << endl;
	Heap heap{ 2 };
	}

