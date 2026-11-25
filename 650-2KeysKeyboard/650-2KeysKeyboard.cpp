// Last updated: 11/25/2026, 3:46:40 PM
class Solution {
public:
    int countSteps(int Asize,int copy,int n,int cost){
        if(Asize > n){
            return INT_MAX;
        }
        if(Asize == n){
            return cost;
        }
        int ans = INT_MAX;
        ans = min({countSteps(Asize + copy,copy,n,cost + 1),countSteps(Asize + Asize,Asize,n,cost + 2),ans});
        return ans;
    }
    int minSteps(int n) {
        if(n == 1)return 0;
        return countSteps(2,1,n,2);
    }
};