// Last updated: 11/25/2026, 3:49:58 PM
class Solution {
public:
    vector<vector<int>> comb;
    vector<int> visArr;
    
    void combinationSum(vector<int>& candidates, int target, int i, vector<int>& ans) {
        if (target == 0) {
            comb.push_back(ans);
            return;
        }
        if (target < 0 || i == candidates.size()) {
            return;
        }
        
        for (int j = i; j < candidates.size(); j++) {
            // Skip duplicates at the same level
            if (j > i && candidates[j] == candidates[j - 1]) continue;
            
            ans.push_back(candidates[j]);
            combinationSum(candidates, target - candidates[j], j + 1, ans);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        vector<int> ans;  // Create a local vector to pass by reference
        combinationSum(candidates, target, 0, ans);
        return comb;
    }
};
