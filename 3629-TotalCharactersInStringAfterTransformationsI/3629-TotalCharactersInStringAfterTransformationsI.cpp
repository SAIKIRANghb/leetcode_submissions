// Last updated: 11/25/2026, 3:38:23 PM

// class Solution {
// public:
//     int lengthAfterTransformations(string s, int t) {
//         vector<int> cnt(26);
//         for (char ch : s) {
//             ++cnt[ch - 'a'];
//         }
//         for (int round = 0; round < t; ++round) {
//             vector<int> nxt(26);
//             nxt[0] = cnt[25];
//             nxt[1] = (cnt[25] + cnt[0]) % mod;
//             for (int i = 2; i < 26; ++i) {
//                 nxt[i] = cnt[i - 1];
//             }
//             cnt = move(nxt);
//         }
//         int ans = 0;
//         for (int i = 0; i < 26; ++i) {
//             ans = (ans + cnt[i]) % mod;
//         }
//         return ans;
//     }

// private:
//     static constexpr int mod = 1000000007;
// };
// class Solution {
// public:
//     int lengthAfterTransformations(string s, int t) {
//         const int MOD = 1e9 + 7;

//         queue<char> q;
//         for (char ch : s) {
//             q.push(ch);
//         }

//         // Perform t transformations
//         while (t--) {
//             int sz = q.size(); // Only process current length
//             for (int i = 0; i < sz; ++i) {
//                 char ch = q.front();
//                 q.pop();
//                 if (ch == 'z') {
//                     q.push('a');
//                     q.push('b');
//                 } else {
//                     q.push(ch + 1);
//                 }
//             }
//         }

//         return q.size() % MOD;
//     }
// };

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        while (t--) {
            vector<long long> newFreq(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (i == 25) { // 'z'
                    newFreq[0] = (newFreq[0] + freq[25]) % MOD;
                    newFreq[1] = (newFreq[1] + freq[25]) % MOD;
                } else {
                    newFreq[i + 1] = (newFreq[i + 1] + freq[i]) % MOD;
                }
            }
            freq = newFreq;
        }

        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + freq[i]) % MOD;
        }
        return result;
    }
};
