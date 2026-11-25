// Last updated: 11/25/2026, 3:42:16 PM
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
        TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
           if(root == NULL)return NULL;
           
           if(root->val == p || root->val == q) return root;

           TreeNode* left = lowestCommonAncestor(root->left,p,q);
           TreeNode* right = lowestCommonAncestor(root->right,p,q);

           if(left && right)return root;

           if(left == NULL){
            return right;
           }else{
            return left;
           }
        }
        string lcaToStart,lcaToDest;
        string path = "";
        void findPath(TreeNode* root, int s, int d){
            if(root == NULL)return;
            if(root->val == s){
                lcaToStart = path;
            }else if(root->val == d){
                lcaToDest = path;
            }
            path.push_back('L');
            findPath(root->left,s,d);
            path.pop_back();

            path.push_back('R');
            findPath(root->right,s,d);
            path.pop_back();
        }
    
    string getDirections(TreeNode* root, int s, int d) {
        TreeNode* LCA = lowestCommonAncestor(root,s,d);
        findPath(LCA,s,d);
        int n = lcaToStart.size();
        for(int i = 0;i<n;i++){
            lcaToStart[i] = 'U';
        }
        return lcaToStart + lcaToDest;
    }
};