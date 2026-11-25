// Last updated: 11/25/2026, 3:44:18 PM
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        queue<int>oddIndices;
        int ans = 0;
        int lastPop = -1,gap = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            if(nums[i] % 2 == 1){
                oddIndices.push(i);
            }
            if(oddIndices.size() > k){
                lastPop = oddIndices.front();
                oddIndices.pop();
            }
            if(oddIndices.size() == k){
                ans += (oddIndices.front() - lastPop);
            }
        }
        return ans;
    }
};