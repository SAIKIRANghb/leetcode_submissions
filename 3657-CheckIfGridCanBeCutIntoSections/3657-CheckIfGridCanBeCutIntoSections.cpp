// Last updated: 11/25/2026, 3:38:05 PM
class Solution {
    public:
    bool check(int n,vector<vector<int>>&rectangles,int dim){
        int gapCnt = 0;
        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
        });
        // farthest ending coordinate
        int furthestEnd = rectangles[0][dim + 2];

        for(int i = 1;i < rectangles.size();i++){
            vector<int>&rect = rectangles[i];

            if(furthestEnd <= rect[dim]){
                gapCnt++;
            }
            furthestEnd = max(furthestEnd,rect[dim + 2]);
        }
        return gapCnt >= 2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return check(n,rectangles,0) || check(n,rectangles,1);
    }
};
