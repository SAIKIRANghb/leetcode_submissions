// Last updated: 11/25/2026, 3:49:50 PM
class Solution {
public:
    void nextPerm(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            // Find the next larger element to swap with
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        
        // Reverse the elements after position i
        reverse(nums.begin() + i + 1, nums.end());
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        bool flag = true;
        int first = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(first != nums[i]){
                flag = false;
            }
        }
        if(flag) {
            ans.push_back(nums);
            return ans;
        }
        sort(nums.begin(), nums.end()); // Start with the smallest lexicographical order
        
        do {
            ans.push_back(nums);
            nextPerm(nums);
        } while (!isSortedDescending(nums)); // Continue until all permutations are generated
        if(nums.size() > 1)ans.push_back(nums);
        return ans;
    }
    private:
    bool isSortedDescending(const vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) return false;
        }
        return true;
    }
};