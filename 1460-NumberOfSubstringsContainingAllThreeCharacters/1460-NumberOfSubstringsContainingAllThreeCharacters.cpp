// Last updated: 11/25/2026, 3:44:01 PM
class Solution {
public:
    bool validSubArr(vector<int>&freq){
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
    int numberOfSubstrings(string s) {
        vector<int>freq(3,0);
        int n = s.size();
        int total = 0;
        int l = 0 , r = 0;
        while(r < n){
            freq[s[r] - 'a']++;
            while(validSubArr(freq)){
                total += n - r;
                freq[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return total;
    }
};

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int len = s.length();
//         int left = 0, right = 0;
//         // Track frequency of a, b, c
//         vector<int> freq(3, 0);
//         int total = 0;

//         while (right < len) {
//             // Add character at right pointer to frequency array
//             char curr = s[right];
//             freq[curr - 'a']++;

//             // While we have all required characters
//             while (hasAllChars(freq)) {
//                 // All substrings from current window to end are valid
//                 // Add count of these substrings to result
//                 total += len - right;

//                 // Remove leftmost character and move left pointer
//                 char leftChar = s[left];
//                 freq[leftChar - 'a']--;
//                 left++;
//             }

//             right++;
//         }

//         return total;
//     }

// private:
//     bool hasAllChars(vector<int>& freq) {
//         // Check if we have at least one of each character
//         return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
//     }
// };