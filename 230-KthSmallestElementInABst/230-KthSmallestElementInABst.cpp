// Last updated: 11/25/2026, 3:47:57 PM
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
    int count=0;
    int n;
    int flag = 1;
    int num=0;
    int trav(TreeNode* root){
        if(root==NULL)return -1;
       int ans = max(ans,trav(root->left));
         num++;
         ans = max(ans,trav(root->right));
         return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)return -1;
        if(flag){
            n = trav(root);
        }
        int ans = -1;
        ans= max(ans,kthSmallest(root->left,k));
        count++;
        if(count == k){
            return root->val;
        }
        ans = max(ans,kthSmallest(root->right,k));
        return ans;
    }
};