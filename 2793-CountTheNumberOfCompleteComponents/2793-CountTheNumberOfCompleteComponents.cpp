// Last updated: 11/25/2026, 3:40:52 PM
class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n);
        rank.assign(n,0);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
    }
    int Find(int x){
        if(x == parent[x])return x;
        return parent[x] = Find(parent[x]);
    }
    void Union(int x,int y){
        int parX = Find(x) , parY = Find(y);
        if(rank[parX] > rank[parY]){
            parent[parY] = parX;
        }else if(rank[parX] < rank[parY]){
            parent[parX] = parY;
        }else{
            parent[parY] = parX;  
            rank[parX]++; 
        }
    }
};
class Solution {
public:
    void dfs(int u,vector<vector<int>>&adjLst,DSU &dsu,vector<bool>&vis){

        vis[u] = true;

        for(int v : adjLst[u]){
            if(!vis[v]){
                dsu.Union(u,v);
                dfs(v,adjLst,dsu,vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjLst(n);
        DSU dsu(n);
        vector<bool>vis(n,false);
        for(vector<int>&edge : edges){
            int u = edge[0] , v = edge[1];
            adjLst[u].push_back(v);
            adjLst[v].push_back(u);
        }
        for(int i = 0;i < n;i++){
            if(!vis[i]) dfs(i,adjLst,dsu,vis);
        }
        unordered_map<int,int>CompEdgeCnt;
        unordered_map<int,int>CompNodeCnt;

        for(vector<int>& edge : edges){
            int u = edge[0] , v = edge[1];
            int rootU = dsu.Find(u);
            int rootV = dsu.Find(v);
            if(rootU == rootV){
                CompEdgeCnt[rootU]++;
            }
        }
        for(int i = 0;i < n;i++){
            int root = dsu.Find(i);
            CompNodeCnt[root]++;
        }
        int numCompleteComponents = 0;
        for(auto &[root,size] : CompNodeCnt){
            int CompleteGraphEdges = (size * (size - 1)) / 2;
            if(CompleteGraphEdges == CompEdgeCnt[root]){
                numCompleteComponents++;
            }
        }
        return numCompleteComponents;
    }
};