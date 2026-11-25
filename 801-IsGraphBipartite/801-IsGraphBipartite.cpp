// Last updated: 11/25/2026, 3:46:15 PM
class Solution {
public:
    bool find(int node, vector<vector<int>>& graph, vector<int>& vis, int val) {
        vis[node] = val;  
        for (int neighbor : graph[node]) {  
            if (vis[neighbor] == -1) {  
                if (find(neighbor, graph, vis, !val) == false) return false;  
            } else if (vis[neighbor] == vis[node]) {  
                return false;  
            }  
        }  
        return true;  
    }  

    bool isBipartite(vector<vector<int>>& graph) {  
        vector<int> vis(graph.size(), -1); 
        for(int i = 0;i  < graph.size();i++){
            if(vis[i] == -1 && find(i,graph,vis,0) == false)return false;
        } 
        return true;
    }  
};
