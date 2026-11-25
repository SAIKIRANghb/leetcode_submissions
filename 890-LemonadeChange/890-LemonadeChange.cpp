// Last updated: 11/25/2026, 3:45:57 PM
class Solution {
public:
    vector<int> diffMap;

    bool tryPossible(vector<int>& map, int target) {
        if (target == 0) {
            for (int i = 0; i < 3; i++) {
                diffMap[i] = map[i];
            }
            return true;
        }
        if (target < 0) return false;

        bool res = false;
        for (int i = 0; i < 3; i++) {
            if (map[i] > 0) {
                map[i]--;
                int newTarget = 0;
                if (i == 2) {
                    newTarget = target - 20;  // for 20-dollar bill
                } else if (i == 1) {
                    newTarget = target - 10;  // for 10-dollar bill
                } else {
                    newTarget = target - 5;   // for 5-dollar bill
                }
                res |= tryPossible(map, newTarget);
                map[i]++;
            }
        }
        return res;
    }

    bool lemonadeChange(vector<int>& bills) {
        vector<int> map(3, 0);
        diffMap = vector<int>(3, 0);
        int n = bills.size();

        for (int i = 0; i < n; i++) {
            if (bills[i] == 20) {
                map[2]++;
            } else if (bills[i] == 10) {
                map[1]++;
            } else {
                map[0]++;
            }

            if (!tryPossible(map, bills[i] - 5)) {
                return false;
            } else {
                for (int j = 0; j < 3; j++) {
                    map[j] = diffMap[j];
                }
            }
        }
        return true;
    }
};
