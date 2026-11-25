// Last updated: 11/25/2026, 3:44:58 PM
class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string>seen;

        sort(tiles.begin(),tiles.end());
        return solve(0,tiles,"",seen) - 1; // -1 for counting the empty string ""
    }
    private:
    int fact(int n){
        if(n <= 1)return 1;
        int res = 1;
        for(int num = 2;num <= n;num++){
            res *= num;
        }
        return res;
    }
    int countPerm(string &seq){
        int charCnt[26] = {0};
        for(char ch : seq){
            charCnt[ch - 'A']++;
        }
        int total = fact(seq.length());
        for(int cnt : charCnt){
            if(cnt > 1){
                total /= fact(cnt);
            }
        }
        return total;
    }
    int solve(int ind,string tiles,string curr,unordered_set<string>&seen){
        if(ind >= tiles.length()){
            if(!seen.count(curr)){
                seen.insert(curr);
                return countPerm(curr);
            }
            return 0;
        }
        return solve(ind + 1,tiles,curr,seen) + solve(ind + 1,tiles,curr + tiles[ind],seen);
    }
};




// class Solution {
// public:
//     int numTilePossibilities(string tiles) {
//         unordered_map<int,int>charCnt;

//         for(char ch : tiles){
//             charCnt[ch - 'A']++;
//         }
//         return solve(charCnt);
//     }
//     private:
//     int solve(unordered_map<int,int>&charCnt){
//         int cnt = 0;
//         for(auto &it : charCnt){
//             if(it.second == 0)continue;
//             cnt++;
//             it.second--;
//             cnt += solve(charCnt);
//             it.second++;
//         }
//         return cnt;
//     }
// };


// class Solution {
// public:
//     int numTilePossibilities(string tiles) {
//         unordered_set<string>st;
//         vector<bool>used(tiles.length(),false);
//         generateSubseq(tiles,"",st,used);
//         return st.size() - 1;   
//     }
//     private:
//     void generateSubseq(string tiles,string curr,unordered_set<string>&st,vector<bool>&used){
//         st.insert(curr);
//         for(int ind = 0;ind < tiles.length();ind++){
//             if(!used[ind]){
//                 used[ind] = true;
//                 generateSubseq(tiles,curr + tiles[ind],st,used);
//                 used[ind] = false;
//             }
//         }
//     }
// };