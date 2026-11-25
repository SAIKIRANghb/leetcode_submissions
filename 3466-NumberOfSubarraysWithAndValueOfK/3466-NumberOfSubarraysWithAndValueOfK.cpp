// Last updated: 11/25/2026, 3:39:13 PM
// class SegTree {
// public:
//     int len;
//     vector<int> t;
//     int k;
//     vector<int> lazy;  // Array to track lazy updates

//     SegTree(){}
//     SegTree(int l,int K){
//         len = l;
//         k = K;
//         t.resize(4 * len);
//         lazy.resize(4 * len);
//     }

//     void build(vector<int>& a, int v, int tl, int tr,int &count){
//         if(tl == tr){
//             t[v] = a[tl];
//             if(t[v] == k)count++;
//         } else {
//             int tm = (tl + tr) / 2;
//             build(a, 2 * v, tl, tm,count);
//             build(a, 2 * v + 1, tm + 1, tr,count);
//             t[v] = t[2 * v] & t[2 * v + 1];
//             if(t[v] == k){
//                 count++;
//             }
//         }
//     }

//     void pushDown(int v, int tl, int tr){
//         if(lazy[v] != 0){
//             t[v] |= lazy[v];
//             if(tl != tr){
//                 lazy[2 * v] |= lazy[v];
//                 lazy[2 * v + 1] |= lazy[v];
//             }
//             lazy[v] = 0;
//         }
//     }

//     int query(int v, int tl, int tr, int l, int r){
//         if(l > r) 
//             return 0;
//         pushDown(v, tl, tr);
//         if(l == tl && r == tr) 
//             return t[v];
//         int tm = (tl + tr) / 2;
//         return query(2 * v, tl, tm, l, min(r, tm)) &
//                query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
//     }


//     void build(vector<int>& a,int &count){
//         build(a, 1, 0, len - 1,count);
//     }

//     int query(int l, int r){
//         return query(1, 0, len - 1, l, r);
//     }

// };
// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         SegTree st = SegTree(n,k);
//         int count = 0;
//         // Build the segment tree with the initial array
//         st.build(nums,count);  
//         return count; 
//     }
// };


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>prevAndCount;
        long long ans = 0;
        for(int i = 0;i<n;i++){
            map<int,int>curAndCount;
            for(auto [andVal,cnt] : prevAndCount){
                curAndCount[andVal & nums[i]] += cnt;
            }
            curAndCount[nums[i]]++;

            for(auto [andVal,cnt] : curAndCount){
                if(andVal == k){
                    ans += cnt;
                }
            }
            prevAndCount = curAndCount;
        }
        return ans;
    }
};
