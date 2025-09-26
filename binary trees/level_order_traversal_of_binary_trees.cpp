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
vector<vector<int>> levelOrderTraversal(Node* root){
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}
void printLevelOrderTraversal(const vector<vector<int>>& ans) {
    for (const auto& level : ans) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
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
    vector<vector<int>> result=levelOrderTraversal(root);
    printLevelOrderTraversal(result);
    return 0;
}