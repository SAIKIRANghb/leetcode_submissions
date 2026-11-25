// Last updated: 11/25/2026, 3:38:19 PM
class Solution {
public:
    bool isBalanced(string num) {
        int Totalsum = 0;
        int oddSum = 0;
        int n = num.size();
        for(int i = 0;i<n;i++){
            if(i % 2 == 1){
                oddSum += (num[i] - '0');
            }
            Totalsum += (num[i] - '0');
        }
        if(oddSum == Totalsum - oddSum)return true;
        return false;
    }
};