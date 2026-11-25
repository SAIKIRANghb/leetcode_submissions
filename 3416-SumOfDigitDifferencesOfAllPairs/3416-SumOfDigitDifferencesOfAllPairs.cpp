// Last updated: 11/25/2026, 3:39:39 PM
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    map<int, map<int, int>> mp;

    void count(int el, int k) {
        while (k) {
            mp[k--][el % 10]++;
            el /= 10;
        }
    }

    long long sumDigitDifferences(vector<int>& nums) {
        int k = 0;
        int num = nums[0];
        while (num != 0) {
            k++;
            num /= 10;
        }
        int n = nums.size();
        for (auto el : nums) {
            count(el, k);
        }
        long long ans = 0;
        for (auto it : mp) {
            long long InC = n * 1ll * (n - 1) / 2;
            for (auto jt : it.second) {
                InC -= jt.second * 1ll * (jt.second - 1) / 2;
            }
            ans += InC;
        }
        return ans;
    }
};
