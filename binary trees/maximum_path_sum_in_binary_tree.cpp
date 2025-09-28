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
int maxS(Node* root,int& maxSum){     //use case of pass by reference of maxi i.e. we do not return maxi but it get updated in main function as well
     if(root==nullptr) return 0;
    int ls=max(0,maxS(root->left,maxSum));
    int rs=max(0,maxS(root->right,maxSum));
    maxSum=max(maxSum,root->data+ls+rs); 
    return root->data+max(ls,rs);
}

int main(){
    int maxSum=0;
    Node* root=nullptr;
    root=insert(root,50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    int result=maxS(root,maxSum);
    cout<<maxSum;
    return 0;
}