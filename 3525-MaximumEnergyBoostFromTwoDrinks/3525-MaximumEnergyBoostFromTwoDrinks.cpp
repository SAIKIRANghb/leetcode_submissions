// Last updated: 11/25/2026, 3:38:46 PM
class Solution {
public:
    vector<long long> dpA, dpB;

    long long helperA(int ind, vector<int>& eA, vector<int>& eB) {
        int n = eA.size();
        if (ind >= n) return 0;  // Base case: no energy gain beyond n hours
        if (dpA[ind] != -1) return dpA[ind];  // Return cached result

        // Continue with drink A or switch to drink B with a one-hour penalty
        long long energy = max(eA[ind] + helperA(ind + 1, eA, eB),
                               (ind + 1 < n ? eA[ind] + helperB(ind + 2, eA, eB) : eA[ind]));

        return dpA[ind] = energy;
    }

    long long helperB(int ind, vector<int>& eA, vector<int>& eB) {
        int n = eA.size();
        if (ind >= n) return 0;  // Base case: no energy gain beyond n hours
        if (dpB[ind] != -1) return dpB[ind];  // Return cached result

        // Continue with drink B or switch to drink A with a one-hour penalty
        long long energy = max(eB[ind] + helperB(ind + 1, eA, eB),
                               (ind + 1 < n ? eB[ind] + helperA(ind + 2, eA, eB) : eB[ind]));

        return dpB[ind] = energy;
    }

    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        dpA = vector<long long>(n, -1);
        dpB = vector<long long>(n, -1);

        // Start with either drink A or drink B
        long long ch1 = helperA(0, energyDrinkA, energyDrinkB);
        long long ch2 = helperB(0, energyDrinkA, energyDrinkB);

        return max(ch1, ch2);
    }
};
