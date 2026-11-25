// Last updated: 11/25/2026, 3:41:34 PM
class Solution {
public:
    int digSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum = -1;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int digS = digSum(nums[i]);
            int maxi = INT_MIN;
            if(mp.count(digS)){
                sum = max(mp[digS] + nums[i],sum);
                maxi = max(mp[digS],nums[i]);
            }
            mp[digS] = max(nums[i],maxi);
        }
        return sum;
    }
};