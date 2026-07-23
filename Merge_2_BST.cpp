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

// 2nd
Node* buildBST(vector<int> arr) {
    Node* root = NULL;

    for(int val : arr) {
        root = insert(root, val);
    }

    return root;
}

// 3rd
void inorder(Node* root, vector<int>& arr) {
    if (root == NULL) return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// 4th
Node* buildBSTFromSorted(vector<int>& arr, int start, int end) {
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBSTFromSorted(arr, start, mid - 1);
    root->right = buildBSTFromSorted(arr, mid + 1, end);

    return root;
}

// 1st
Node* mergeBST(Node* root1, Node* root2) {
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> temp;
    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size()) {
        if(arr1[i] < arr2[j]) {
            temp.push_back(arr1[i]);
            i++;
        } else {
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while(i<arr1.size()) {
        temp.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size()) {
        temp.push_back(arr2[j]);
        j++;
    }

    return buildBSTFromSorted(temp, 0, temp.size()-1);
}

int main() {
    vector<int> arr1 = {8, 2, 1, 10};
    vector<int> arr2 = {5, 3, 0};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    Node* root = mergeBST(root1, root2);
    vector<int> seq;
    inorder(root, seq);
    for(int v : seq) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}