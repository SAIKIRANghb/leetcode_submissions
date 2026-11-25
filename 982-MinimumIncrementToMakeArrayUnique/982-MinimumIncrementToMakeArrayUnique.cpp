// Last updated: 11/25/2026, 3:45:32 PM
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        int minInc = 0;

        for(int i = 0;i < n;i++){
            maxVal = max(maxVal,nums[i]);
        }

        vector<int>freq(n + maxVal,0);

        for(int i = 0;i < n;i++){
            freq[nums[i]]++;
        }

        for(int i = 0;i < freq.size();i++){
            if(freq[i] <= 1)continue;
            int duplicates = freq[i] - 1;
            freq[i + 1] += duplicates; 
            freq[i] = 1;
            minInc += duplicates;
        }
        return minInc;
    }
};


// class Solution {
// public:
//     int minIncrementForUnique(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         int ops = 0;
//         for(int i = 1;i < n;i++){
//             if(nums[i - 1] >= nums[i]){
//                 ops += nums[i - 1] - nums[i] + 1;
//                 nums[i] = nums[i - 1] + 1;
//             }
//         }
//         return ops;
//     }
// };