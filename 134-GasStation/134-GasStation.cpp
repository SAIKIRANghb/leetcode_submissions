// Last updated: 11/25/2026, 3:48:50 PM
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int start = 0;
        int carTank = 0;
        int totalCapacity = 0;

        int totalGas = 0;
        int totalCost = 0;

        for (int i = 0; i < n ;i++) {
            carTank += (gas[i] - cost[i]);
            totalCapacity = (gas[i] - cost[i]);

            if (carTank < 0) {
               start = i + 1;
               carTank = 0;
            }

            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost) return -1;

        return start;
    }
};