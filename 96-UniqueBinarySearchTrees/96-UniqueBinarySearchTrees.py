# Last updated: 11/25/2026, 3:49:21 PM
class Solution:
    def numTrees(self, n: int) -> int:
        # G(n) = F(1,n) + F(2, n) + ....F(n,n)
        # F(1, n) => number of unique B.S.T with root 1
        # F(i, n) = G(i - 1) * G(n - i) => starting number on right (n - i)
        # => G(n) = G(0) * G(n -1) + G(1) * G(n - 2) + ... + G(n - 1) * G(0)
        # base case if forming unique B.S.T using seq of len 1 and 0 is 1 => G(1) = 1, G(0) = 1

        G: list[int] = [0] * (n + 1)

        G[0], G[1]= 1, 1

        # n + 1 (excluded n + 1) to account for edge case
        for i in range(2,n + 1):
            for j in range(1, i + 1):
                # for all i's i < j (i is the sub-problem's n and j is recursive variable)
                G[i] = G[i] + G[j - 1] * G[i - j]

        return G[n]
