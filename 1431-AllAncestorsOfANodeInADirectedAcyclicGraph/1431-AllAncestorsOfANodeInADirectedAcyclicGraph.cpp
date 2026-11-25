// Last updated: 11/25/2026, 3:44:06 PM
// class Solution {
// public:
//     vector<vector<int>> ans;
    
//     vector<int> dfs(int i, vector<vector<int>>& DAG) {
//         int n = DAG[i].size();
        
//         if (n == 0) {
//             return {i};
//         }
//         if(!ans[i].empty()){
//             vector<int> temp = ans[i];
//             temp.push_back(i);
//             return temp;
//         }
        
//         vector<int> path;
//         for (int j = 0; j < n; j++) {
//             vector<int> temp = dfs(DAG[i][j], DAG);
//             temp.push_back(DAG[i][j]);
//             for (int node : temp) {
//                 path.push_back(node);
//             }
//         }

        
//         if (ans[i].empty()) {
//             ans[i] = path;
//         }
        
//         return path;
//     }
    
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         int m = edges.size();
//         vector<vector<int>> DAG(n);
//         ans.resize(n);
        
//         for (int i = 0; i < m; i++) {
//             int from = edges[i][0];
//             int to = edges[i][1];
//             DAG[to].push_back(from);
//         }
        
//         for (int i = 0; i < n; i++) {
//             dfs(i, DAG);
//         }
        
//         return ans;
//     }
// };


class Solution {
public:
    vector<set<int>> ancestors;
    
    vector<int> dfs(int i, vector<vector<int>>& DAG) {
        int n = DAG[i].size();
        if (!ancestors[i].empty()) {
            set<int> temp = ancestors[i];
            temp.insert(i); // Include current node as an ancestor
            return vector<int>(temp.begin(), temp.end());
        }
        if (n == 0) {
            return {i};
        }
        
        set<int> path;
        for (int j = 0; j < n; j++) {
            vector<int> temp = dfs(DAG[i][j], DAG);
            temp.push_back(DAG[i][j]);
            for (int node : temp) {
                path.insert(node);
            }
        }

        ancestors[i] = path;
        
        return vector<int>(path.begin(), path.end());
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> DAG(n);
        ancestors.resize(n);
        
        for (int i = 0; i < m; i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            DAG[to].push_back(from);
        }
        
        for (int i = 0; i < n; i++) {
            dfs(i, DAG);
        }
        
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }
        
        return ans;
    }
};

