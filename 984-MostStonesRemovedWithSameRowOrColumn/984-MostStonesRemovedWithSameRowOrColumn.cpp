// Last updated: 11/25/2026, 3:45:31 PM
class Solution {
public:
    int n;
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);  // Path compression
        }
        return parent[i];
    }

    void Union(int i, int j) {
        int Ult_ParI = find(i);
        int Ult_ParJ = find(j);

        if (Ult_ParI != Ult_ParJ) {  // Correct condition
            if (rank[Ult_ParI] > rank[Ult_ParJ]) {
                parent[Ult_ParJ] = Ult_ParI;
            } else if (rank[Ult_ParI] < rank[Ult_ParJ]) {
                parent[Ult_ParI] = Ult_ParJ;
            } else {
                parent[Ult_ParJ] = Ult_ParI;
                rank[Ult_ParI]++;  // Increment rank when both have the same rank
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        parent.resize(n);   
        rank.resize(n, 0);  // Initialize ranks to 0
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    Union(i, j);
                }
            }
        }

        int groups = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i) {  // Find the root parent for comparison
                groups++;
            }
        }

        return n - groups;  // Maximum stones that can be removed
    }
};
