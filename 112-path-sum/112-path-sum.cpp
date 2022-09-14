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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //If tree is empty
        if(root == NULL) return false;
        targetSum=targetSum-root->val;
        //Checking if the node is leaf node 
        if(root->left==NULL && root->right==NULL)
            return targetSum==0;
        //Check for left and right childe
        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
    }
};