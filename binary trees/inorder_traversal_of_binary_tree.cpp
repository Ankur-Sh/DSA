#include<iostream>
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
}
void inorderTraversal(Node* root){
    if(root==nullptr) return;
    inorderTraversal(root->left);
    cout<<root->data;
    inorderTraversal(root->right);
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
    inorderTraversal(root);
    return 0;
}