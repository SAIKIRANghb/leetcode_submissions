// Last updated: 11/25/2026, 3:45:23 PM
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
    int StepCount(int &steps ,TreeNode* root){
        if(root==NULL){
            return 0;
        }
       int leftVal = StepCount(steps,root->left);
       int rightVal = StepCount(steps,root->right);
       steps += abs(leftVal) + abs(rightVal); 
       return root->val - 1 + leftVal + rightVal;
    }
    int distributeCoins(TreeNode* root) {
        int steps = 0;
        StepCount(steps,root);
        return steps;
    }
};