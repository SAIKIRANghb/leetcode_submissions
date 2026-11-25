// Last updated: 11/25/2026, 3:46:34 PM
class Solution {
    class DSU {
        public:
        vector<int> parent, rank;
        DSU(int n) { 
            parent.resize(n);rank.resize(n,0);
            for(int i = 0;i < n;i++)parent[i] = i;
        }
        int find(int x){
            if(parent[x] == x)return x;
            return parent[x] = find(parent[x]);
        }
        bool Union(int x,int y){
            int parX = find(x);
            int parY = find(y);
            if(parX != parY){
                if(rank[parX] < rank[parY])parent[parX] = parY;
                else if(rank[parX] > rank[parY])parent[parY] = parX;
                else{
                    parent[parY] = parX;
                    rank[parX]++;
                }
                return true;
            }
            return false;
        }
    };
 
 public :    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto edge : edges){
            if(!dsu.Union(edge[0] - 1,edge[1] - 1)){
                return edge;
            }
        }
        return {};
    }
};