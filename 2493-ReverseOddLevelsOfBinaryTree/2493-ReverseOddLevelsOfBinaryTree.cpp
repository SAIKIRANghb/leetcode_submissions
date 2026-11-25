// Last updated: 11/25/2026, 3:41:31 PM
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

// class Solution {
// public:
//     void reverse(deque<pair<TreeNode*, TreeNode*>>& dq) {
//         int n = dq.size();
//         if (n < 2) return;

//         for (int i = 0; i < n / 2; ++i) {
//             auto& left = dq[i];
//             auto& right = dq[n - 1 - i];
//             swap(left.second->val, right.second->val);
//         }
//     }

//     TreeNode* reverseOddLevels(TreeNode* root) {
//         if (!root) return root;

//         deque<pair<TreeNode*, TreeNode*>> dq;
//         if (root->left) dq.push_back({root, root->left});
//         if (root->right) dq.push_back({root, root->right});

//         int depth = 1; // Level 1 (odd level) comes first
//         while (!dq.empty()) {
//             int sz = dq.size();
//             if (depth % 2 == 1) {
//                 reverse(dq); // Reverse values of nodes at the current odd level
//             }
//             for (int i = 0; i < sz; ++i) {
//                 auto front = dq.front();
//                 dq.pop_front();

//                 TreeNode* parent = front.second;
//                 if (parent->left) dq.push_back({parent, parent->left});
//                 if (parent->right) dq.push_back({parent, parent->right});
//             }
//             depth++;
//         }
//         return root;
//     }
// };

// class Solution {
// public:
//     void reverse(deque<pair<TreeNode*, TreeNode*>>& dq) {
//         int n = dq.size();
//         if (n < 2) return;

//         deque<pair<TreeNode*, TreeNode*>> rightDq;
//         deque<pair<TreeNode*, TreeNode*>> leftDq;

//         int terminate = n / 2 - 1;

//         for (int i = 0; i <= terminate; ++i) {
//             auto left = dq.front();
//             auto right = dq.back();
//             dq.pop_back();
//             dq.pop_front();

//             // Swap the values of the nodes
//             swap(left.second->val, right.second->val);

//             rightDq.push_front(right);
//             leftDq.push_back(left);
//         }

//         // Add remaining nodes if odd number of pairs in deque
//         if (!dq.empty()) {
//             leftDq.push_back(dq.front());
//             dq.pop_front();
//         }

//         // Combine left and right deques
//         while (!rightDq.empty()) {
//             leftDq.push_back(rightDq.front());
//             rightDq.pop_front();
//         }

//         dq = leftDq;
//     }

//     TreeNode* reverseOddLevels(TreeNode* root) {
//         if (!root || (!root->left && !root->right)) return root;

//         deque<pair<TreeNode*, TreeNode*>> dq;

        
//         if (root->left) dq.push_back({root, root->left});
//         if (root->right) dq.push_back({root, root->right});

//         int depth = 1;
//         while (!dq.empty()) {
//             int sz = dq.size();
//             if (depth % 2 == 1) {
//                 reverse(dq);
//             }

//             for (int i = 0; i < sz; ++i) {
//                 auto front = dq.front();
//                 dq.pop_front();

//                 TreeNode* parent = front.second;
//                 if (parent->left) dq.push_back({parent, parent->left});
//                 if (parent->right) dq.push_back({parent, parent->right});
//             }
//             depth++;
//         }
//         return root;
//     }
// };


// class Solution {
// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         queue<TreeNode*> q;
//         q.push(root);
//         bool reversed=0;
//         while(!q.empty()){
//             int qz=q.size();
//             vector<TreeNode*> arr(qz);
//             for(int i=0; i<qz; i++){
//                 auto Node=q.front();
//                 q.pop();
//                 if (Node->left) q.push(Node->left);
//                 if (Node->right) q.push(Node->right);
//                 if (reversed){
//                     arr[i]=Node;
//                     if (i>=qz/2) 
//                         swap(arr[i]->val, arr[qz-1-i]->val); 
//                 }
//             }
//             reversed=!reversed;
//         }
//         return root;
//     }
// };
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,0);
        return root;
    }
    void dfs(TreeNode* leftChild,TreeNode* rightChild, int level){
        if(leftChild == nullptr || rightChild == nullptr){
            return;
        }

        if(level % 2 == 0){
            int temp = leftChild -> val;
            leftChild->val = rightChild->val;
            rightChild->val = temp;
        }
        
        dfs(leftChild->left, rightChild->right, level + 1);
        dfs(leftChild->right, rightChild->left, level + 1);
    }
};