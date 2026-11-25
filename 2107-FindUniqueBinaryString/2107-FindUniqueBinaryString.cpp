// Last updated: 11/25/2026, 3:42:29 PM
class Solution {
public:
    string solve(int n,unordered_set<string>&st,string str){
        if(n == 0){
            if(!st.count(str))return str;
            return "";
        }  
        string take = solve(n - 1,st,str + "0");
        if(take != "")return take;
        string nottake = solve(n - 1,st,str + "1");
        if(nottake != "")return nottake;
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string>st(nums.begin(),nums.end());
        return solve(n,st,"");
    }
};