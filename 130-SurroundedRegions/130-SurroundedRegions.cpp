// Last updated: 11/25/2026, 3:48:54 PM
class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0;i < n;i++)parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]);
    }
    void union_find(int x,int y){
        int parX = find(x);
        int parY = find(y);
        if(rank[parX] > rank[parY]){
            parent[parY] = parX;
        }else if(rank[parY] > rank[parX]){
            parent[parX] = parY;
        }else{
            parent[parX] = parY;
            rank[parX]++;
        }
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        DSU dsu(m * n + 1);
        int dummyNode = m * n;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    int node = i * n + j;
                    if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                        dsu.union_find(node, dummyNode);
                    } else {
                        for (int k = 0; k < 4; k++) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny] == 'O') {
                                int adj = nx * n + ny;
                                dsu.union_find(node, adj);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && dsu.find(i * n + j) != dsu.find(dummyNode)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
