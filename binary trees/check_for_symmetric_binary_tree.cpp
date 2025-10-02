#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
    bool isSymmetricHelp(Node* left,Node*right) {
        if(left==nullptr || right==nullptr) return left==right;
        if(left->val !=right->val) return false;
        return isSymmetricHelp(left->left,right->right) && isSymmetricHelp(left->right,right->left);
    }
    bool isSymmetric(Node* root) {
        return root==nullptr || isSymmetricHelp(root->left,root->right);
    }

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    bool result =isSymmetric(root);
    cout << result;
    return 0;
}
