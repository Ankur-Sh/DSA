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
int diameter(Node* root,int& maxi){     //use case of pass by reference of maxi i.e. we do not return maxi but it get updated in main function as well
     if(root==nullptr) return 0;
    int lh=diameter(root->left,maxi);
    int rh=diameter(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}

int main(){
    int maxi=0;
    Node* root=nullptr;
    root=insert(root,50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    int result=diameter(root,maxi);
    cout<<maxi;
    return 0;
}