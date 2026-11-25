// Last updated: 11/25/2026, 3:45:40 PM
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n2 = words2.size();
        vector<int>maxOfW2(26,0);
        for(int i = 0;i<n2;i++){
            vector<int>tempMax(26,0);
            for(char ch : words2[i]){
                tempMax[ch - 'a']++;
            }
            for(int j = 0;j < 26;j++){
                maxOfW2[j] = max(maxOfW2[j],tempMax[j]); 
            }
        }
        int n1 = words1.size();
        vector<string>ans;
        for(int i = 0;i<n1;i++){
            vector<int>tempMax(26,0);
            for(char ch : words1[i]){
                tempMax[ch - 'a']++;
            }
            bool flag = false;
            for(int j = 0;j < 26;j++){
                if(tempMax[j] < maxOfW2[j]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};

