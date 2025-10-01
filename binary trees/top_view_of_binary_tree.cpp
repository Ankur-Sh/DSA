#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Definition for a binary tree node
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(NULL), right(NULL) {}
};

    vector<int> topView(Node* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;
            if(mpp.find(line)==mpp.end()) mpp[line]=node->val;
            if(node->left!=nullptr) q.push({node->left,line-1});
            if(node->right!=nullptr) q.push({node->right,line+1});
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }

void printResult(const vector<int>& result) {
    for (int it : result) {
            cout << it << " ";
    }
}

int main() {

    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector<int> result = topView(root);
    printResult(result);

    return 0;
}
