//using recursion
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
Node* insert(Node* root, int val){
    if(root==nullptr) return new Node(val);
    if(val < root->data) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}
int maxH(Node* root){
    if(root==nullptr) return 0;
    int lh=maxH(root->left);
    int rh=maxH(root->right);
    return 1+ max(lh,rh);
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
    int result = maxH(root);
    cout<<result;
    return 0;
}

//using levelorder traversal

#include<iostream>
#include<vector>
#include<queue>
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
int levelOrderTraversal(Node* root){
    int ans=0;
    if(root==nullptr) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
        }
        ans++;
    }
    return ans;
}
int main(){
    Node* root= nullptr;
    root=insert(root,50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    int result=levelOrderTraversal(root);
    cout<<result;
    return 0;
}