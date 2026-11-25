// Last updated: 11/25/2026, 3:43:25 PM
class Solution {
public:
    int Sol1(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 1;
        if(nums[n-1] < count)return -1;
        while (count <= n) {
            if (n - count - 1 >= 0 && nums[n - count - 1] >= count) {
                count++;
                if (count < n && nums[n - count] < count) {
                    return -1;
                }
            } else {
                return count;
            }
        }
        return -1;
    }

int Sol2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int low = 1, high = n;
    
    if (nums[n - 1] < 1) return -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[n - mid] >= mid && (n - mid - 1 < 0 || nums[n - mid - 1] < mid)) {
            return mid;
        } else if (nums[n - mid] < mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}


    int specialArray(vector<int>& nums) {
        //return Sol1(nums);
        return Sol2(nums);
    }
};
