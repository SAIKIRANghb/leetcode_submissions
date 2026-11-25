// Last updated: 11/25/2026, 3:40:10 PM
class Solution {
public:
    void dijkstra(char source, unordered_map<char,vector<pair<char,int>>>& adj, vector<vector<long long>>& costMatrix) {
        priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> pq;
        pq.push({0, source});
        costMatrix[source - 'a'][source - 'a'] = 0;  // Distance from source to itself is 0

        while (!pq.empty()) {
            long long d = pq.top().first;
            char node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                char adjacent = it.first;
                int cost = it.second;

                if (costMatrix[source - 'a'][adjacent - 'a'] > d + cost) {
                    costMatrix[source - 'a'][adjacent - 'a'] = d + cost;
                    pq.push({d + cost, adjacent});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;

        for (int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<long long>> costMatrix(26, vector<long long>(26, LLONG_MAX));

        for (int i = 0; i < source.length(); i++) {
            char ch = source[i];
            dijkstra(ch, adj, costMatrix);
        }

        long long ans = 0;

        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) continue;

            if (costMatrix[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX) {
                return -1;
            }
            ans += costMatrix[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};

/*
class Solution {
public:
    void FloydWarshall(vector<vector<long long>> &adj,vector<char>& original, vector<char>& changed, vector<int>& cost){
        for(int i=0;i<original.size();i++){
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            adj[s][t] = min(adj[s][t],(long long)cost[i]);
        }
        for(int k = 0;k<26;k++){
            for(int i = 0;i<26;i++){
                for(int j = 0;j<26;j++){
                    adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        vector<vector<long long>>adj(26,vector<long long>(26,INT_MAX));

        FloydWarshall(adj,original,changed,cost);

        long long ans = 0;

        for(int i = 0;i<source.length();i++){
            if(source[i] == target[i])continue;

            if(adj[source[i] - 'a'][target[i] - 'a'] == INT_MAX){
                return -1;
            }
            ans += adj[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};
*/