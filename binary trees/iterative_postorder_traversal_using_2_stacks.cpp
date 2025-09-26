#include<iostream>
#include<vector>
#include<stack>
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
Node* insert(Node*root,int val){
    if(root==nullptr) return new Node(val);
    if(val < root->data) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}
vector<int> postOrderTraversal(Node* root){
    stack<Node*> st1;
    stack<Node*> st2;
    vector<int> postorder;
    if(root==nullptr) return postorder;
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=nullptr)st1.push(root->left);
        if(root->right!=nullptr)st1.push(root->right);
    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}
void printPostOrderTraversal(vector<int>& ans){
    for(auto it: ans){
        cout<<it;
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
    vector<int> result=postOrderTraversal(root);
    printPostOrderTraversal(result);
    return 0;
}