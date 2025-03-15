#include<iostream>
#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

class FibonacciHeap;

struct Vertex {
    int priority = 0;
    int value = 0;
    Vertex* parent = nullptr;
    vector<Vertex*> children;

    void ClearChildren() {
        children.clear();
    }
};

class FibonacciHeap {

    vector<Vertex*> root_list;
    vector<Vertex*> marked;
    Vertex* minimum = nullptr;
    unordered_map<int, Vertex*> degree_map; 

   int KeyIsPresent(int key) {
       // Searching for element with key
       if (degree_map.find(key) == degree_map.end()) {
            return 0;
       } else { 
            return 1;
       }
    }

    int CleanRoots(int children_amount, Vertex* root) {

        if (KeyIsPresent(children_amount)) {
            Vertex* second_root = degree_map.at(children_amount);
            if (root->priority < second_root->priority) {
                auto element_found = std::find((root->children).begin(), (root->children).end(), second_root);
                if (element_found == (root->children).end()) { (root->children).push_back(second_root); }
                second_root->parent = root;
                int modified_children_amount = (root->children).size();
                degree_map.erase(children_amount);
                CleanRoots(modified_children_amount, root);
            } else {
                auto element_found = std::find((second_root->children).begin(), (second_root->children).end(), root);
                if (element_found == (second_root->children).end()) { (second_root->children).push_back(root); }
                root->parent = second_root;
                int modified_children_amount = (second_root->children).size();
                degree_map.erase(children_amount);
                CleanRoots(modified_children_amount, second_root);
            }
        } else {
            root->parent = nullptr;
            degree_map.insert(std::make_pair(children_amount, root));
            return -1;
        }
    };

    void HandleMarkedVertex(Vertex* decreased_key_vertex) {
        Vertex* parent_vertex = decreased_key_vertex->parent;
        // We check if the parent vertex is already a marked vertex.
        auto element_found = std::find(marked.begin(), marked.end(), parent_vertex);
        if (element_found == marked.end()) { // In this case the vertex is not a marked vertex.
            // We copy the value of the parent_vertex pointer, so that we can Override the cell.
            // TODO Maybe we can even move it ?
            Vertex tmp = *parent_vertex;
            marked.push_back(&tmp);  // We "mark" the vertex by pushing it in the marked vector.
            parent_vertex = nullptr;

            // We push the whole subtree with the decresed_key_vertex to the root_list.
            Insert(decreased_key_vertex);
            // We update the children vector of the parent Vertex accordingly.
            std::erase(tmp.children, decreased_key_vertex);
            return;
        } else {
            for (auto child : decreased_key_vertex->children) {
                child->parent = nullptr;
                Insert(child);
            }
            decreased_key_vertex->ClearChildren();
            std::erase(marked, parent_vertex);

            Insert(decreased_key_vertex);
            // We update the children vector of the parent Vertex accordingly.
            std::erase(parent_vertex->children, decreased_key_vertex);
            if (parent_vertex != nullptr) {
                Vertex tmp = *parent_vertex;
                parent_vertex = nullptr;
                HandleMarkedVertex(&tmp);
            }
        }
    }

    public:

    void Insert(Vertex* other_value) { 
        root_list.push_back(other_value);
        if (minimum != nullptr) {
            minimum = other_value->priority < minimum->priority ? other_value : minimum;
        } else {
            minimum = other_value;
        }
    }

    Vertex GetMin() {

        for (auto root : root_list) {
            cout << root->priority << " ";
        }
        cout << endl;

        Vertex* min_vertex = minimum;
        
        for (auto child : (min_vertex->children)) {
            child->parent = nullptr;
            root_list.push_back(child);
        }

        if (minimum) {
            std::erase(root_list, minimum);
        } else {
            throw std::runtime_error( "The Root List is empty. Please add an Element before trying to remove it." );
        }

        for (auto root : root_list) {

            if (root->parent != nullptr) {
                continue;
            }

            int children_amount = (root->children).size();
            CleanRoots(children_amount, root);
        }
        degree_map.clear();

        auto bad_roots = std::erase_if(root_list, [](Vertex* x) { return (x->parent) != nullptr; });

        for (auto root : root_list) {
            cout << root->priority << " ";
        }
        cout << endl;

        minimum = nullptr;
        for (auto root : root_list) {
                if (minimum != nullptr) {
                    minimum = root->priority < minimum->priority ? root : minimum;
                } else {
                    minimum = root;
                }
        }

        return *min_vertex;
        }

    void DecreaseKey(Vertex* vertex_to_change, int new_priority) {
        if (vertex_to_change->priority < new_priority) {
            throw std::runtime_error( "new_priority must be smaller that the current one." );
        }

        vertex_to_change->priority = new_priority;
        Vertex* parent_vertex = vertex_to_change->parent;

        // Its possible that the decreased priority lead to a new minimum => update
        if (parent_vertex == nullptr) { 
            for (auto root : root_list) {
                    if (minimum != nullptr) {
                        minimum = root->priority < minimum->priority ? root : minimum;
                    } else {
                        minimum = root;
                    }
            }
            return;
        }

        if (parent_vertex->priority > new_priority) {
            HandleMarkedVertex(vertex_to_change);
        }

        for (auto root : root_list) {
                if (minimum != nullptr) {
                    minimum = root->priority < minimum->priority ? root : minimum;
                } else {
                    minimum = root;
                }
        }
    }
};

int main() {
    Vertex v;
    v.priority = 4;
    v.value = 5;

    Vertex w;
    w.priority = 6;
    w.value = 5;

    Vertex a;
    a.priority = 2;
    a.value = 1;

    Vertex x;
    x.priority = 3;
    x.value = 2;

    Vertex y;
    y.priority = 7;
    y.value = 8;

    Vertex z;
    z.priority = 0;
    z.value = 9;

    FibonacciHeap f;
    f.Insert(&v);
    f.Insert(&w);
    f.Insert(&a);
    f.Insert(&x);
    f.Insert(&y);
    f.Insert(&z);
    f.DecreaseKey(&y, 0);
    f.DecreaseKey(&v, 0);
    Vertex output1 = f.GetMin();
    cout << output1.priority << endl;
    cout << output1.value<< endl;
    Vertex output2 = f.GetMin();
    cout << output2.priority << endl;
    cout << output2.value<< endl;
    Vertex output3 = f.GetMin();
    cout << output3.priority << endl;
    cout << output3.value<< endl;
    Vertex output4 = f.GetMin();
    cout << output4.priority << endl;
    cout << output4.value<< endl;
    Vertex output5 = f.GetMin();
    cout << output5.priority << endl;
    cout << output5.value<< endl;
    Vertex output6 = f.GetMin();
    cout << output6.priority << endl;
    cout << output6.value<< endl;
    cout << "TEST" << endl;
}

