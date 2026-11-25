// Last updated: 11/25/2026, 3:39:46 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumEnergy(std::vector<int>& energy, int k) {
        int n = energy.size();
        int maxEnergy = INT_MIN;
        
        // Check each possible starting point
        for (int start = n-1; start >= n-k; start--) {
            int currentEnergy = 0;
            int i = start;
            
            // Simulate the journey starting from 'start' with jumps of size 'k'
            while (i >= 0) {
                currentEnergy += energy[i];
                // Move to the next magician using the jump size 'k'
                            maxEnergy = std::max(maxEnergy, currentEnergy);
                i -= k;
            }
            
            // Update the maximum energy gained from any starting point
        }
        
        return maxEnergy;
    }
};
