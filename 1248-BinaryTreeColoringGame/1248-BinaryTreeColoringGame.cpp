// Last updated: 11/25/2026, 3:44:38 PM
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    int ScoreL = 0;
    int ScoreR = 0;
    int Count(TreeNode* root,int x){
        if(root == NULL)return 0;
        int left = 0,right = 0;
        left = Count(root->left,x);
        right = Count(root->right,x);
        if(root->val == x){
            ScoreL = left;
            ScoreR = right;
        }
        return left + right + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        Count(root,x);
        int parScore = n - (ScoreL + ScoreR + 1);
        int maxBlueScore = max({parScore,ScoreL,ScoreR}); 
        if(maxBlueScore > n/2)return true;
        return false;
    }
};