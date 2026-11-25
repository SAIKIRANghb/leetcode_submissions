// Last updated: 11/25/2026, 3:41:21 PM
class Solution {
public:
    vector<int>gr[505];
    int color[505];
    bool isBipartite;
    vector<int>connectedComponentNodes;

    int getMaxDistanceFromNode(int src,int totalNodes){
        vector<int>distance(totalNodes + 1, -1);
        queue<int>q;
        q.push(src);
        distance[src] = 1;
        int maxDistance = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int &neighbor : gr[curr]){
                if(distance[neighbor] == -1){
                    distance[neighbor] = distance[curr] + 1;
                    q.push(neighbor);
                    maxDistance = max(maxDistance,distance[neighbor]);
                }
            }
        }
        return maxDistance;
    }
    void dfs(int i,int currentColor = 1){
        color[i] = currentColor;
        connectedComponentNodes.push_back(i);

        for(int &neighbour : gr[i]){
            if(!color[neighbour]){
                dfs(neighbour,3 - currentColor);
            }else if(color[neighbour] == currentColor){
                isBipartite = false;
            }
        }
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        for(int i = 1;i <= n;i++)gr[i].clear();
        memset(color,0,sizeof color);

        for(auto &edge : edges){
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        int maxGroups = 0;

        for(int i = 1;i <= n;i++){
            if(color[i] == 0){
                connectedComponentNodes.clear();
                isBipartite = true;
                dfs(i);
                if(!isBipartite)return -1;

                int maxComponentDistance = 0;
                for(int &node : connectedComponentNodes){
                    maxComponentDistance = max(maxComponentDistance,getMaxDistanceFromNode(node,n));
                }
                maxGroups += maxComponentDistance;
            }
        }
        return maxGroups;
    }
};