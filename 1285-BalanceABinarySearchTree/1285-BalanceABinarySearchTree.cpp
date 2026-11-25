// Last updated: 11/25/2026, 3:44:33 PM
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

    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr) return nullptr;

        //(1) Create the backbone (vine)
        //Adding a temperory dummy node
        TreeNode* vineHead = new TreeNode(0);
        vineHead->right = root;
        TreeNode* current = vineHead;
        while(current->right != nullptr){
            if(current->right->left != nullptr){
                rightRotate(current,current->right);
            }else{
                current = current->right;
            }
        }
        //(2) Count the nodes
        int nodeCount = 0;
        current = vineHead->right;
        while(current != nullptr){
            ++nodeCount;
            current = current->right;
        }
        //(3) Create a balanced BST
        int logVal = floor(log2(nodeCount + 1));
        int m = (1<<logVal) - 1;
        makeRotations(vineHead,nodeCount - m);
        while(m > 1){
            m /= 2;
            makeRotations(vineHead,m);
        }
        TreeNode* balancedRoot = vineHead->right;
        delete vineHead;
        return balancedRoot;
    }

    void rightRotate(TreeNode* parent,TreeNode* node){
        TreeNode* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        parent->right = temp;
    }

    void leftRotate(TreeNode* parent,TreeNode* node){
        TreeNode* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        parent->right = temp;
    }

    void makeRotations(TreeNode* vineHead,int count){
        TreeNode* current = vineHead;
        for(int i = 0;i<count;i++){
            TreeNode* tmp = current->right;
            leftRotate(current,tmp);
            current = current->right;
        }
    }
};