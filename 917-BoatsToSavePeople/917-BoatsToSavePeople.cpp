// Last updated: 11/25/2026, 3:45:51 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int n = people.size();
        int cnt = 0;
        int left = 0, right = n - 1;

        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            cnt++;
        }

        return cnt;
    }
};
