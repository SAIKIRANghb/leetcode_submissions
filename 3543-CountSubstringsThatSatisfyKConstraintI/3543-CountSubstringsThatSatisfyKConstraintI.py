# Last updated: 11/25/2026, 3:38:41 PM
from collections import Counter

class Solution(object):
    def countKConstraintSubstrings(self, s, k):
        c = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                b = s[i:j+1]
                print(b)
                d = Counter(b)
                if d['0'] <= k or d['1'] <= k:
                    c += 1
        return c
