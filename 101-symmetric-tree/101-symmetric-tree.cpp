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

    bool isSymmetric(TreeNode* root) {
        return root == NULL || check(root->left, root->right);
    }

    bool check(TreeNode* L, TreeNode* R){
        if(L == NULL || R == NULL)
            return L == R;
        if(L->val != R->val)
            return false;
        else
            return { check(L->left, R->right) && check(L->right, R->left)};
   }
  
};