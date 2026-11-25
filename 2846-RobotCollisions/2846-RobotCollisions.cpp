// Last updated: 11/25/2026, 3:40:44 PM
// class Solution {
// public:
//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
//         vector<vector<int>> ans;
//         int n = positions.size();
//         priority_queue<pair<int, pair<int, char>>> pq;
//         unordered_map<int,int>mp;
//         // Push elements into priority queue
//         for (int i = 0; i < n; i++) {
//             pq.push({-positions[i], {healths[i], directions[i]}});
//         }

//         // Process each robot in the priority queue
//         for(int i = 0;i<n;i++) {
//             auto top = pq.top();
//             pq.pop();
//             int position = -top.first;
//             char direction = top.second.second;
//             int health = top.second.first;

//             // Check conditions to determine if the robot survives
//             if (!ans.empty() && (ans.back()[2] == 'R' && direction == 'L') && health < ans.back()[1]) {
//                 int ansHealth = ans.back()[1];
//                 char ansDir = ans.back()[2];
//                 int ansPos = ans.back()[0];
//                 ans.pop_back();
//                 mp.erase(ansPos);
//                 if (ansHealth > 1) {
//                     mp[ansPos] = ansHealth - 1;
//                     ans.push_back({ansPos, ansHealth - 1, ansDir});
//                 }
//                 continue;
//             }

//             while (!ans.empty() && (ans.back()[2] == 'R' && direction == 'L') && ans.back()[1] < health) {
//                 mp.erase(ans.back()[0]);
//                 ans.pop_back();
//                 health--;
//             }

//             if (!ans.empty() && (ans.back()[2] == 'R' && direction == 'L') && ans.back()[1] == health) {
//                 mp.erase(ans.back()[0]);
//                 ans.pop_back();
//                 continue;
//             }
//             mp[position] = health;
//             ans.push_back({position, health, direction});
//         }


//         // Extract the health values from ans to return
//         vector<int> result;
//         for(int i = 0;i<n;i++){
//             if(mp.find(positions[i]) != mp.end()){
//                 result.push_back(mp[positions[i]]);
//             }
//         }
//         return result;
//     }
// };

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ids;
        
        // Create vector of indices to positions
        for(int i = 0; i < n; i++) {
            ids.push_back(i);
        }
        
        // Comparator function to sort indices based on positions
        auto compare = [&](int id1, int id2) {
            return positions[id1] <= positions[id2];
        };
        
        // Sort indices based on positions
        sort(ids.begin(), ids.end(), compare);
        
        stack<int> st;
        
        // Process robots based on sorted order of positions
        for(auto id : ids) {
            if (directions[id] == 'R') {
                st.push(id); // Push robot id onto stack if it's facing right
            } else {
                // Process robots facing left
                while (!st.empty() && healths[id] > 0) {
                    if (healths[id] > healths[st.top()]) {
                        healths[id]--;
                        healths[st.top()] = 0;
                        st.pop();
                    } else if (healths[id] < healths[st.top()]) {
                        healths[id] = 0;
                        healths[st.top()]--;
                    } else {
                        healths[id] = 0;
                        healths[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        }
        if(n == 1)return healths;
        vector<int>ans;
        for(auto it : healths){
            if(it != 0){
                ans.push_back(it);
            }
        }
        return ans; // Return updated healths after processing
    }
};
