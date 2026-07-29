#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }    
};

//Insert a node in BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

//Find Predecessor & Successor in BST

vector<int> getPredSucc(Node* root, int key) {
    Node* pred = NULL;
    Node* succ = NULL;

    while (root != NULL) {
        if (root->data == key) {
            // Find predecessor
            if (root->left != NULL) {
                Node* temp = root->left;
                while (temp->right != NULL) {
                    temp = temp->right;
                }
                pred = temp;
            }

            // Find successor
            if (root->right != NULL) {
                Node* temp = root->right;
                while (temp->left != NULL) {
                    temp = temp->left;
                }
                succ = temp;
            }
            break;
        } else if (key < root->data) {
            succ = root; // Update successor
            root = root->left;
        } else {
            pred = root; // Update predecessor
            root = root->right;
        }
    }

    vector<int> result(2, -1);
    if (pred != NULL) result[0] = pred->data;
    if (succ != NULL) result[1] = succ->data;

    return result;
}

int main() {

    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    vector<int> ans = getPredSucc(root, key);
    cout << "Predecessor: " << ans[0] << endl;
    cout << "Successor: " << ans[1] << endl;

    return 0;

}