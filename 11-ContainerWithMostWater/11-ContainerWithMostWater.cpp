// Last updated: 11/25/2026, 3:50:19 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int ans = INT_MIN;
        while(i <= j){
            if(height[i] <= height[j]){
                ans = max((j - i)*height[i],ans);
                i++;
            }else{
                ans = max((j - i)*height[j],ans);
                j--;
            }
        }
        return ans;
    }
};