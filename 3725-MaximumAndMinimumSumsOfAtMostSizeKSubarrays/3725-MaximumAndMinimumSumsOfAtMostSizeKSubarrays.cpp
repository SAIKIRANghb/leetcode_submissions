// Last updated: 11/25/2026, 3:37:56 PM
class Solution {
    public:
        long long minMaxSubarraySum(vector<int>& nums, int K) {
            int n = nums.size();
            long long ans = 0;
            long long k = K;
    {        vector<long long> S;
            vector<long long> l(n, -1);
            vector<long long> r(n, n);
    
            // Calculate the left and right bounds for each element
            for (int i = 0; i < n; i++) {
                while (!S.empty() && nums[S.back()] <= nums[i]) {
                    r[S.back()] = i;  // Update right bound for prevector<long long>ous elements
                    S.pop_back();
                }
                if (!S.empty()) {
                    l[i] = S.back();  // Update left bound for current element
                }
                S.push_back(i);
            }
    
            // Compute the sum of subarrays using the constraints
            for (long long i = 0; i < n; i++) {
                l[i] = max(l[i], i - k);  // Ensure the left bound is within the window
                r[i] = min(r[i], i + k); // Ensure the right bound is within the window
    
                long long ld = i - l[i]; // Distance to the left bound
                long long rd = r[i] - i; // Distance to the right bound
    
                long long mnd = min(ld, rd); // Minimum distance
                long long mxd = max(ld, rd); // Maximum distance
    
                // Add contributions from subarrays where the current element is the minimum
                ans += (mnd * (mnd + 1) / 2) * nums[i];
    
                // Handle overlap with extended ranges
                long long extended = min(mxd + mnd - 1, k);
                ans += (extended - mnd) * mnd * nums[i];
    
                // Subtract overcounted contributions from overly extended ranges
                long long diff = extended - mxd;
                ans -= (diff * (diff + 1) / 2) * nums[i];
            }
    }
            {
                vector<long long> S;
                vector<long long> l(n, -1);
                vector<long long> r(n, n);
                for (int i = 0; i < n; i++)
                {
                    while (!S.empty() && nums[S.back()] >= nums[i])
                    {
                        r[S.back()] = i;
                        S.pop_back();
                    }
                    if (!S.empty())
                    {
                        l[i] = S.back();
                    }
                    S.push_back(i);
                }
                for (long long i = 0; i < n; i++)
                {
                    l[i] = max(l[i], i - k);
                    r[i] = min(r[i], i + k);
                    long long ld = i - l[i];
                    long long rd = r[i] - i;
                    long long mnd = min(ld, rd);
                    long long mxd = max(ld, rd);
                    ans += ((mnd * (mnd + 1)) / 2) * nums[i];
                    ans += (min(k, mnd + mxd - 1) - mnd) * mnd * nums[i];
                    long long diff = min(mxd + mnd - 1, k) - mxd;
                    ans -= ((diff * (diff + 1)) / 2) * nums[i];
                }
            }
            return ans;
        }
    };
    