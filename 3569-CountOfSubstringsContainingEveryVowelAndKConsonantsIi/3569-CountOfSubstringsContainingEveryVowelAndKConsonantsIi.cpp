// Last updated: 11/25/2026, 3:38:34 PM
class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e'|| c == 'i'|| c == 'o'|| c == 'u'){
            return true;
        }
        return false;
    }
    long long atLeastK(string word,int k){
        long start = 0 , end = 0 ,validStrings = 0;
        unordered_map<char,long long>vowelCnt;
        long long consCnt = 0;
        while(end < word.size()){
            char newLtr = word[end];
            if(isVowel(newLtr)){
                vowelCnt[newLtr]++;
            }else{
                consCnt++;
            }
            while(consCnt >= k && vowelCnt.size() == 5){
                validStrings += word.size() - end;
                char srt = word[start];
                if(isVowel(srt)){
                    vowelCnt[srt]--;
                    if(vowelCnt[srt] == 0)vowelCnt.erase(srt);
                }else{
                    consCnt--;
                }
                start++;
            }
            end++;
        }
        return validStrings;
    }
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word,k) - atLeastK(word,k + 1);
    }
};

