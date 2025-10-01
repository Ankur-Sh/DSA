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
    void rec(Node* root, int level, vector<int>& res){ 
        if (root == NULL) return; 
        if(level==res.size()) res.push_back(root->val); 
        rec(root->right, level + 1, res); 
        rec(root->left, level + 1, res); 
        }
    vector<int> rightSideView(Node* root) {
        vector<int> res; 
        rec(root,0,res); 
        return res;
    }

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    vector<int> result =rightSideView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
