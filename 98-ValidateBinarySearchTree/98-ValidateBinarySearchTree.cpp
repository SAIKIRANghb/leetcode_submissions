// Last updated: 11/25/2026, 3:49:17 PM
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
    bool helper(TreeNode* root,pair<long long,long long>range){
        if(root == NULL)return true;
        if(range.first >= root->val || root->val >= range.second){
            return false;   
        }
        bool left = helper(root->left,{range.first,1LL*root->val});
        bool right = helper(root->right,{1LL*root->val,range.second});
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,{LONG_MIN,LONG_MAX});
    }
};