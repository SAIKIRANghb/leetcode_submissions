// Last updated: 11/25/2026, 3:45:20 PM
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;
        q.push({root, {0, 0}}); // {x, y} x is vertical, y is level

        while (!q.empty()) {
            auto fr = q.front();
            q.pop();
            int x = fr.second.first;
            int y = fr.second.second;
            TreeNode* node = fr.first;
            mp[x][y].insert(node->val);
            
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        for (auto v : mp) {
            vector<int> col;
            for (auto l : v.second) {
                col.insert(col.end(), l.second.begin(), l.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
