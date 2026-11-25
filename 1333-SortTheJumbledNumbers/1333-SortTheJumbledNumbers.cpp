// Last updated: 11/25/2026, 3:44:23 PM
class Solution {
public:
    void merge(vector<int> &arr,vector<int>&nums, int low, int mid, int high) {
    vector<int>tempNums;    
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            tempNums.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            tempNums.push_back(nums[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        tempNums.push_back(nums[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        tempNums.push_back(nums[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
        nums[i] = tempNums[i - low];
    }
}

void mergeSort(vector<int> &arr,vector<int>&nums, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr,nums, low, mid);  // left half
    mergeSort(arr,nums, mid + 1, high); // right half
    merge(arr,nums, low, mid, high);  // merging sorted halves
}

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int nsz = nums.size();
        vector<int>mapVec(nsz,0);
        for(int i = 0;i<nsz;i++){
            int num = nums[i];
            int mapNum = 0;
            int place = 1;
            if(num == 0){
                mapVec[i] = mapping[num];
                continue;
            }
            while(num != 0){
                mapNum += (mapping[num % 10])*place;
                place *= 10;
                num /= 10; 
            }
            mapVec[i] = mapNum;
        }
        mergeSort(mapVec,nums,0,nsz - 1);
        return nums;
    }
};