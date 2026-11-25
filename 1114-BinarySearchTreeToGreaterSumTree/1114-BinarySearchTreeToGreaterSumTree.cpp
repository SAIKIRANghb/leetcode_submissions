// Last updated: 11/25/2026, 3:45:05 PM
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
    TreeNode* postExtremeLeft(TreeNode* root){
        TreeNode* p = root->right;
        while(p->left != NULL && p->left != root){
            p = p->left;
        }
        return p;
    }
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* retRoot = root;
        TreeNode* p = root;
        int sum = 0;
        while(p!=NULL){
            if(p->right == NULL){
                sum += p->val;
                p->val = sum;
                p = p->left;
            }else{
                TreeNode* pel = postExtremeLeft(p);
                if(pel->left == NULL){
                    pel->left = p;
                    p = p->right;
                }else{
                    pel->left = NULL;
                    sum += p->val;
                    p->val = sum;
                    p = p->left;
                }
            }
        }
        return retRoot;
    }
};