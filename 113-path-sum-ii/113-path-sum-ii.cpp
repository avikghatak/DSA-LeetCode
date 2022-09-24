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
        vector<int> currPath;
        dfs(root,targetSum,currPath,ans);
        return ans;
    }
    void dfs(TreeNode* root, int target, vector<int>& currPath,vector<vector<int>>& ans) {
        if (!root) return; 
        currPath.push_back(root->val);
        target -= root->val; 
        if (!root->left && !root->right && target==0) 
            ans.push_back(currPath);
        else 
        {
            dfs(root->left, target, currPath, ans);
            dfs(root->right, target, currPath, ans);
        }
        currPath.pop_back(); 
    }
};