// Last updated: 11/25/2026, 3:42:01 PM
class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int index, int delta) {
        index++;
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>pos2(n) , reversedIndexMapping(n);

        for(int j = 0;j < n;j++){
            pos2[nums2[j]] = j; // maps nums2[j] to j   
        }

        //creating (j , i) pairs where nums2[j] == nums1[i]
        for(int i = 0;i < n;i++){
            reversedIndexMapping[pos2[nums1[i]]] = i; // mapping j to i
        }
        FenwickTree tree(n);

        long long res = 0;

        // j is positions of nums2
        for(int j = 0;j < n;j++){
            //gives i where nums1[i] == nums2[j] => got the index pairs
            int i = reversedIndexMapping[j];

// get the number of valid (pairs (j,i) such that nums2[j] == nums1[i]) indexes in nums1 on left of nums1[i]
    // prefixsum of valid pairs are recorded in BIT in past iterations
            int left = tree.query(i);
            tree.update(i,1); // recording the valid pair (j,i)
            int right = (n - 1 - i) - (j - left);
            res += (long long)left * right;
        }
        return res;
    }
};