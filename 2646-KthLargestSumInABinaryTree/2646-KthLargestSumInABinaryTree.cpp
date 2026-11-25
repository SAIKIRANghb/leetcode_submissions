// Last updated: 11/25/2026, 3:41:06 PM
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL) return -1;

        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;

            while(size--) {
                TreeNode* front = q.front();
                q.pop();

                if (front) {
                    sum += front->val;
                    if (front->left) q.push(front->left);
                    if (front->right) q.push(front->right);
                }
            }

            pq.push(sum);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        if(pq.size() < k) {
            return -1;
        } else {
            return pq.top();
        }
    }
};
