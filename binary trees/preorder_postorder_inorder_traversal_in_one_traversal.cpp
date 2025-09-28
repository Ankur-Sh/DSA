/*
if(num==1){
preorder
++
left
}
if(num==2){
inoreder
++
right
}
if(num==3){
postorder
pop
}
*/
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
Node* insert(Node* root,int val){
    if(root==nullptr) return new Node(val);
    if(val < root->data) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}
vector<int> combineTraversal(Node* root){
stack<pair<Node*,int>> st;
st.push({root,1});
vector<int> pre,in,post;
if(root==nullptr) return;
while(!st.empty()){
    auto it=st.top();
    st.pop();
    if(it.second==1){
        pre.push_back(it.first->data);
        it.second++;
        st.push(it);
        if(it.first->left!=nullptr){
            st.push({it.first->left,1});
        }
    }
    else if(it.second==2){
        in.push_back(it.first->data);
        it.second++;
        st.push(it);
        if(it.first->right!=nullptr){
            st.push({it.first->right,1});
        }
    }
    else{
        post.push_back(it.first->data);
    }
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
    vector<int> result=combineTraversal(root);
    return 0;
}