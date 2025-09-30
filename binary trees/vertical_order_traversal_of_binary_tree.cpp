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

    vector<vector<int>> verticalTraversal(Node* root) {
        // Map of x -> map of y -> multiset of node values
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            pair<Node*, pair<int, int>> front = q.front();
            q.pop();

            Node* node = front.first;
            int x = front.second.first;
            int y = front.second.second;
            nodes[x][y].insert(node->val);
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }
        vector<vector<int>> result;
        for (map<int, map<int, multiset<int>>>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
            vector<int> col;
            for (map<int, multiset<int>>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt) {
                col.insert(col.end(), jt->second.begin(), jt->second.end());
            }
            result.push_back(col);
        }
        return result;
    }

void printResult(const vector<vector<int>>& result) {
    for (const vector<int>& col : result) {
        cout << "[ ";
        for (int val : col) {
            cout << val << " ";
        }
        cout << "]";
        cout << endl;
    }
}

int main() {

    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector<vector<int>> result = verticalTraversal(root);

    cout << "Vertical Traversal Output:\n";
    printResult(result);

    return 0;
}
