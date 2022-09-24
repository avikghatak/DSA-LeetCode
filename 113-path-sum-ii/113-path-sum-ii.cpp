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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        //stores current array of nodes
        vector<int> curr;
        dfs(root,targetSum,ans,curr);
        return ans;
    }
    
    void dfs(TreeNode* root, int sum,vector<vector<int>>& ans, vector<int>& curr){
        if(!root) return;
        curr.push_back(root->val);
        sum -= root->val;
        if(!(root->left) && !(root->right) && sum==0){
            ans.push_back(curr);
        }
        else {
            dfs(root->left,sum,ans,curr);
            dfs(root->right,sum,ans,curr);
        }
        curr.pop_back();
    }
};