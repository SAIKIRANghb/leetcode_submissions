// Last updated: 11/25/2026, 3:49:06 PM
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
    TreeNode* build(vector<int>&inorder,int i0,int i1,vector<int>&postorder,int p0,int p1,unordered_map<int,int>&mp){
        if(i0 > i1 || p0 > p1)return NULL;
        TreeNode* root = new TreeNode(postorder[p1]);
        int inRoot = mp[postorder[p1]];
        int leftnum = inRoot - i0;
        root->left = build(inorder,i0,inRoot - 1,postorder,p0,p0 + leftnum - 1,mp);
        root->right = build(inorder,inRoot + 1,i1,postorder,p0 + leftnum,p1 - 1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i = 0;i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(inorder,0,inorder.size() - 1,postorder,0,postorder.size() - 1,mp);
        return root;
    }
};