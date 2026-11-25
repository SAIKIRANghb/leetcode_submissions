// Last updated: 11/25/2026, 3:45:15 PM
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

    // TreeNode* construct(int start ,int end,vector<int>nums,TreeNode *root){
    //     if(start == end){
    //         return new TreeNode(nums[start]);
    //     }
    //     if(start > end){
    //         return NULL;
    //     }
    //     int n = nums.size();
    //     int Max = INT_MIN;
    //     int maxi = n/2;
    //     for(int j=start;j<=end;j++){
    //         if(Max < nums[j]){
    //             Max = nums[j];
    //             maxi = j;
    //         }
    //     }
    //     root = new TreeNode(nums[maxi]);
    //     root->left=construct(start , maxi - 1 , nums,root->left);
    //     root->right=construct(maxi+1 ,end , nums , root->right);
    //     return root;
    // }
    // void inorder(TreeNode* root,vector<int>&a){
    //     if(root==NULL){
    //         return;
    //     }
    //     inorder(root->left,a);
    //     a.push_back(root->val);
    //     inorder(root->right,a);
    //     return;
    // }

    
    // TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    //     if(root == NULL)return NULL;
    //     if(root->val < val){
    //         TreeNode* New=new TreeNode(val);
    //         New->left = root;
    //         return New;
    //     }
    //    vector<int> a;
    //    inorder(root,a);
    //    a.push_back(val);
    //    return construct(0,a.size()-1,a,root);
    // }

TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (root == NULL || root->val < val) {
        TreeNode* New = new TreeNode(val);
        New->left = root;
        return New;
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
}

};