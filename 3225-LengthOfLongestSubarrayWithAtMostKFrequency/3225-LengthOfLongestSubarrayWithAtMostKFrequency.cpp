// Last updated: 11/25/2026, 3:40:13 PM
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, pair<int, int>> umap; 

        int i = 0, j = 0;
        int maxLen = 0; 
        // for (int i = 0; i < n; ++i) {
        //     umap[nums[i]].first = -1;
        // }
        
        while (i < n && j < n) {
            if (umap[nums[j]].second < k) {
                if (umap[nums[j]].first == 0) {
                    umap[nums[j]].first = j;
                }
                umap[nums[j]].second++;
                maxLen = max((j - i) + 1, maxLen);
                ++j;
            } else {
                // Adjust the window by moving the start pointer
                while (i < n && umap[nums[i]].first < umap[nums[j]].first) {
                    umap[nums[i]].second--;
                    if (umap[nums[i]].second == 0) {
                        umap[nums[i]].first = 0;
                    }
                    i++;
                }
                // Move start pointer to the next occurrence of the current element
                umap[nums[i]].first = i;
                umap[nums[i]].second--;
                i++;
            }
        }
        return maxLen;
    }
};
