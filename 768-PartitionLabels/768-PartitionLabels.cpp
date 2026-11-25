// Last updated: 11/25/2026, 3:46:23 PM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>fullMp;
        int n = s.size();
        int partitionSize = 1;
        vector<int>ans;
        for(int i = 0;i < n;i++){
            fullMp[s[i]]++;
        }
        int NumUnique = fullMp.size();
        unordered_map<char,int>mp;

        for(int i = 0;i < n;i++){
            mp[s[i]]++;
            fullMp[s[i]]--;
            if(fullMp[s[i]] == 0){
                fullMp.erase(s[i]);
            }
            if(mp.size() + fullMp.size() == NumUnique){
                ans.push_back(partitionSize);
                partitionSize = 0;
            }
            partitionSize++;
        }
        return ans;
    }
};