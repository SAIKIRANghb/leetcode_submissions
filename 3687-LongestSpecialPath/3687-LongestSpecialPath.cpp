// Last updated: 11/25/2026, 3:39:57 PM
class Solution {
public:
    vector<pair<int,int>>dp;
    map<int,pair<int,int>>last;
    vector<int>val;
    vector<vector<pair<int,int>>>adj;
    vector<pair<int,int>>lim;

    void dfs(int v,int par,int nodes,int len){
        if(par == -1){
            dp[v] = {0,1};
            lim[v] = {0,-1};
            last[val[v]] = {0,0};
            for(auto [x,wt] : adj[v]){
                last[val[v]].first += wt;
                if(x != par){
                    dfs(x,v,nodes + 1,len + wt);
                }
                last[val[v]].first -= wt;
            }
            last.erase(val[v]);
            return;
        }else{
            if(last.find(val[v]) != last.end()){
                lim[v] = max(lim[par],last[val[v]]); // max(last occurence of v,maxRange of immediate par)
                dp[v] = {len - lim[v].first,nodes - lim[v].second};
                auto temp = last[val[v]]; //save ot backtract after solving a case
                last[val[v]] = {len,nodes};
                for (auto [x,wt] : adj[v]){
                    last[val[v]].first += wt;
                    if(x != par){
                        dfs(x,v,nodes + 1,len + wt);
                    }
                    last[val[v]].first -= wt;
                }
                last[val[v]] = temp;
                return;
            }else{
                    lim[v] = lim[par];
                    dp[v] = {len - lim[v].first,nodes - lim[v].second};
                    last[val[v]] = {len,nodes};
                    for(auto [x,wt] : adj[v]){
                        last[val[v]].first += wt;
                        if(x != par){
                            dfs(x,v,nodes + 1,len + wt);
                        }
                        last[val[v]].first -= wt;
                    }
                    last.erase(val[v]);
                    return;
            }
        }
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        adj.resize(n);
        dp.resize(n);
        lim.resize(n);
        val = nums;

        for(auto x : edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        dfs(0,-1,0,0);
        pair<int,int>ans = dp[0];
        for(int i = 0;i < n;i++){
            if(ans.first < dp[i].first){
                ans = dp[i];
            }else if(ans.first == dp[i].first && dp[i].second < ans.second){
                ans = dp[i];
            }
        }
        return {ans.first,ans.second};
    }
};