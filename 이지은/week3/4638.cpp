#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, int k) {
    if (node == nullptr) return new Node(k);
    if (k < node->data) node->left = insert(node->left, k);
    else if (k > node->data) node->right = insert(node->right, k);
    return node;
}

Node* findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

Node* erase(Node* node, int k) {
    if (node == nullptr) return nullptr;

    if (k < node->data) node->left = erase(node->left, k);
    else if (k > node->data) node->right = erase(node->right, k);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = erase(node->right, temp->data);
    }
    return node;
}

void preorder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;
    Node* root = nullptr;

    while (Q--) {
        char cmd;
        int k;
        cin >> cmd >> k;
        if (cmd == 'i') root = insert(root, k);
        else if (cmd == 'r')