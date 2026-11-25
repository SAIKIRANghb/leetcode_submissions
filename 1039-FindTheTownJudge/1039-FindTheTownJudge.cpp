// Last updated: 11/25/2026, 3:45:16 PM
#include <vector>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        std::vector<int> trust_scores(n + 1, 0); // Trust scores for each person

        // Calculate trust scores
        for (const auto& t : trust) {
            // Decrease the trust score of the person who trusts
            trust_scores[t[0]]--;
            // Increase the trust score of the person who is trusted
            trust_scores[t[1]]++;
        }

        // Check for the judge
        for (int i = 1; i <= n; ++i) {
            // The judge trusts nobody (trust score is n - 1)
            // and everybody (except themselves) trust the judge (trust score is n - 1)
            if (trust_scores[i] == n - 1) {
                return i;
            }
        }

        return -1; // No judge found
    }
};
