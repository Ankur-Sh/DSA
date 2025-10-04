#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == nullptr || root == p || root == q)
        return root;

    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
        return root;
    }

    return left ? left : right;
}

Node* createNode(int val) {
    return new Node(val);
}

int main() {
    Node* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);
    Node* p = root->left;
    Node* q = root->left->right->right;
    Node* lca = lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    else
        cout << "LCA not found!" << endl;
    return 0;
}
