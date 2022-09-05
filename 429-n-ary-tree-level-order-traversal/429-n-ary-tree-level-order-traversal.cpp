/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //Same as level order traversal of binary tree
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<Node*> childrenNodes;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> v;
            while(len--){
                Node* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                childrenNodes = temp->children;
                //instead of adding left&right children add all children from the vector
                for(auto child : childrenNodes){
                    q.push(child);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};