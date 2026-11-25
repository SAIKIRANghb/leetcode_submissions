// Last updated: 11/25/2026, 3:46:37 PM
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
    TreeNode* construct(int start ,int end,vector<int>nums,TreeNode *root){
        if(start == end){
            return new TreeNode(nums[start]);
        }
        if(start > end){
            return NULL;
        }
        int n = nums.size();
        int Max = INT_MIN;
        int maxi = n/2;
        for(int j=start;j<=end;j++){
            if(Max < nums[j]){
                Max = nums[j];
                maxi = j;
            }
        }
        root = new TreeNode(nums[maxi]);
        root->left=construct(start , maxi - 1 , nums,root->left);
        root->right=construct(maxi+1 ,end , nums , root->right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return construct(0,n-1,nums,NULL);
    }
};