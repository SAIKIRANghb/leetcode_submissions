// Last updated: 11/25/2026, 3:47:16 PM
class Solution {
public:
    void merge(vector<int>& arr, int start, int mid, int end) {
        int i = start; // Left subarray pointer
        int j = mid + 1; // Right subarray pointer
        int index = 0; // Index for temp array

        vector<int> ans(end - start + 1); // Temporary array

        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                ans[index++] = arr[i++];
            } else {
                ans[index++] = arr[j++];
            }
        }

        // Copy remaining elements from left subarray
        while (i <= mid) {
            ans[index++] = arr[i++];
        }

        // Copy remaining elements from right subarray
        while (j <= end) {
            ans[index++] = arr[j++];
        }

        // Copy back the merged elements to the original array
        for (int k = start; k <= end; k++) {
            arr[k] = ans[k - start];
        }

    }
    int mergeSort(vector<int>& arr, int start, int end) {
        if (start >= end) return 0; // Base condition: Single element

        int mid = start + (end - start) / 2; // Avoid overflow
        int left = mergeSort(arr, start, mid); // Count inversions in left half
        int right = mergeSort(arr, mid + 1, end); // Count inversions in right half
        int j = mid + 1;
        int ans = 0;
        for(int i = start;i <= mid;i++){
            while(j <= end && 1LL*arr[i] > 1LL*2*arr[j])j++;
            ans += (j - (mid + 1));
        }
        merge(arr, start, mid, end); // Count cross inversions

        return left + right + ans;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size() - 1);    
    }
};