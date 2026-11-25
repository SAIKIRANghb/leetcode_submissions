// Last updated: 11/25/2026, 3:39:00 PM
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        //diff count 
        unordered_map<int,int>currDiff;
        //nums[i] <= k ==> diff <= k so define the array to maintain counts of [diff] with size k + 1 
        vector<int>oneOp(k+1,0);
        //First take the number of pairs that a specific diff is occuring thats the num of pairs with 0 Ops
        //Then take the number of pairs for each diff after 1 op 
        //Remove the  
        for(int i=0;i<n/2;i++){
            int diff = abs(nums[i]-nums[n-i-1]);
            currDiff[diff]++;
            int minEl = min(nums[i],nums[n-i-1]);
            int maxEl = max(nums[i],nums[n-i-1]);
            int maxAchievedDiff = max(k - minEl,maxEl);
            oneOp[maxAchievedDiff]++;
        }  
        for(int mad = k - 1;mad >= 0;mad--){
            oneOp[mad] += oneOp[mad+1];
        }
        //another pairs also contribute to the no diff pairs of one [diff] so the number of pairs for a [diff] after constructing oneOp[] increases
        //so removing the original number of pairs that previously existed without 1 operation performed should be removed from the oneOp[]
        int ans = INT_MAX;
        for(auto &[diff,count] : currDiff){
            int oneOps = oneOp[diff] - count;
            int twoOps = n / 2 - oneOps - count;
            ans = min(ans,oneOps + 2*twoOps);
        }
        return ans;
    }
};
