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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> BSTarray;
        TreeNode* temp = root;
        while(temp!=NULL || !s.empty()){
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            BSTarray.push_back(temp->val);
            temp = temp->right;
        }
        int ans=INT_MAX;
        for(int i=1;i<BSTarray.size();i++){
            ans = min(ans,BSTarray[i]-BSTarray[i-1]);
        }
        
        return ans;
    }
};