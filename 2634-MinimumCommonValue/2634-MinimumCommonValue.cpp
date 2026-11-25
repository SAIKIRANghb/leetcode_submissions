// Last updated: 11/25/2026, 3:41:10 PM
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n1=nums1.size(),n2=nums2.size();
        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j])return nums1[i];
            if(nums1[i]>nums2[j]){
                j++;
            }
            if(j>=n2)return -1;
            if(nums1[i]<nums2[j]){
                i++;
            }
        }
        return -1;
    }
};