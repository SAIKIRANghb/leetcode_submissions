// Last updated: 11/25/2026, 3:39:59 PM
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0] + nums[1] <= nums[2])return "none";
        if(nums[0] != nums[1]){
            if(nums[1] != nums[2]) return "scalene";
            else return "isosceles";
        }else{
            if(nums[1] != nums[2])return "isosceles";
            else return "equilateral";
        }

    }
};