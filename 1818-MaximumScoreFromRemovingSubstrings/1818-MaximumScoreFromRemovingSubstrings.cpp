// Last updated: 11/25/2026, 3:43:15 PM
class Solution {
public:
    int CountPoints(string &s,string comp,int points){
        int n = s.size();
        int ans = 0,j=0;
        for(int i = 0;i<n;i++){
            s[j++] = s[i];
            if(j > 1 && s[j - 1] == comp[1] && s[j - 2] == comp[0]){
                j -= 2;
                ans += points;
            }
        }
        s = s.substr(0,j);
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        string s1 = "ab";
        string s2 = "ba";
        if(x < y){
            swap(s1,s2);
            swap(x,y);
        }
        return CountPoints(s,s1,x) + CountPoints(s,s2,y);
    }
};

/*
class Solution {
public:
    int CountPoints(string &s,string comp,int points){
        int n = s.length();
        int j = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            s[j++] = s[i];
            if(j > 1 && s[j - 1] == comp[1] && s[j - 2] == comp[0]){
                j -= 2;
                ans += points;
            }
        }
        s = s.substr(0,j);
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if (x < y) {
            swap(s1, s2);
            swap(x, y);
        }
        
        int points1 = CountPoints(s, s1, x);
        int points2 = CountPoints(s, s2, y);
        return points1 + points2;
    }
};


*/