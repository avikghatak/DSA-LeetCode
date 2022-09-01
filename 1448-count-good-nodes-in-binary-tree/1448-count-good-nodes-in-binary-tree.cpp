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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int ans=0,max=INT_MIN;
        countGoodNodes(root,max,ans);
        return ans;
    }
    
    void countGoodNodes(TreeNode* root,int max,int& ans) {
        if(!root) return;
        if(root->val >= max) {
            ans++;
            max = root->val;
        }
        countGoodNodes(root->left,max,ans);
        countGoodNodes(root->right,max,ans);
    }
};