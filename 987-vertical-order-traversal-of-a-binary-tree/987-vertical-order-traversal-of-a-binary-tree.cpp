/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        //inorder traversal
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            TreeNode* tempNode = temp.first;
            int x = temp.second.first, y = temp.second.second;
            mp[x][y].insert(tempNode->val);
            if(tempNode->left)
                q.push({tempNode->left,{x-1,y+1}});
            if(tempNode->right)
                q.push({tempNode->right,{x+1,y+1}});
        }
        for(auto it:mp){
            vector<int> v;
            for(auto x : it.second) {
                for(auto y : x.second)
                    v.push_back(y);
            }
            res.push_back(v);
        }
        return res;
    }
};