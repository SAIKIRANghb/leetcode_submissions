// Last updated: 11/25/2026, 3:38:55 PM
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
    int solve(TreeNode* root, int k, priority_queue<int, vector<int>, greater<int>>& pq) {
        if(root == NULL)return 0;
        int left = solve(root->left, k, pq);
        int right = solve(root->right, k, pq);

        int res = (left!= -1 && right!=-1 && left == right) ? left + right + 1 : -1;
        if (res > 0) {
            pq.push(res);
            if (pq.size() >= k + 1) {
                pq.pop();
            }
        }
        return res;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        solve(root, k, pq);
        return (pq.size() == k ? pq.top() : -1);
    }
};

