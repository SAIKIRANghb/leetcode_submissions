// Last updated: 11/25/2026, 3:39:02 PM
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long ans = 0;
        int numOfHorizontalSection = 1, numOfVerticalSection = 1, i = 0,j = 0;
         n = horizontalCut.size(),m = verticalCut.size();
        sort(horizontalCut.rbegin(),horizontalCut.rend());
        sort(verticalCut.rbegin(),verticalCut.rend());

        while(i < n && j < m){
            if(horizontalCut[i] >= verticalCut[j]){
                ans += numOfVerticalSection * horizontalCut[i];
                numOfHorizontalSection++;
                i++;
            }else{
                ans += numOfHorizontalSection * verticalCut[j];
                numOfVerticalSection++;
                j++;
            }
        }

        while(i<n){
            ans += numOfVerticalSection * horizontalCut[i];
            numOfHorizontalSection++;
            i++;
        }
        while(j<m){
            ans += numOfHorizontalSection * verticalCut[j];
            numOfVerticalSection++;
            j++;
        }
        return ans;
    }
};