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
    if(val < root->data) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}
vector<int> inOrderTraversal(Node* root){
stack<Node*> st;
Node* node=root;
vector<int> inorder;
while(true){
    if(node!=nullptr){
        st.push(node);
        node=node->left;
    }
    else{
        if(st.empty()==true) break;
        node=st.top();
        st.pop();
        inorder.push_back(node->data); 
        node=node->right;
    }
}
return inorder;
}
void printInOrderTraversal(vector<int>& ans){
for(auto it: ans){
    cout << it << " ";
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
    vector<int> result = inOrderTraversal(root);
    printInOrderTraversal(result);
    return 0;
}