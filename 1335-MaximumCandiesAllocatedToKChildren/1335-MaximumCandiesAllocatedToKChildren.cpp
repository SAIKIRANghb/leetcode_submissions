// Last updated: 11/25/2026, 3:44:22 PM
class Solution {
public:
    bool canAllocate(vector<int>& candies, long long k, long long candyPerChild){
        int n = candies.size();
        long long allocated = 0;
        for(int i = 0; i < n; i++) {
            allocated += candies[i] / candyPerChild; 
            if(allocated >= k)return true;
        }
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {        
        long long l = 1, r = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        long long ans = 0;
        
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (canAllocate(candies, k, mid)) {
                ans = mid;  
                l = mid + 1;  
            } else {
                r = mid - 1;  
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int maximumCandies(vector<int>& candies, long long k) {
//         // Find the maximum number of candies in any pile
//         int maxCandiesInPile = 0;
//         for (int i = 0; i < candies.size(); i++) {
//             maxCandiesInPile = max(maxCandiesInPile, candies[i]);
//         }

//         // Set the initial search range for binary search
//         int left = 0;
//         int right = maxCandiesInPile;

//         // Binary search to find the maximum number of candies each child can
//         // get
//         while (left < right) {
//             // Calculate the middle value of the current range
//             int middle = (left + right + 1) / 2;

//             // Check if it's possible to allocate candies so that each child
//             // gets 'middle' candies
//             if (canAllocateCandies(candies, k, middle)) {
//                 // If possible, move to the upper half to search for a larger
//                 // number
//                 left = middle;
//             } else {
//                 // Otherwise, move to the lower half
//                 right = middle - 1;
//             }
//         }

//         return left;
//     }

// private:
//     bool canAllocateCandies(vector<int>& candies, long long k,
//                             int numOfCandies) {
//         // Initialize the total number of children that can be served
//         long long int maxNumOfChildren = 0;

//         for (int pileIndex = 0; pileIndex < candies.size(); pileIndex++) {
//             maxNumOfChildren +=
//                 candies[pileIndex] /
//                 numOfCandies;  // Add the number of children this pile can serve
//         }

//         return maxNumOfChildren >= k;
//     }
// };