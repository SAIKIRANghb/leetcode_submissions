// Last updated: 11/25/2026, 3:44:49 PM
class Solution {
public:
    vector<int>dp;
    //TopDown - Dp
    // int helper(int i,int shelfWidth,vector<vector<int>>&books){
    //     int n = books.size();
    //     if(i == n)return 0;

    //     if(dp[i] != -1)return dp[i];
    //     int currWidth = shelfWidth;
    //     int maxHeight = 0;
    //     int ans = INT_MAX;
    //     for(int j = i;j<n;j++){
    //         int width = books[j][0];
    //         int height = books[j][1];

    //         if(currWidth < width)break;
    //         currWidth -= width;
    //         maxHeight = max(maxHeight,height);

    //         ans = min(ans , helper(j + 1,shelfWidth,books) + maxHeight);
    //     }
    //     return dp[i] = ans;
    // }

    //BottomUp - Dp
    // int helper(int i,int shelfWidth,vector<vector<int>>&books){
    //     int n = books.size();

    //     for(int i = n - 1; i>=0 ;i--){
    //     int currWidth = shelfWidth;
    //     int maxHeight = 0;
    //     dp[i] = INT_MAX;
    //     for(int j = i;j<n;j++){
    //         int width = books[j][0];
    //         int height = books[j][1];

    //         if(currWidth < width)break;
    //         currWidth -= width;
    //         maxHeight = max(maxHeight,height);

    //         dp[i] = min(dp[i] , dp[j + 1] + maxHeight);
    //     }
    //     }
    //     return dp[0];
    // }


    
    //TopDown - Dp
    int helper(int i,vector<vector<int>>&books,int shelfWidth){
        int n = books.size();
        if(i == n)return 0;
        if(dp[i] != -1)return dp[i];
        int ans = INT_MAX;
        int maxHeight = 0;
        int currWidth = shelfWidth;
        for(int j = i;j<n;j++){
            int width = books[j][0];
            int height = books[j][1];
            if(currWidth < width){
                break;
            }
            currWidth -= width;
            maxHeight = max(maxHeight,height);
            ans = min(helper(j + 1,books,shelfWidth) + maxHeight,ans);
        }
        return dp[i] = ans;
    }
    int helper(vector<vector<int>>&books,int shelfWidth){
        int n = books.size();
        for(int i = n - 1; i>=0 ;i--){
            int currWidth = shelfWidth;
            int maxHeight = 0;
            int ans = INT_MAX;
            for(int j = i;j<n;j++){
                int height = books[j][1];
                int width = books[j][0];
                if(currWidth < width){
                    break;
                }
                currWidth -= width;
                maxHeight = max(maxHeight,height);
                ans = min(maxHeight + dp[j+1] , ans);
                dp[i] = ans;
            }
        }
        return dp[0];
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // dp = vector<int>(books.size(),-1);
        // return helper(0,books,shelfWidth);
        dp = vector<int>(books.size()+1,0);
        return helper(books,shelfWidth);
    }
};