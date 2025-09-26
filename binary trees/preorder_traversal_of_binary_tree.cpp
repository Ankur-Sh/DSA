//Root-Left-Right
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
Node* insert(Node* root,int value){
    if(root==nullptr) return new Node(value);
    if(value < root->data) root->left=insert(root->left,value);
    else root->right=insert(root->right,value);
    return root;
}
void preOrderTraversal(Node* root){
    if(root==nullptr) return;
    cout<<root->data;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
int main(){
    Node* root=nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    preOrderTraversal(root);
}