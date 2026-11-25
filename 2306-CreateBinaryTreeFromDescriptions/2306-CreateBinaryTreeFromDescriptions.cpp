// Last updated: 11/25/2026, 3:41:58 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, TreeNode*> mp;
        unordered_map<int,int>Pmp;
        for (int i = 0; i < n; i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            Pmp[child] = parent;
            TreeNode* p;
            if (mp.find(parent) != mp.end()) {
                p = mp[parent];
            } else {
                p = new TreeNode(parent);
                mp[parent] = p;
            }
            TreeNode* ch;
            if (mp.find(child) != mp.end()) {
                ch = mp[child];
            } else {
                ch = new TreeNode(child);
                mp[child] = ch;
            }
            if (isLeft == 1)
                p->left = ch;
            else
                p->right = ch;
            mp[child] = ch;
        }
        for(auto [val , node] : mp){
            if(Pmp.find(val) == Pmp.end()){
                return node;
            }
        }
        return NULL;
    }
};