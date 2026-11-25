// Last updated: 11/25/2026, 3:44:17 PM
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
class FindElements {
    private:
    TreeNode* root;
public:
    FindElements(TreeNode* rootNode) {
        root = rootNode;
    }
    
    bool helper(TreeNode* root,int target,int val){
        if(root == NULL)return false;
        if(val == target)return true;
        bool l = helper(root->left,target,val * 2 + 1);
        if(l)return true;
        bool r = helper(root->right,target,val * 2 + 2);
        if(r)return true;
        return false;
    }
    bool find(int target) {
        return helper(root,target,0);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */