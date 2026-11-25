// Last updated: 11/25/2026, 3:43:29 PM
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        int n = logs.size();
        for(int i = 0;i<n;i++){
            if(logs[i].compare("../") == 0){
                if(count != 0)count-=1;
            }
            else if(logs[i].compare("./") == 0){
                count += 0;
            }else {
                count += 1;
            }
        }
        return count;
    }
};