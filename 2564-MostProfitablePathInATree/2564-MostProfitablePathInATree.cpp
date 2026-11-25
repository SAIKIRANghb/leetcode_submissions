// Last updated: 11/25/2026, 3:41:23 PM
class Solution {
    private:
    int n;
    vector<vector<int>>tree;
    vector<int>distanceFromBob;
public:
    int findPaths(int src,int parent,int time,int bob,vector<int>&amounts){
        int maxIncome = 0,maxChild = INT_MIN;
        if(src == bob){
            distanceFromBob[src] = 0;
        }else{
            distanceFromBob[src] = n;
        }

        for(int adj : tree[src]){
            if(adj != parent){
                maxChild = max(maxChild,findPaths(adj,src,time + 1,bob,amounts));
                distanceFromBob[src] = min(distanceFromBob[src],distanceFromBob[adj] + 1);
            }
        }
        
        //First complete the recursion and while backtract calculate values
        //dist is not of Bobs path then it is distFromBob = n which is max time that can be
        if(distanceFromBob[src] > time){
            maxIncome += amounts[src];
        }
        else if(distanceFromBob[src] == time){
            maxIncome += amounts[src] / 2;
        }
        if(maxChild == INT_MIN)return maxIncome;
        else{
            return maxIncome + maxChild;
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n = amount.size();
        tree.resize(n);
        distanceFromBob.resize(n);
        for(vector<int>edge : edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        //src,parent,time,bob,amount arr
        return findPaths(0,0,0,bob,amount);
    }

};


// class Solution {
// private:
//     vector<vector<int>> tree;
//     vector<int> distanceFromBob;
//     int n;
// public:
//  //since it is tree just keeping parent is sufficient instead of vis array
//     int findPaths(int src,int parent,int time,int bob,vector<int>&amount){ 
//         int maxIncome = 0, maxChild = INT_MIN;
//         if(src == bob){
//             distanceFromBob[src] = 0;
//         }else{
//             distanceFromBob[src] = n;
//         }
//         for(int adj : tree[src]){
//             if(adj != parent){
//                 maxChild = max(maxChild,findPaths(adj,src,time + 1,bob,amount));
//                 distanceFromBob[src] = min(distanceFromBob[src],distanceFromBob[adj] + 1);
//             }
//         }
//         if(distanceFromBob[src] > time)maxIncome += amount[src];
//         else if(distanceFromBob[src] == time){
//             maxIncome += amount[src] / 2;
//         }

//         if(maxChild == INT_MIN)return maxIncome;
//         else{
//             return maxIncome + maxChild;
//         }
//     }
//     int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
//         n = amount.size();
//         tree.resize(n,vector<int>());

//         for(vector<int>edge : edges){
//             tree[edge[0]].push_back(edge[1]);
//             tree[edge[1]].push_back(edge[0]);
//         }
//         distanceFromBob.resize(n);
//         return findPaths(0,0,0,bob,amount);
//     }
// };

// class Solution {
// public:
//     unordered_map<int,int>bobPath;
//     vector<vector<int>>adjLst;
//     vector<bool>vis;

//     int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
//         int n = amount.size();
//         int maxIncome = INT_MIN;
//         adjLst.resize(n);
//         vis.assign(n,false);

//         for(vector<int>edge : edges){
//             int x = edge[0];
//             int y = edge[1];
//             adjLst[x].push_back(y);
//             adjLst[y].push_back(x);
//         }

//         findBobPath(bob,0);

//         vis.assign(n,false);

//         queue<vector<int>>q;
//         vis[0] = true;
//         q.push({0,0,0});
//         while(!q.empty()){
//             int src = q.front()[0],time = q.front()[1],income = q.front()[2];

//             if(!bobPath.count(src) || time < bobPath[src]){
//                 income += amount[src];
//             }else if(bobPath[src] == time){
//                 income += (amount[src] / 2);
//             }
//             if(adjLst[src].size() == 1 && src != 0){
//                 maxIncome = max(maxIncome,income);
//             }
//             for(int adj : adjLst[src]){
//                 if(!vis[adj])q.push({adj,time + 1,income});
//             }
//             q.pop();
//             vis[src] = true;//vis and pop can be here or at begining bcz it's a tree
//         }
//         return maxIncome;
//     }
//     bool findBobPath(int src,int time){
//         if(src == 0)return true;
//         vis[src] = true;
//         bobPath[src] = time;
//         for(int adj : adjLst[src]){
//             if(!vis[adj] && findBobPath(adj,time + 1)){
//                 return true;
//             }
//         }
//         bobPath.erase(src);
//         return false;
//     }
// };
