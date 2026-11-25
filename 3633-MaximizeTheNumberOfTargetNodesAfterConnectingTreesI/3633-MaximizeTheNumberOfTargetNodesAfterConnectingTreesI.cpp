// Last updated: 11/25/2026, 3:38:20 PM
class Solution {
public:
    // BFS from a single start node up to depth k
    int bfs(int start, vector<vector<int>>& graph, int k) {
        int n = graph.size();
        vector<bool> vis(n, false);
        queue<pair<int, int>> q;  // {node, depth}
        q.push({start, 0});
        vis[start] = true;
        int count = 1;  // count the start node

        while (!q.empty()) {
            auto [u, depth] = q.front();
            q.pop();
            if (depth == k) continue;
            for (int v : graph[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push({v, depth + 1});
                    count++;
                }
            }
        }
        return count;
    }

    // Build graph and run BFS for each node
    vector<int> build(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> count(n);
        for (int i = 0; i < n; i++) {
            count[i] = bfs(i, graph, k);
        }
        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        if(k == 0){
            return vector<int>(edges1.size() + 1,1);
        }
        vector<int> count1 = build(edges1, k);
        vector<int> count2 = build(edges2, k - 1);
        int maxTargetOf2 = *max_element(count2.begin(), count2.end());
        int n = edges1.size() + 1;
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            res[i] = count1[i] + maxTargetOf2;
        }
        return res;
    }
};
