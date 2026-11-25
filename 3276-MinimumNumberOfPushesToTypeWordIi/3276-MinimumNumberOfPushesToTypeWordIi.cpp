// Last updated: 11/25/2026, 3:40:05 PM
class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,-1);
        for(char ch : word){
            if(mp[ch - 'a'] == -1){
                mp[ch - 'a'] = 1;
            }
            else mp[ch - 'a']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i = 0;i<26;i++){
            if(mp[i] != -1)pq.push({mp[i],i + 'a'});
        }
        int ans = 0;
        int minNum = 2;
        vector<int>counts(10,0);
        int i = 2;
        while(!pq.empty()){
            if(i == 0 || i == 1){
                i = 2;
            }
            auto top = pq.top();
            pq.pop();
            if(counts[i] <= counts[minNum]){
                minNum = i;
            }
            counts[minNum]++;
            ans += counts[minNum] * top.first;
            i = (i+1) % 10;
        }
        return ans;
    }
};