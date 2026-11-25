// Last updated: 11/25/2026, 3:41:36 PM
// class Solution {
// public:
//     vector<vector<int>> buildGraph(int k ,vector<vector<int>>&conditions){
//         vector<vector<int>>graph(k+1);
//         for(auto edge : conditions){
//             int u = edge[0];
//             int v = edge[1];
//             graph[u].push_back(v);
//         }
//         return graph;
//     }
//     vector<int>topoOrder(int k,vector<vector<int>>gr){
//         vector<int>indeg(k+1,0);
//         vector<int>vis(k+1,0);
//         vector<int>topoSort;
//         queue<int>q;

//         for(auto u : gr){
//             for(auto v : u){
//                 indeg[v]++;
//             }
//         }
//         for(int i = 1;i<=k;i++){
//             if(indeg[i] == 0)q.push(i);
//         }
//         while(!q.empty()){
//             int sz = q.size();
//             while(sz--){
//                 int node = q.front();
//                 q.pop();
//                 vis[node] = true;
//                 topoSort.push_back(node); 
//                 for(auto child : gr[node]){
//                     if(!vis[child]){
//                         indeg[child]--;
//                         if(indeg[child] == 0){
//                             q.push(child);
//                         }
//                     }
//                 }
//             }
//         }
//         for(auto i : indeg){
//             if(i != 0)return {};
//         }
//         return topoSort;
//     }

//     void fillTopo(vector<int>& xTopo , int k){
//         unordered_map<int,bool>vis;
//         for(auto node : xTopo){
//             vis[node] = true;
//         }

//         for(int node = 1;node<=k;node++){
//             if(!vis[node]){
//                 xTopo.push_back(node);
//             }
//         }
//     }
//     vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
//         vector<vector<int>>rowGraph = buildGraph(k,rowConditions);
//         vector<vector<int>>colGraph = buildGraph(k,colConditions);

//         vector<int>rowTopo = topoOrder(k,rowGraph);
//         vector<int>colTopo = topoOrder(k,colGraph);
//         vector<vector<int>>ans;
//         if(rowTopo.size() == 0 || colTopo.size() == 0)return ans;
//         fillTopo(rowTopo,k);
//         fillTopo(colTopo,k);

//         unordered_map<int,int>colIndex;
//         for(int i = 0;i<k;i++){
//             colIndex[colTopo[i]] = i;
//         }
//         ans = vector<vector<int>>(k,vector<int>(k,0));
//         for(int i = 0;i<k;i++){
//             ans[i][colIndex[rowTopo[i]]] = rowTopo[i];
//         }
//         return ans;
//     }
// };
















class Solution {
public:
    vector<int>topoOrder(int k,vector<vector<int>>&gr){
        vector<int>indeg(k+1,0);

        for(int node = 1;node<=k;node++){
            for(auto child : gr[node]){
                indeg[child]++;
            }
        }
        queue<int>q;
        vector<int>vis(k+1,0);

        for(int node = 1;node<=k;node++){
            if(indeg[node] == 0){
                q.push(node);
            }
        }
        vector<int>topoSort;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                vis[node] = true;
                topoSort.push_back(node);
                for(auto child : gr[node]){
                    if(!vis[child]){
                        indeg[child]--;
                        if(indeg[child] == 0)q.push(child);
                    }
                }
            }
        }
        vector<int>notTopo;
        for(int node = 1;node<=k;node++){
            if(indeg[node] != 0)return notTopo;
        }
        return topoSort;
    }
    vector<vector<int>>buildGraph(int k,vector<vector<int>>& conditions){
        vector<vector<int>>gr(k+1);

        for(auto &condition : conditions){
            int u = condition[0],v = condition[1];
            gr[u].push_back(v);
        }
        return gr;
    }
    void fillTopoArray(int k,vector<int>&xTopo){
        unordered_map<int,bool>vis;
        for(auto el : xTopo)vis[el] = true;

        for(int el = 1;el<=k;el++){
            if(!vis[el])xTopo.push_back(el);
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>rowGr = buildGraph(k,rowConditions);
        vector<vector<int>>colGr = buildGraph(k,colConditions);

        vector<int>rowTopo = topoOrder(k,rowGr);
        vector<int>colTopo = topoOrder(k,colGr);
        vector<vector<int>>ans;
        if(rowTopo.size() == 0 || colTopo.size() == 0)return ans;

        fillTopoArray(k,rowTopo);
        fillTopoArray(k,colTopo);
        unordered_map<int,int>colInd;

        for(int j=0;j<k;j++){
            colInd[colTopo[j]] = j;
        }
        ans = vector<vector<int>>(k,vector<int>(k,0));
        for(int i = 0;i<k;i++){
            ans[i][colInd[rowTopo[i]]] = rowTopo[i];
        }
        return ans;
    }
};
