// Last updated: 11/25/2026, 3:45:43 PM
class Solution {
public:
    void merge(int low,int mid,int high,vector<int>&nums){
        vector<int>temp;
        int l = low,r = mid + 1;
        while(l <= mid && r <= high){
            if(nums[l] <= nums[r]){
                temp.push_back(nums[l]);
                l++;
            }else{
                temp.push_back(nums[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(nums[r]);
            r++;
        }
        for(int i = low;i<=high;i++){
            nums[i] = temp[i - low];
        }
    }
    void mergeSort(int low,int high,vector<int>&nums){
        if(low >= high)return;
        int mid = (low+high)/2;
        mergeSort(low,mid,nums);
        mergeSort(mid+1,high,nums);
        merge(low,mid,high,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};