// Last updated: 11/25/2026, 3:50:29 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int low=0,high=arr.size()-1;
        int lb=-1,ub=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                low=mid+1;
                ub=mid;
            }
            else if(arr[mid]<target){
                low = mid+1;
            }
            else {
                high=mid-1;
            }
        }
        low=0;high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                high=mid-1;
                lb=mid;
            }
            else if(arr[mid]<target){
                low = mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return {lb,ub};
    }
};