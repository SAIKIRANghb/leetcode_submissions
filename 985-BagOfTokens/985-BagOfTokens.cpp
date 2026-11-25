// Last updated: 11/25/2026, 3:45:29 PM
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int n = tokens.size();
        int i = 0 , j = n - 1;
        int points = 0;

        if(n == 0) return 0;

        while(i < j){
            if (power - tokens[i] >= 0){
                power -= tokens[i];
                points++;
                i++;
            } else {
                power += tokens[j];
                points--;
                if(points < 0) return 0;
                j--;
            }
        }

        if(power - tokens[i] >= 0) {
            points++;
        }

        return points;
    }
};