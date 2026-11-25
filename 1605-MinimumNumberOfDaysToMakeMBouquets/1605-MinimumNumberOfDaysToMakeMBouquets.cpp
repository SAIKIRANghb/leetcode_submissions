// Last updated: 11/25/2026, 3:43:47 PM
class Solution {
public: 
    bool calcBoq(int k,int m,int days,vector<int>&bloomDay){
        int n = bloomDay.size();
        int numBoqs = 0;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(bloomDay[i] > days){
                cnt = 0;
                continue;
            }
            if(bloomDay[i] <= days){
                cnt++;
            }
            if(cnt == k){
                cnt = 0;
                numBoqs++;
            }
            if(numBoqs >= m)return true;
        }
        
        return false;
    }


    int minDays(vector<int>& bloomsDay, int m, int k) {
        int n = bloomsDay.size();
        if(1LL*m*k > n)return -1;
        int low = bloomsDay[0], high = bloomsDay[0];
        for (int i = 1; i < n; i++) {
            if (bloomsDay[i] < low) low = bloomsDay[i];
            if (bloomsDay[i] > high) high = bloomsDay[i];
        }

        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            bool possible = calcBoq(k,m,mid,bloomsDay);
            if(possible){
                ans = min(ans,mid);
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};