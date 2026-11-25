// Last updated: 11/25/2026, 3:43:06 PM
//Good solution both for string of numbers (can be really big) and string of alphabets | TC : O(log(K)*N^2) works 
//reasonably well for large K
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0;i < n;i++){
            unordered_map<char,int>mp;
            multiset<int> mset;
            for(int j = i;j < n;j++){
                if(mp.find(s[j]) != mp.end()) mset.erase(mset.find(mp[s[j]]));
                mp[s[j]]++;
                mset.insert(mp[s[j]]);
                ans += (*mset.rbegin()-*mset.begin());
            }
        }
        return ans;
    }
};

//works well for smaller ranges string like alphabets (26) | TC : O(26*N^2) ,if numbers => TC : O(K*N^2) ; large K can 
//cause TLE

/*
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j = i;j < n;j++){
                mp[s[j]]++;
                int maxf = INT_MIN,minf = INT_MAX;
                for(auto it : mp){
                    maxf = max(it.second,maxf);
                    minf = min(it.second,minf);
                }
                ans += (maxf - minf);
            }
        }
        return ans;   
    }
};
*/