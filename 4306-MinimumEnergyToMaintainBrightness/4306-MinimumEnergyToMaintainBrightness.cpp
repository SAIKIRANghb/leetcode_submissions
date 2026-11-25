// Last updated: 11/25/2026, 3:37:43 PM
class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        
        for(auto interval : intervals) {
            if(ans.size() >= 1) {
                if(ans.back()[1] >= interval[0]) {
                    vector<int> last = ans.back();
                    ans.pop_back();
                    ans.push_back({last[0],max(last[1], interval[1])});
                } else {
                    ans.push_back(interval);
                }
            } else {
                 ans.push_back(interval);
            }
        }

        return ans;
    }
    
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        intervals = mergeIntervals(intervals);
    
        long long ans = 0;
            
            for(auto interval : intervals) {
                ans += (interval[1] - interval[0] + 1);
            }

        long long multiplier = brightness < 3 ? 1 : ceil(brightness / 3.0);
        
        return ans * multiplier;
    }
};