#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
    bool getPath(Node* root,vector<int>& arr,int val){
        if(!root) return false;
        arr.push_back(root->val);
        if(root->val==val) return true;
        if(getPath(root->left,arr,val) || getPath(root->right,arr,val)) return true;
        arr.pop_back();
        return false;
    }
    vector<int> rootToNode(Node* root, int val){ 
        vector<int> arr;
        if (root == NULL) return arr;
        getPath(root,arr,val);
        return arr;
        }

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    int val=5;
    vector<int> result =rootToNode(root,val);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
