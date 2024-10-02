/*this is an exploratory implementation of a heap in c++.
* every step is documented in a vary detailed manner as it is intended for educational purposes.
*
* author: joshua spingler
* date: 30.08.2024
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Heap {

	// We declare two basic functions, necessary to repair the heap-structure if there is a violation
	// after a new value was added via add_data.
	void repair_up(int index) {
		// The array size has to be bigger than 1 (otherwise there is no need to assign a parent to the vertex).
		// There will be some abstraction within the function so that an index of 0 can be used but within the method
		// there will be 1-Indexing and the Algorithm will expect that as well.
		// However the index must be below the size of the array -1 otherwise there will be undefined behaviour.
		if ((data_array.size() > 1) && 
				(index > 0) && 
				(index <= data_array.size() - 1)) {

			// The index will be increased by one so that the Algorithm works as defined.
			// The current parent of the vertex in question has index / 2 in the definition I'm using.
			int father = ((index + 1) / 2)  - 1;

			while (data_array[father] < data_array[index]) {
				iter_swap(data_array.begin() + index, 
						data_array.begin() + father);
				index = father;
				father = ((index + 1) / 2) - 1;
			}
		}
	};

	void repair_down(int index) {
		if ((data_array.size() > 1) && 
				(index >= 0) && 
				(index < data_array.size() - 1)) {

			// define potential child vertecies and the last index assuming 1-Indexation.
			int possible_child_index_a = ((index + 1) * 2) - 1;
			int possible_child_index_b = possible_child_index_a + 1;
			int last_possible_index = data_array.size() - 1;

			// Decision if child vertecies can exist.
			// If not the value of the child be set equal with the current index and thereby will never be 
			// bigger or smaller that the current index.
			int child_index_a = possible_child_index_a <= last_possible_index ? possible_child_index_a : index;
			int child_index_b = possible_child_index_b <= last_possible_index ? possible_child_index_b : index;

			while ((data_array[index] < data_array[child_index_a]) ||
					(data_array[index] < data_array[child_index_b])) {

				if (data_array[child_index_a] > data_array[child_index_b]) {
					iter_swap(data_array.begin() + index,
							data_array.begin() + child_index_a);
					index = child_index_a;
				}
				else {
					iter_swap(data_array.begin() + index,
							data_array.begin() + child_index_b);
					index = child_index_b;
				}

				possible_child_index_a = ((index + 1) * 2) - 1;
				possible_child_index_b = possible_child_index_a + 1;

				// Decision if child vertecies can exist.
				// If not the value of the child be set equal with the current index and thereby will never be 
				// bigger or smaller.
				child_index_a = possible_child_index_a <= last_possible_index ? possible_child_index_a : index;
				child_index_b = possible_child_index_b <= last_possible_index ? possible_child_index_b : index;
			};
		}

	};

	public:
	
	// Other necessesary information like heap-size can be derived from the vector itself.
	vector<int> data_array;
	
	Heap(vector<int> start_array) : data_array(start_array) {};

	// As public we first declare the Destructor of the class.
	// After those to specifications we declare public functions such as delete_max.
	~Heap() {
		// When the Heap is destructed the memory of the arrays must be freed.
		data_array.clear();
	};

	void add(int data_point) {
		// push_back adds an element at the End of the veoctor in increases the size if necessary.
		data_array.push_back(data_point);
	};

	int delete_max() {
		// Sets the most recent Element to Prioritiy 0, calls repair_down and returns the maximum of the heap.
		if (data_array.size() > 1) {
			int max = data_array[0];
			data_array[0] = data_array.back();
			repair_down(0);
			return max;
		} else if (data_array.size() == 1) {
			int max = data_array[0];
			data_array.pop_back();
			return max;
		} else {
			cout << "No values in the Heap" << endl;
			return 0;
		}
	};

	int change_priority(int index, int new_priority) {
		int old_priority = data_array[index];
		data_array[index] = new_priority;
		if (new_priority < old_priority) {
			repair_down(index);
			return 1;
		} else if (new_priority > old_priority) {
			repair_up(index);
			return 1;
		} else {
			return 0;
		}
	};  

	void build_heap() {
		int end_index = data_array.size() - 1;
		int start_index = 0;
		int index = 0;
		
		while (end_index > 0) {
			start_index = (end_index + 1) / 2;
			index = start_index;
			
			while (index <= end_index) {
				int father = ((index + 1) / 2) - 1;
				if (index == start_index) {
					start_index = father;
				}
				if ((index + 1) <= end_index) {
					index++;
				}
				repair_down(father);
				index++;
			}
			end_index = start_index * 2;
		}
		repair_down(0);
	};

	int read();
	void remove();
	
	};

int main() {
	vector<int> test_vector{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };
	Heap test_heap{ test_vector };
	for (int i = 0; i <= (test_heap.data_array.size() - 1); i++) {
		cout << test_heap.data_array[i] << " ";
	}
	cout << endl;
	test_heap.build_heap();
	for (int i = 0; i <= (test_heap.data_array.size() - 1); i++) {
		cout << test_heap.data_array[i] << " ";
	};
	cout << endl;
	return 0;
	}

