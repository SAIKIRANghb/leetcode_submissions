// Last updated: 11/25/2026, 3:39:38 PM
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int nq = queries.size();
        if(n == 1)return vector<bool>(nq,true); 
        vector<int>maxReach(n,0);
        vector<bool>ans(nq,false);
        maxReach[0] = 0;
        for(int i = 1;i<n;i++){
            if(nums[i] % 2 != nums[i - 1] % 2){
                maxReach[i] = maxReach[i - 1];
            }else{
                maxReach[i] = i;
            }
        }
        for(int i = 0;i < nq;i++){
            int start = queries[i][0];
            int end = queries[i][1];
            if(maxReach[end] <= start){
                ans[i] = true;
            } 
        }
        return ans;
    }
};

// class Solution {
// public:
//     bool bs(int start,int end,vector<int>&violating){
//         int low = 0 , high = violating.size() - 1;
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             if(violating[mid] < start){
//                 low = mid + 1;
//             }else if(violating[mid] > end){
//                 high = mid - 1;
//             }else{
//                 return true;
//             }
//         }
//         return false;
//     }
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         int nq = queries.size();
//         if(n == 1)return vector<bool>(nq,true); 
//         vector<int>violating;
//         vector<bool>ans(nq,true);
//         for(int i = 1;i<n;i++){
//             if(nums[i]%2 == nums[i - 1]%2){
//                 violating.push_back(i);
//             }
//         }
//         for(int i = 0;i < nq ;i++){
//             vector<int>query = queries[i];
//             int start = query[0];
//             int end = query[1];
//             bool foundViolation = bs(start + 1,end,violating);
//             if(foundViolation){
//                 ans[i] = false;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         int nq = queries.size();
//         vector<int>prefix(n,0);
//         vector<bool>ans(nq,false);
//         prefix[0] = 0;
//         for(int i = 1;i<n;i++){
//             int mod = nums[i - 1] % 2;
//             if(mod == nums[i] % 2){
//                 prefix[i] = prefix[i - 1] + 1;
//             }else{
//                 prefix[i] = prefix[i - 1];
//             }
//         }

//         for(int i = 0;i<nq;i++){
//             int start = queries[i][0];
//             int end = queries[i][1];
//             if(prefix[end] - prefix[start] == 0){
//                 ans[i] = true;
//             }
//         }
//         return ans;
//     }
// };