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
    return root;
}
int check(Node* node){
    if(node==nullptr) return 0;
    int lh=check(node->left);
    if(lh==-1) return -1;
    int rh=check(node->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1)return -1;
    return max(lh,rh)+1;
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
    int result = check(root);
    cout<<(result==-1)?false:true;
    return 0;
}