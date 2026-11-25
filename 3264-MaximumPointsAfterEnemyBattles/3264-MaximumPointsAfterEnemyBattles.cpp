// Last updated: 11/25/2026, 3:40:07 PM
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long sum = 0;
        int minEnergy = *min_element(enemyEnergies.begin(),enemyEnergies.end());
        if(minEnergy > currentEnergy)return 0;
        for(auto energy : enemyEnergies){
            sum += energy;
        }
        sum -= minEnergy;
        sum += currentEnergy;
        return (sum / minEnergy);
    }
};