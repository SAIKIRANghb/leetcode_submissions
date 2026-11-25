// Last updated: 11/25/2026, 3:46:04 PM
class DisjointSet {
public:
    vector<int> parent;
    vector<int> islandSize;

    DisjointSet(int n) {
        parent.resize(n);
        islandSize.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            islandSize[i] = 1;
        }
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void Union(int i, int j) {
        int parI = find(i);
        int parJ = find(j);
        if (parI == parJ) return;
        if (islandSize[parI] < islandSize[parJ]) {
            parent[parI] = parJ;
            islandSize[parJ] += islandSize[parI];
        } else {
            parent[parJ] = parI;
            islandSize[parI] += islandSize[parJ];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n * m);

        vector<int> rowDir = {1, -1, 0, 0};
        vector<int> colDir = {0, 0, 1, -1};
        bool hasZero = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) hasZero = true;
                if (grid[i][j] == 1) {
                    int currNode = (i * m) + j;
                    for (int dir = 0; dir < 4; dir++) {
                        int x = i + rowDir[dir];
                        int y = j + colDir[dir];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {  // Fix grid check
                            int neighbour = x * m + y;
                            ds.Union(currNode, neighbour);
                        }
                    }
                }
            }
        }

        if (!hasZero) return n * m;

        int maxIslandSize = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueRoots;
                    int currentIslandSize = 1;
                    
                    for (int dir = 0; dir < 4; dir++) {
                        int x = i + rowDir[dir];
                        int y = j + colDir[dir];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                            int neighbour = x * m + y;
                            int root = ds.find(neighbour);
                            uniqueRoots.insert(root);
                        }
                    }

                    for (int root : uniqueRoots) {
                        currentIslandSize += ds.islandSize[root];
                    }

                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;
    }
};

// class Solution {
// public:
//     int exploreIsland(vector<vector<int>>& grid,int islandId,int i,int j){
//         int n = grid.size(),m = grid[0].size();
//         if(i < 0 || i == n || j < 0 || j == m || grid[i][j] != 1)return 0;

//         grid[i][j] = islandId;
//         return 1 + (exploreIsland(grid,islandId,i + 1,j) + exploreIsland(grid,islandId,i - 1,j)
//                 + exploreIsland(grid,islandId,i,j + 1) + exploreIsland(grid,islandId,i,j - 1));
//     }
//     int largestIsland(vector<vector<int>>& grid) {
//         unordered_map<int,int>islandSizes;
//         int islandId = 2;
//         int ans = INT_MIN;
//         int n = grid.size();
//         int m = grid[0].size();
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<m;j++){
//                 if(grid[i][j] == 1){
//                     islandSizes[islandId] = exploreIsland(grid,islandId,i,j);
//                     islandId++;
//                 }
//             }
//         }
//         //no islands
//         if(islandSizes.empty())return 1;

//         if(islandSizes.size() == 1){
//             islandId--;//bcz last increment is not valid
//             return (islandSizes[islandId] == m*n) ? islandSizes[islandId] : islandSizes[islandId] + 1;
//         }

//         for(int i = 0;i < n;i++){
//             for(int j = 0;j<m;j++){
//                 if(grid[i][j] == 0){
//                     int currIslandSize = 1;
//                     unordered_set<int>neighboringIslands;

//                     if(i + 1 < n && grid[i + 1][j] > 1){
//                         neighboringIslands.insert(grid[i + 1][j]);
//                     }
//                     if(i - 1 >= 0 && grid[i - 1][j] > 1){
//                         neighboringIslands.insert(grid[i - 1][j]);
//                     }
//                     if(j - 1 >= 0 && grid[i][j - 1] > 1){
//                         neighboringIslands.insert(grid[i][j - 1]);
//                     }
//                     if(j + 1 < m && grid[i][j + 1] > 1){
//                         neighboringIslands.insert(grid[i][j + 1]);
//                     }
//                     for(int id : neighboringIslands){
//                         currIslandSize += islandSizes[id];
//                     }
//                     ans = max(ans,currIslandSize);
//                 }
//             }
//         }
//         return ans;
//     }
// };