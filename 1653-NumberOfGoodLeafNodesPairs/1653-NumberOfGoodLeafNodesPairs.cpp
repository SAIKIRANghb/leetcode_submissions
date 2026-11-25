// Last updated: 11/25/2026, 3:43:38 PM
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
    int ans = 0;
    vector<int> pairs(TreeNode* root, int distance){
        if(root == NULL){
            return {};
        }
        if (root->left == nullptr && root->right == nullptr) {
            return { 1 }; 
        }

        vector<int>L,R;
        L = pairs(root->left,distance);
        R = pairs(root->right,distance);
        int n = R.size();
        for(int l : L){
            R.push_back(l + 1);
            for(int i = 0;i<n;i++){
                int r = R[i];
                if(l + r <= distance)ans++;
            }
        }
        for(int i = 0;i<n;i++){
            R[i]++;
        }
        return R;
    }
    int countPairs(TreeNode* root, int distance) {
        pairs(root,distance);
        return ans;
    }
};