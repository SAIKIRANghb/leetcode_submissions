// Last updated: 11/25/2026, 3:49:11 PM
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
    unordered_map<int,int>mp;
    TreeNode* build(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        int node = preorder[preStart];
        TreeNode* root = new TreeNode(node);

        int brInd = mp[node];

        int len = brInd - inStart;

        root->left = build(preStart + 1, preStart + len, inStart, brInd - 1, preorder, inorder);
        root->right = build(preStart + len + 1, preEnd, brInd + 1, inEnd, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        for(int i = 0;i < n;i++){
            mp[inorder[i]] = i;
        }
        return build(0, n - 1, 0, n - 1, preorder, inorder);
    }
};

