// Last updated: 11/25/2026, 3:49:26 PM
class Solution {
public:
    void solve(int ind,vector<int>&subset,vector<int>&nums,vector<vector<int>>&ans){
        int n = nums.size();

        ans.push_back(subset);

        if(ind == n)return;
        for(int i = ind;i < n;i++){
            if(i > ind && nums[i - 1] == nums[i])continue;
            subset.push_back(nums[i]);
            solve(i + 1,subset,nums,ans);
            subset.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>subset;
        solve(0,subset,nums,ans);
        return ans;
    }
};
