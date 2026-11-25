// Last updated: 11/25/2026, 3:43:24 PM
class Solution {
public:

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        priority_queue<vector<int>> pq;

        int n = nums.size();
        vector<int> ans(n);  // Corrected: initialize ans with size n

        // Step 1: Count frequencies of each number using unordered_map
        for (int num : nums) {
            mp[num]++;
        }

        // Step 2: Push frequencies along with num and index into priority_queue
        for (int i = 0; i < n; i++) {
            if(mp.find(nums[i]) != mp.end()){
                pq.push({ -mp[nums[i]], nums[i], i });
                mp.erase(nums[i]);
            }
        }

        // Step 3: Build the result array using the priority_queue
        int j = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int freq = -top[0];
            int num = top[1];
            int index = top[2];

            // Populate ans with the correct number based on its frequency
            for (int i = 0; i < freq; i++) {
                ans[j] = num;  // Corrected: update ans[j++] with num
                j++;
            }
        }

        return ans;
    }
};
