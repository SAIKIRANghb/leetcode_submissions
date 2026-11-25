// Last updated: 11/25/2026, 3:49:13 PM
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
    bool isSymmetric(TreeNode* lt,TreeNode* rt){
        if(lt == NULL || rt == NULL)return lt == rt;
        if(lt->val != rt->val)return false;
        return isSymmetric(lt->left,rt->right) && isSymmetric(lt->right,rt->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root->left,root->right);
    }
};