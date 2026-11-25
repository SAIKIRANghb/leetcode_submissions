// Last updated: 11/25/2026, 3:43:30 PM
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>Set;
        return solve(0,s,Set);
    }

    private:
    int solve(int i,string &s,unordered_set<string>&Set){
        int n = s.size();
        if(n == i)return 0;
        int ans = 0;
        for(int j = i + 1;j <= n;j++){
            string subStr = s.substr(i,j - i); 
            if(Set.find(subStr) == Set.end()){
                Set.insert(subStr);
                ans = max(1 + solve(j,s,Set) , ans);
                Set.erase(subStr);
            }
        }
        return ans;
    }
};