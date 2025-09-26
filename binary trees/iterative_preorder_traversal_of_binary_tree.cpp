#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
Node* insert(Node* root,int val){
    if(root==nullptr) return new Node(val);
    if(val < root->data) root->left= insert(root->left,val);
    else root->right= insert(root->right,val);
    return root;
}
vector<int> preOrderTraversal(Node* root){
    vector<int> preorder;
    if(root==nullptr) return preorder;
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right != nullptr) st.push(root->right);
        if(root->left != nullptr) st.push(root->left);
    }
    return preorder;
}
void printLevelOrderTraversal(const vector<int>& ans) {
        for (int val : ans) {
            cout << val << " ";
        }
}
int main(){
    Node* root=nullptr;
    root=insert(root,50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    vector<int> result = preOrderTraversal(root);
    printLevelOrderTraversal(result);
    return 0;
}