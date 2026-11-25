// Last updated: 11/25/2026, 3:48:57 PM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endWord)return level;

            for(int i = 0;i < n;i++){
                char temp = word[i];
                for(char ch = 'a';ch <= 'z';ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push({word,level + 1});
                        st.erase(word);
                    }
                }
                word[i] = temp;
            }
        }
        return 0;
    }
};

// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         int n = beginWord.size();
//         unordered_set<string>st(wordList.begin(),wordList.end());
//         queue<pair<string,int>>q;
//         q.push({beginWord,1});
//         st.erase(beginWord);

//         while(!q.empty()){
//             string word = q.front().first;
//             int level = q.front().second;
//             q.pop();
//             if(word == endWord)return level;
//             for(int i = 0;i < n;i++){
//                 char temp = word[i];
//                 for(char ch = 'a';ch <= 'z';ch++){
//                     word[i] = ch;
//                     if(st.count(word)){
//                         q.push({word,level + 1});
//                         st.erase(word);
//                     }
//                 }
//                 word[i] = temp;
//             }
//         }
//         return 0;
//     }
// };