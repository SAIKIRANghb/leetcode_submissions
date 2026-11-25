// Last updated: 11/25/2026, 3:47:01 PM

//Unionfind

class UnionFind{
private:
    vector<int>parent,rank;
    int cnt = 0;
public:
    UnionFind(int size){
        parent.resize(size);
        rank.resize(size);
        cnt = size;
        for(int i = 0;i < size;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]);
    }
    void union_set(int x,int y){
        int parX = find(x);
        int parY = find(y);
        if(rank[parX] > rank[parY]){
            parent[parY] = parX;
        }else if(rank[parX] < rank[parY]){
            parent[parX] = parY;
        }else{
            parent[parX] = parY;
            rank[parY]++;
        }   
    }
};
class Solution {
public:

    int findCircleNum(vector<vector<int>>& G) {
        int n = G.size();
        UnionFind dsu(n);
        int numComp = n;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(G[i][j] && dsu.find(i) != dsu.find(j)){
                    numComp--;
                    dsu.union_set(i,j);
                }
            }
        }
        return numComp;
    }
};

//DFS

// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& G) {
//         int n = G.size();
//         vector<bool>vis(n,false);
//         int numProv = 0;
//         for(int i = 0;i < n;i++){
//             if(!vis[i]){
//                 numProv++;
//                 dfs(i,G,vis);
//             }
//         }
//         return numProv;
//     }

// private:
//     void dfs(int i,vector<vector<int>>& G,vector<bool>&vis){
//         int n = G.size();
//         vis[i] = true;
//         for(int j = 0;j < n;j++){
//             if(G[i][j] && !vis[j]){
//                 dfs(j,G,vis);
//             }
//         }
//     }
// };