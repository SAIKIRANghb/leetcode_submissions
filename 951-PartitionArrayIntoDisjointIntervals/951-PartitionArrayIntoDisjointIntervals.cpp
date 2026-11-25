// Last updated: 11/25/2026, 3:45:42 PM
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        // int n = nums.size();
        // int leftMax[n],rightMin[n];
        // int min=INT_MAX,max=INT_MIN;
        // for(int i=0;i<n;i++){
        //     if(max < nums[i]){
        //         max=nums[i];
        //         leftMax[i]=max;
        //     }
        //         leftMax[i]=max;
        // }
        // for(int i=n-1;i>=0;i--){
        //     if(min > nums[i]){
        //         min=nums[i];
        //         rightMin[i]=min;
        //     }
        //         rightMin[i]=min;
        // }

        // for(int i=0;i<n-1;i++){
        //     if(leftMax[i] <= rightMin[i+1]){
        //         return i+1;
        //     }
        // }
        // return 1;

        int n = nums.size();
        int leftMax = nums[0];
        int greater = nums[0];
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i] > greater){
                greater = nums[i];
            }
            else if(nums[i] < leftMax){
                ans = i;
                leftMax = greater;
            }
        }
        return ans+1;
    }
};