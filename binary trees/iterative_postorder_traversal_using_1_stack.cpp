#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=right=nullptr;
    }
};
Node* insert(Node*root, int val){
    if(root==nullptr) return new Node(val);
    if(val < root->data) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}
void printPostOrderTraversal(vector<int>& arr){
    for(auto it: arr){
        cout<<it;
    }
}
vector<int> postOrderTraversal(Node* root){
    vector<int> postorder;
    stack<Node*> st;
    Node* curr=root;
    if(root==nullptr) return postorder;
    while (curr!=nullptr || !st.empty()){
        if(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }
        else{
            Node* temp=st.top()->right;
            if(temp==nullptr){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else curr=temp;
        }
    }
    return postorder;
    
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