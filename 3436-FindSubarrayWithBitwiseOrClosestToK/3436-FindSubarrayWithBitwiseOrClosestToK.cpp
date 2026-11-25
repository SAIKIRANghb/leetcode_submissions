// Last updated: 11/25/2026, 3:39:29 PM
// #include <vector>
// using namespace std;

// class SegTree {
// public:
//     int len;
//     vector<int> t;
//     vector<bool> isLazy;   // Array to track lazy updates
//     vector<int> unpropUpd; // Array to store pending updates

//     SegTree(){}
//     SegTree(int l){
//         len = l;
//         t.resize(4 * len);
//         isLazy.assign(4 * len, false);
//         unpropUpd.resize(4 * len);
//     }

//     void build(vector<int>& a, int v, int tl, int tr){
//         if(tl == tr){
//             t[v] = a[tl];
//             return;
//         }
//         int tm = (tl + tr) / 2;
//         build(a, 2 * v, tl, tm);
//         build(a, 2 * v + 1, tm + 1, tr);
//         t[v] = t[2 * v] + t[2 * v + 1];
//     }

//     void pushDown(int v, int tl, int tr){
//         if(!isLazy[v]) return;
//         isLazy[v] = false;
//         int tm = (tl + tr) / 2;
//         apply(2 * v, tl, tm, unpropUpd[v]);
//         apply(2 * v + 1, tm + 1, tr, unpropUpd[v]);
//         unpropUpd[v] = 0;
//     }

//     void apply(int v, int tl, int tr, int val){
//         if(tl != tr){
//             isLazy[v] = true;
//             unpropUpd[v] += val;
//         }
//         t[v] += (tr - tl + 1) * val;
//     }

//     int query(int v, int tl, int tr, int l, int r){
//         if(tl > r || tr < l) return 0;
//         if(l <= tl && tr <= r){
//             return t[v];
//         }
//         pushDown(v, tl, tr);
//         int tm = (tl + tr) / 2;
//         int left = query(2 * v, tl, tm, l, r);
//         int right = query(2 * v + 1, tm + 1, tr, l, r);
//         return left + right;
//     }

//     void update(int v, int tl, int tr, int l, int r, int val){
//         if(tl > r || tr < l) return;
//         if(l <= tl && tr <= r){
//             apply(v, tl, tr, val);
//             return;
//         }
//         pushDown(v, tl, tr);
//         int tm = (tl + tr) / 2;
//         update(2 * v, tl, tm, l, r, val);
//         update(2 * v + 1, tm + 1, tr, l, r, val);
//         t[v] = t[2 * v] + t[2 * v + 1];
//     }

//     void build(vector<int>& a){
//         build(a, 1, 0, len - 1);
//     }

//     int query(int l, int r){
//         return query(1, 0, len - 1, l, r);
//     }

//     void update(int id, int val){
//         update(1, 0, len - 1, id, id, val);
//     }
// };

// class Solution {
// public:
//     int minimumDifference(vector<int>& nums, int k) {
//         int n = nums.size();
//         SegTree st = SegTree(n);
//         st.build(nums);
//         int low = 0, high = n - 1;
//         int reqVal;
//         while(low <= high){
//             int mid = (low + high) / 2;
//             int val = st.query(low, high);
//             if(val <= k){
//                 high = mid - 1;
//                 reqVal = val;
//             }
//             else {
//                 low = mid + 1;
//             }
//         }
//         return abs(k - reqVal);
//     }
// };


#include <vector>
#include <climits>
using namespace std;

class SegTree {
public:
    int len;
    vector<int> t;
    vector<int> lazy;  // Array to track lazy updates

    SegTree(){}
    SegTree(int l){
        len = l;
        t.resize(4 * len);
        lazy.resize(4 * len);
    }

    void build(vector<int>& a, int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = t[2 * v] | t[2 * v + 1];
        }
    }

    void pushDown(int v, int tl, int tr){
        if(lazy[v] != 0){
            t[v] |= lazy[v];
            if(tl != tr){
                lazy[2 * v] |= lazy[v];
                lazy[2 * v + 1] |= lazy[v];
            }
            lazy[v] = 0;
        }
    }

    int query(int v, int tl, int tr, int l, int r){
        if(l > r) 
            return 0;
        pushDown(v, tl, tr);
        if(l == tl && r == tr) 
            return t[v];
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, min(r, tm)) |
               query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int l, int r, int val){
        pushDown(v, tl, tr);
        if(l > r) 
            return;
        if(l == tl && r == tr){
            t[v] |= val;
            if(tl != tr){
                lazy[2 * v] |= val;
                lazy[2 * v + 1] |= val;
            }
        } else {
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), val);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
            t[v] = t[2 * v] | t[2 * v + 1];
        }
    }

    void build(vector<int>& a){
        build(a, 1, 0, len - 1);
    }

    int query(int l, int r){
        return query(1, 0, len - 1, l, r);
    }

    void update(int id, int val){
        update(1, 0, len - 1, id, id, val);
    }
};
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        SegTree st = SegTree(n);

        // Build the segment tree with the initial array
        st.build(nums);

        int minDiff = INT_MAX;

        // Iterate over each starting index i of the subarray
        for (int i = 0; i < n; ++i) {
            // Case 1: Check single element subarray
            minDiff = min(minDiff, abs(nums[i] - k));

            // Case 2: Check subarrays starting from i
            int low = i, high = n - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                int val = st.query(i, mid);
                minDiff = min(minDiff, abs(val - k));
                if (val > k) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return minDiff;
    }
};

