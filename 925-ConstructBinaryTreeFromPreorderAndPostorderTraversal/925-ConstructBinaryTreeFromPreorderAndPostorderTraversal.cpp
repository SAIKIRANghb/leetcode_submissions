// Last updated: 11/25/2026, 3:45:48 PM
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
    TreeNode* build(int preStart,int preEnd,int postStart,int postEnd,vector<int>& preorder, vector<int>& postorder){
        if(preStart > preEnd)return NULL;
        if(preStart == preEnd)return new TreeNode(preorder[preStart]);
        TreeNode* node = new TreeNode(preorder[preStart]);
        int posInd = -1;
        for(int i = postStart;i <= postEnd;i++){
            if(postorder[i] == preorder[preStart + 1]){
                posInd = i;
                break;
            }
        }
        int numLeft = posInd - postStart + 1;
        node->left = build(preStart + 1,preStart + numLeft,postStart,posInd,preorder,postorder);// or posInd = posStart + numLeft - 1
        node->right = build(preStart + numLeft + 1,preEnd,posInd + 1,postEnd,preorder,postorder);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size(); 
        return build(0,n - 1,0 ,n - 1,preorder,postorder);
    }
};