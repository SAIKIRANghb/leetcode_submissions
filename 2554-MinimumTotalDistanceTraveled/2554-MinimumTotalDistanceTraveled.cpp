// Last updated: 11/25/2026, 3:41:24 PM

class Solution {
public:
    vector<vector<long long>> dp;

    long long solve(int r, int f, vector<int>& robot, vector<vector<int>>& factory) {
        if (r < 0) return 0;  // All robots assigned successfully
        if (f < 0) return LONG_MAX / 10;  // No factory left, but robots remain

        if (dp[r][f] != -1) return dp[r][f];

        long long Pick = LONG_MAX, notPick = LONG_MAX;



        // Option 1: Try assigning up to `factory[f][1]` robots to this factory
        int limit = min(factory[f][1], r + 1);  // max robots we can assign is factory capacity or remaining robots
        long long distance = 0;
        
        for (int i = 0; i < limit; ++i) {
            distance += abs(factory[f][0] - robot[r - i]);  // Accumulate distance for each assigned robot
            Pick = min(Pick, distance + solve(r - i - 1, f - 1, robot, factory));  // Assign up to `limit` robots
        }
        // Option 2: Skip this factory
        notPick = solve(r, f - 1, robot, factory);

        return dp[r][f] = min(Pick, notPick);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int nr = robot.size();
        int nf = factory.size();
        dp = vector<vector<long long>>(nr, vector<long long>(nf, -1));

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        return solve(nr - 1, nf - 1, robot, factory);
    }
};

// class Solution {
// public:
//     vector<vector<long long>>dp;
//     long long solve(int r,int f,vector<int>&robot,vector<int>&positions){
//         if(r >= robot.size()){
//             return 0;
//         }
//         if(f >= positions.size()){
//             return LONG_MAX/10;
//         }
//         if(dp[r][f] != -1)return dp[r][f];
//         long long take = abs(robot[r] - positions[f]) + solve(r + 1,f + 1,robot,positions);
//         long long skip = solve(r,f + 1,robot,positions);
//         return dp[r][f] = min(take,skip);
//     }
//     long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//         //Step-1
//         sort(robot.begin(),robot.end());
//         sort(factory.begin(),factory.end());
//         int nr = robot.size();
//         //Step-2
//         vector<int>positions;
//         for(int i = 0;i < factory.size();i++){
//             int limit = factory[i][1];
//             int pos = factory[i][0];
//             for(int j = 0;j<limit;j++){
//                 positions.push_back(pos);
//             }
//         }
//         int nf = positions.size();
//         dp = vector<vector<long long>>(nr,vector<long long>(nf,-1));
//         //Step-3  Solve
//         return solve(0,0,robot,positions);
//     }
// };


// class Solution {
// public:
//     vector<vector<vector<long long>>> dp;

//     long long solve(int r, int f, int capacity_used, vector<int>& robot, vector<vector<int>>& factory) {
//         if (r < 0) return 0; // All robots assigned successfully
//         if (f < 0) return LONG_MAX / 10; // No factory left, but robots remain

//         if (dp[r][f][capacity_used] != -1) return dp[r][f][capacity_used];

//         long long Pick = LONG_MAX, notPick = LONG_MAX;

//         // "Pick" option: assign this robot to the current factory if capacity allows
//         if (capacity_used < factory[f][1]) {
//             Pick = abs(factory[f][0] - robot[r]) + solve(r - 1, f, capacity_used + 1, robot, factory);
//         }

//         // "NotPick" option: move to the next factory
//         notPick = solve(r, f - 1, 0, robot, factory); // Reset capacity when moving to a new factory

//         return dp[r][f][capacity_used] = min(Pick, notPick);
//     }

//     long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//         int nr = robot.size();
//         int nf = factory.size();

//         // 3D DP array to store state for each robot, factory, and capacity used
//         dp = vector<vector<vector<long long>>>(nr, vector<vector<long long>>(nf, vector<long long>(101, -1)));

//         sort(robot.begin(), robot.end());
//         sort(factory.begin(), factory.end());

//         return solve(nr - 1, nf - 1, 0, robot, factory);
//     }
// };
