// Last updated: 11/25/2026, 3:41:19 PM
class Cell{
public:
    int row;
    int col;
    int value;
    Cell(int r,int c,int v) : row(r) ,col(c), value(v){}
};

class Query{
public: 
    int index;
    int value;
    Query(int i,int v) : index(i) , value(v) {}
};

bool operator<(const Query &a,const Query &b){ return a.value < b.value; }
bool operator<(const Cell &a,const Cell &b){ return a.value < b.value; }

class UnionFind{
    vector<int>parent;
    vector<int>size;
public:
    UnionFind(int n) : parent(vector<int>(n,-1)) , size(vector<int>(n,1)) {};

    int Find(int x){
        if(parent[x] < 0)return x;

        return parent[x] = Find(parent[x]);
    }
    bool Union(int x,int y){
        int parX = Find(x);
        int parY = Find(y);

        if(parX == parY){
            return false;
        }
        if(size[parX] > size[parY]){
            parent[parY] = parX;
            size[parX] += size[parY];
        }else{
            parent[parX] = parY;
            size[parY] += size[parX]; 
        }
        return true;
    }
    int getSize(int x){
        return size[Find(x)];
    }
};

const vector<int>ROW_DIRECTIONS = {0,0,1,-1};
const vector<int>COL_DIRECTIONS = {1,-1,0,0};
class Solution{
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size() , n = grid[0].size();
        int totalCells = m * n;

        vector<Query>sortedQueries;

        for(int i = 0;i < queries.size();i++){
            sortedQueries.push_back(Query(i,queries[i]));
        }
        sort(sortedQueries.begin(),sortedQueries.end());

        vector<Cell>sortedCells;
        for(int row = 0;row < m;row++){
            for(int col = 0;col < n;col++){
                sortedCells.push_back(Cell(row,col,grid[row][col]));
            }
        }

        sort(sortedCells.begin(),sortedCells.end());

        UnionFind uf = UnionFind(totalCells);
        vector<int>result(queries.size());
        int cellInd = 0;

        for(Query query : sortedQueries){
            while(cellInd < totalCells && sortedCells[cellInd].value < query.value){
                int row = sortedCells[cellInd].row;
                int col = sortedCells[cellInd].col;

                int cellId = row * n + col;

                for(int i = 0;i < 4;i++){
                    int newRow = row + ROW_DIRECTIONS[i];
                    int newCol = col + COL_DIRECTIONS[i];
                    if(newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && grid[newRow][newCol] < query.value){
                        uf.Union(cellId,newRow * n + newCol);
                    }
                }
                cellInd++;
            }
            // Get the size of the connected component containing the top-left
            // cell (0,0)
            result[query.index] = query.value > grid[0][0] ? uf.getSize(0) : 0;
        }
        return result;
    }
};
// class Solution {
// public:
//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//         int queryCnt = queries.size();
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<int>result(queryCnt,0);

//         vector<int>dx = {0,0,-1,1};
//         vector<int>dy = {-1,1,0,0};

//         vector<vector<int>>minValToReach(m,vector<int>(n,INT_MAX));
//         int totalPoints = m * n;
//         //minimum |query| val required to achieve the required no of points 
//         vector<int>thresholdForMaxPoints(totalPoints + 1,0); 

//         int points = 0;

//         priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>>pq;

//         pq.push({grid[0][0] , 0 , 0});

//         minValToReach[0][0] = grid[0][0];

//         while(!pq.empty()){
//             vector<int>curr = pq.top();
//             pq.pop();
//             thresholdForMaxPoints[++points] = curr[0];
//             for(int i = 0;i < 4;i++){
//                 int newX = curr[1] + dx[i];
//                 int newY = curr[2] + dy[i];
//                 if(newX < m && newY < n && newX >= 0 && newY >= 0 && minValToReach[newX][newY] == INT_MAX){
//                     minValToReach[newX][newY] = max(curr[0] , grid[newX][newY]);
//                     pq.push({minValToReach[newX][newY],newX,newY});
//                 }
//             }
//         }
//         for(int i = 0;i < queryCnt;i++){
//             int l = 0 , r = totalPoints;
//             int query = queries[i];
//             while(l <= r){
//                 int mid = l + (r - l) / 2;
//                 if(thresholdForMaxPoints[mid] < query){
//                     l = mid + 1;
//                 }else{
//                     r = mid - 1;
//                 }
//             }
//             result[i] = r;
//         }
//         return result;
//     }
// };


//T.C : O(klogk+n⋅mlog(n⋅m))  || S.C : O(n⋅m+k)

// class Solution {
// public:
//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
//         int m = grid.size(),n = grid[0].size();

//         vector<vector<bool>>vis(m,vector<bool>(n,0));
//         vector<vector<int>>sortedQueries(queries.size(),vector<int>(2,0));
//         for(int i = 0;i < queries.size();i++){
//             sortedQueries[i][0] = queries[i];
//             sortedQueries[i][1] = i; 
//         }
//         sort(sortedQueries.begin(),sortedQueries.end());
//         vector<int>ans(queries.size(),0);
//         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
//         pq.push({grid[0][0],0,0});
//         vis[0][0] = true;
//         int points = 0;
//         for(vector<int>iterate : sortedQueries){
//             int queryVal = iterate[0] , queryInd = iterate[1];
//             while(!pq.empty() && pq.top()[0] < queryVal){
//                 vector<int>top = pq.top();
//                 pq.pop();
//                 int currX = top[1] , currY = top[2];
//                 points++;

//                 vector<int>dx = {0,0,1,-1};
//                 vector<int>dy = {1,-1,0,0};
//                 for(int i = 0;i < 4;i++){
//                     int newX = currX + dx[i];
//                     int newY = currY + dy[i];
//                     if(newX >= 0 && newY >= 0 && newX < m && newY < n && !vis[newX][newY]){
//                         vis[newX][newY] = true;
//                         pq.push({grid[newX][newY],newX,newY});
//                     }
//                 } 
//             }
//             ans[queryInd] = points;
//         }   
//         return ans;
//     }
// };