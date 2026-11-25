// Last updated: 11/25/2026, 3:45:06 PM
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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*>st;
        int index = 0;
        int n = traversal.size(); 
        while(index < n){
            int depth = 0;
            while(index < n && traversal[index] == '-'){
                depth++;
                index++;
            }
            int val = 0;
            while(index < n && isdigit(traversal[index])){
                val = val*10 + (traversal[index] - '0');
                index++;
            }
            TreeNode* node = new TreeNode(val);
            while(st.size() > depth){
                st.pop();
            }
            if(!st.empty()){
                if(st.top()->left == NULL){
                    st.top()->left = node;
                }else{
                    st.top()->right = node;
                }
            }
            st.push(node);
        }
        while(st.size() > 1){
            st.pop();
        }
        return st.top();
    }
};

// class Solution {
// public:
//     TreeNode* helper(int &index,const string &traversal,const int n,int depth){
//         if(index >= traversal.size())return NULL;
//         int dashCnt = 0;
//         while(index + dashCnt < n && traversal[index + dashCnt] == '-'){
//             dashCnt++;
//         }

//         if(dashCnt != depth)return NULL; //if the dashes are not as expeced depth then the preorder has backtract
 
//         index += dashCnt;  // after verifying depth is as expected add the number of dashes to update index to correct value

//         string strNum = "";
//         while(index < n && isdigit(traversal[index])){
//             strNum += traversal[index];
//             index++;
//         }
//         int num = stoi(strNum);
//         TreeNode *node = new TreeNode(num);
//         node->left = helper(index,traversal,n,depth + 1);
//         node->right = helper(index,traversal,n,depth + 1);
//         return node;
//     }
//     TreeNode* recoverFromPreorder(string traversal) {
//         int index = 0;
//         return helper(index,traversal,traversal.size(),0);
//     }
// };



// class Solution {
// public:
//     TreeNode* recoverFromPreorder(string traversal) {
//         unordered_map<int,vector<TreeNode*>>mp;
//         int n = traversal.size();
//         int i = 0;
//         while(i < n){
//             int lvl = 0;
//             while(i < n && traversal[i] == '-'){
//                 i++;
//                 lvl++;
//             }
//             string strNum;
//             while(i < n && isdigit(traversal[i])){
//                 strNum += traversal[i];
//                 i++;
//             }
//             int num = stoi(strNum);
//             TreeNode* node = new TreeNode(num);
//             mp[lvl].push_back(node);
//             if(lvl > 0 && !mp[lvl - 1].empty()){
//                 TreeNode* parent = mp[lvl - 1].back();
//                 if(!parent->left){
//                     parent->left = node;
//                 }else{
//                     parent->right = node;
//                 }
//             }
//         }
//         return mp[0][0];
//     }
    
// };

