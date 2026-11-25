// Last updated: 11/25/2026, 3:44:46 PM
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
    vector<TreeNode*>ans;
    void del(TreeNode* root, unordered_map<int,bool> &to_delete,TreeNode* prev){
        if(root == NULL) return; 
        
        del(root->left,to_delete,root);
        del(root->right,to_delete,root);
        if(to_delete.find(root->val) != to_delete.end()){
            if(root->left != NULL)ans.push_back(root->left);
            if(root->right != NULL)ans.push_back(root->right);
            if(prev!=NULL){
                if(prev->left == root){
                    prev->left = NULL;
                }else{
                    prev->right = NULL;
                }
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == NULL)return {};
        unordered_map<int,bool>to_del;
        for(auto num : to_delete){
            to_del[num] = true;
        }
        if(to_del.find(root->val) == to_del.end()){
            ans.push_back(root);
        }
        del(root,to_del,NULL);
        return ans;
    }
};