// Last updated: 11/25/2026, 3:46:50 PM
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root->left == NULL && root->right == NULL || depth == 1){
            TreeNode* New = new TreeNode(val);
            New->left = root;
            return New;
        }
        depth--;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
           int n = q.size();
           if(depth == 0)break;
           for(int i=0;i<n;i++){
            TreeNode* temp = q.front();
            q.pop();
            if(depth > 1){
                if(temp->left != NULL){
                q.push(temp->left);
                }
                if(temp->right != NULL){
                q.push(temp->right);
                }
            }else{
                TreeNode* NewL = new TreeNode(val);
                TreeNode* NewR = new TreeNode(val);
                NewL->left = temp->left;
                NewR->right = temp->right; 
                temp->left = NewL;
                temp->right = NewR;
            }
           }
           depth--;
        }   
        return root;
    }
};