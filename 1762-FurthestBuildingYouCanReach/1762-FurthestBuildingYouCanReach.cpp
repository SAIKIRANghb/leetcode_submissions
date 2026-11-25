// Last updated: 11/25/2026, 3:43:20 PM
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>pq;
        int building = 0;
        while(building < n - 1){
            if(heights[building + 1] - heights[building] <= 0){
                building++;
                continue;
            }
            int diff = heights[building + 1] - heights[building];
            pq.push(diff);
            bricks -= diff;
            if(bricks >= 0){    
                building++;
            }else if(bricks < 0){
                if(ladders <= 0)return building;
                bricks += pq.top();
                pq.pop();
                building++;
                ladders--;
            }
        }
        return n - 1;
    }
};
/*#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<pair<int,int>> pq;
        int n = heights.size();

        for(int i = 0; i < n - 1; i++) {
            if(heights[i + 1] <= heights[i]) {
                continue;
            }
            int diff = heights[i + 1] - heights[i];
            
            if(!pq.empty()) {
                if(pq.top().second == 1 && ladders > 0) {
                    int First = pq.top().first;
                    int Second = pq.top().second;
                    pq.pop();
                    Second = 0;
                    bricks += First;
                    ladders--;
                    pq.push({First, Second});
                }
            }
            
            if(diff <= bricks) {
                pq.push({diff, 1});
                bricks -= diff;
            } else if(ladders > 0) {
                if(!pq.empty() && diff > pq.top().first&&bricks>=(diff - pq.top().first+1)) {
                    int First = pq.top().first;
                    int Second = pq.top().second;
                    pq.pop();
                    Second = 1;
                    // bricks += First;
                    bricks += (diff - First+1);
                    pq.push({diff, Second});
                } else {
                    ladders--;
                    pq.push({diff, 0});
                }
            } else {
                return i;
            }
        }
        return n - 1;
    }
};
*/