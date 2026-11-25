// Last updated: 11/25/2026, 3:45:53 PM
class Solution {
public:
    long long NoOfHr(int k, vector<int>& piles) {
        int n = piles.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (1LL*piles[i] + k - 1) / k; 
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long numOfHr = NoOfHr(mid, piles);

            if (numOfHr <= h) {
                ans = mid;      
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }

        return ans;
    }
};
