// Last updated: 11/25/2026, 3:45:25 PM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int ind=n-1;
        vector<int> res(n);
        while(i<=j){
            int ai = nums[i]*nums[i];
            int aj= nums[j]*nums[j];
            if(ai > aj){
                res[ind]=ai;
                i++;
            }
            else{
                res[ind]=aj;
                j--;
            }
            ind--;
        }
        return res;
    }
};