// Last updated: 11/25/2026, 3:49:33 PM
class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&subset){
        int n = nums.size();

        ans.push_back(subset);
        if(ind == n)return;
        for(int i = ind;i < n;i++){
            subset.push_back(nums[i]);
            solve(i + 1,nums,ans,subset);
            subset.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        solve(0,nums,ans,subset);
        return ans;
    }
};