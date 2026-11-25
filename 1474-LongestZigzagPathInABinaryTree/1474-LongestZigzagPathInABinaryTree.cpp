// Last updated: 11/25/2026, 3:44:00 PM
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
    int dfs(TreeNode* root,bool goLeft,int &ans){
        if(root == NULL)return 0;
        int lt = dfs(root->left,true,ans);
        int rt = dfs(root->right,false,ans);
        ans = max({lt , rt,ans});
        if(goLeft == true){
            return rt + 1;
        } 
        return lt + 1;
    }
    int longestZigZag(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root,true,ans);
        return ans;
    }
};

// class Solution {
// public:
//    // {LR , RL}
//     pair<int,int> findLen(TreeNode* root,int &ans){
//         if(root == NULL)return {0,0};
//         auto l = findLen(root->left,ans);
//         auto r = findLen(root->right,ans);
//         ans=max({ans,l.second+1,r.first+1});
//         return {l.second+1,r.first+1};
//     }
//     int longestZigZag(TreeNode* root) {
//         int ans = 0;
//         findLen(root,ans);
//         return ans - 1;
//     }
// };

// class Solution {
// public:
//     int pathLength = 0;
//     void dfs(TreeNode* root,bool goLeft,int steps){
//         if(root == NULL)return;
//         pathLength = max(pathLength,steps);
//         if(goLeft){
//             dfs(root->left,false,steps + 1);
//             dfs(root->right,true,1);
//         }else{
//             dfs(root->right,true,steps + 1);
//             dfs(root->left,false,1);
//         }
//     }
//     int longestZigZag(TreeNode* root) {
//         dfs(root,true,0);
//         return pathLength;
//     }
// };