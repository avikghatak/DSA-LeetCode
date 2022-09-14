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
    void helper(TreeNode* root,vector<int>& freq,int& ans){
        if(root==NULL) return;
        //preorder traversal
        freq[root->val]++;
        helper(root->left,freq,ans);
        helper(root->right,freq,ans);
        //when we reach the leaf node we check for number of odd frequencies
        if(!root->right && !root->left){
            int oddFreq=0;
            for(int i=1;i<freq.size();i++){
                if(freq[i]%2!=0)
                    oddFreq++;
            }
            //if we have 0/1 odd frequencies, the sequence can be a palindrome
            if(oddFreq<=1) ans++;
        }
        freq[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        vector<int> freq(10,0);
        helper(root,freq,ans);
        return ans;
    }
};