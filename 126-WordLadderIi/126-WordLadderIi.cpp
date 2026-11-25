// Last updated: 11/25/2026, 3:48:58 PM
class Solution {
    unordered_map<string,int>mpp;
    vector<vector<string>>ans;
    string b;
private:
    void dfs(string word,vector<string>&seq){
        if(word == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mpp[word];
        int sz = word.size();

        for(int i = 0;i < sz;i++){
            char temp = word[i];
            for(char ch = 'a';ch <= 'z';ch++){
                word[i] = ch;
                if(mpp.count(word) && mpp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back(); 
                }
            }
            word[i] = temp;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);
        int sz = beginWord.size();
        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            for(int i = 0;i < sz;i++){
                char temp = word[i];
                for(char ch = 'a';ch <= 'z';ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = temp;
            }
        }
        if(mpp.count(endWord)){
            vector<string>seq;
            seq.push_back(endWord);
            b = beginWord;
            dfs(endWord,seq);
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         int n = beginWord.size();
//         vector<vector<string>>ans;
//         unordered_set<string>st(wordList.begin(),wordList.end());
//         int level = 0;
//         queue<vector<string>>q;
//         q.push({beginWord});
//         vector<string>toDel;
//         while(!q.empty()){
//             vector<string> subQ = q.front();
//             string word = subQ.back();
//             q.pop();
//             if(subQ.size() > level){
//                 level++;
//                 for(string &wrd : toDel){
//                     st.erase(wrd);
//                 }
//                 toDel.clear();
//             }
//             if(word == endWord){
//                 if(ans.size() == 0 || ans[0].size() == subQ.size()){
//                     ans.push_back(subQ);
//                 }
//             }
//             for(int i = 0;i < n;i++){
//                 char temp = word[i];
//                 for(char ch = 'a';ch <= 'z';ch++){
//                     word[i] = ch;
//                     if(st.count(word)){
//                         subQ.push_back(word);
//                         q.push(subQ);
//                         subQ.pop_back();
//                         toDel.push_back(word);
//                     }
//                 }
//                 word[i] = temp;
//             }
//         }
//         return ans;
//     }
// };
