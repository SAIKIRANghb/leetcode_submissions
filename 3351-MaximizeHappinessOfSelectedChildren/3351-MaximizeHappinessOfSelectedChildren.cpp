// Last updated: 11/25/2026, 3:39:49 PM
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater <>());
        long long sum=0;
        for(int i=0;i<k;i++){
            int val = happiness[i];
            if(val-i > 0){
                sum+=(val-i);
            }
        }
        return sum;
    }
};