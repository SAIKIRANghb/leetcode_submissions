// Last updated: 11/25/2026, 3:49:35 PM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int x = 0, z = n - 1, i = 0;

        while (i <= z) {
            if (nums[i] == 0) {
                swap(nums[i], nums[x]);
                x++;
                i++; // Increment because the swapped element is now in the correct position
                //if every number before index i will 0 or 1 because 2's are already sent to end 
            } 
            else if (nums[i] == 2) {
                swap(nums[i], nums[z]);
                z--; // Do not increment i because the swapped element at index i needs to be re-evaluated
            } 
            else {
                i++; // Increment for nums[i] == 1
            }
        }
    }
};
