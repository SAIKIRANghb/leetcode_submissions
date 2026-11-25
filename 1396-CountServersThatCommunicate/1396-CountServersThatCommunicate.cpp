// Last updated: 11/25/2026, 3:44:14 PM
class Solution {
public:
    vector<int>parent,rank;
    int find(int x){
        if(x == parent[x])return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a  ,int b){
        int a_par = find(a);
        int b_par = find(b);

        if(a_par == b_par)return;

        if(rank[a_par] > rank[b_par]){
            parent[b_par] = a_par;
        }
        else if(rank[b_par] > rank[a_par]){
            parent[a_par] = b_par;
        }else{
            parent[a_par] = b_par;
            rank[b_par]++;
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = m*n;
        parent.resize(size);
        rank.resize(size);

        for(int i = 0;i<size;i++){
            parent[i] = i;
        }

        //Union by row
        for(int i = 0;i < n;i++){
            int parentServer = -1;
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1){
                    //this is the first server in the row
                    //we union all other servers in same row with this
                    if(parentServer == -1){
                        //converting 2D array coordinates into index
                        parentServer = i * m + j;
                    }
                    else{
                        Union(parentServer,i*m + j);
                    }
                }
            }
        }

        for(int j = 0;j < m;j++){
            int parentServer = -1;
            for(int i = 0;i < n;i++){
                if(grid[i][j] == 1){
                    //this is the first server in the col
                    //we union all other servers in same col with this
                    if(parentServer == -1){
                        parentServer = i*m + j;
                    }else{
                        Union(parentServer,i*m + j);
                    }
                }
            }
        }
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1){
                    mp[find(i*m + j)]++;
                }
            }
        }
        int canCommunicate = 0;

        for(auto &it : mp){
            int count = it.second;
            if(count > 1){
                canCommunicate += count;
            }
        }
        return canCommunicate;
    }
};

// class Solution {
// public:
//     int countServers(const vector<vector<int>>& grid) {
//         int communicableServersCount = 0;
//         vector<int> colCount(size(grid[0]), 0),
//             lastServerInRow(size(grid), -1);

//         // First pass to count servers in each row and column
//         for (int row = 0; row < size(grid); ++row) {
//             int serverCountInRow = 0;
//             for (int col = 0; col < size(grid[0]); ++col)
//                 if (grid[row][col]) {
//                     serverCountInRow++;
//                     colCount[col]++;
//                     lastServerInRow[row] = col;
//                 }
//             // If there is more than one server in the row, increase the count
//             if (serverCountInRow != 1)
//                 communicableServersCount += serverCountInRow,lastServerInRow[row] = -1;
//         }

//         // Second pass to check if servers can communicate
//         for (int row = 0; row < size(grid); ++row)
//             communicableServersCount += lastServerInRow[row] != -1 &&
//                                         colCount[lastServerInRow[row]] > 1;

//         return communicableServersCount;
//     }
// };