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
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> s;
        int prev =-1,curr,ans=INT_MAX;
        TreeNode* temp = root;
        while(temp!=NULL || !s.empty()){
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            curr = temp->val;
            if(prev!=-1){
                ans = min(ans,curr-prev);
            }
            prev=curr;
            temp = temp->right;
        }
        return ans;
    }
};