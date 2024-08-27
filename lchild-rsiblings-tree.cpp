#include <iostream>

using namespace std;


struct CSVertex {
	int num;
	// This is the left child of the CSVertex.
	int lchild;
	// Those are the right children of the CSVertex.
	int rsiblings[1];  // This value could possibly be adjusted.
	};

struct ChildSiblingsTree{
	CSVertex all[3];
	};


int main() {
	// Initialize the ChildSiblingsTree and the vertecies.
	ChildSiblingsTree g;
	CSVertex root{1, 2, 3};
	CSVertex first{2, 4, 5};
	CSVertex second{3, 6, 7};
	// Aggregate vertecies in ChildSiblingsTree.
	g.all[0] = root;
	g.all[1] = first;
	g.all[2] = second;
	// Print each CSVertex with his children.
	for (CSVertex i : g.all) {
		cout << "Parent " << i.num << " : Children " << i.lchild << " ";
		for (int j : i.rsiblings) {
		cout << j << " " << endl;
			};
		};
	return 0;
	}

