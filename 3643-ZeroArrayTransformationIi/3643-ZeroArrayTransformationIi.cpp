// Last updated: 11/25/2026, 3:38:14 PM
class Solution {
public:
    vector<int>segTree,lazy;
    void build(int l,int r,int ind,vector<int>&nums){
        if(l == r){
            segTree[ind] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(l , mid,2*ind,nums);
        build(mid + 1,r,2*ind + 1,nums); 
        segTree[ind] = max(segTree[2*ind],segTree[2*ind + 1]);
    }
    void lazyUpdate(int ind,int l,int r){
        if(lazy[ind] != 0){
            segTree[ind] = max(0,segTree[ind] - lazy[ind]);
            if(l != r){
                lazy[2*ind] += lazy[ind];
                lazy[2*ind + 1] += lazy[ind];
            }
            lazy[ind] = 0;
        }
    }
    void RangeUpdate(int l,int r,int ind,int ql,int qr,int val){
        lazyUpdate(ind,l,r);

        if(l > qr || r < ql)return;

        if(segTree[ind] == 0)return;

        if(l >= ql && r <= qr){
            segTree[ind] = max(0,segTree[ind] - val);
            if(l != r){
                lazy[2*ind] += val;
                lazy[2*ind + 1] += val;
            }
            return;
        }
        if(l == r)return;
        int mid = l + (r - l) / 2;
        RangeUpdate(l,mid,2*ind,ql,qr,val);
        RangeUpdate(mid + 1,r,2*ind + 1,ql,qr,val);
        segTree[ind] = max(segTree[2*ind],segTree[2*ind + 1]);
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        segTree.assign(4*n,0);
        lazy.assign(4*n,0);

        build(0,n - 1,1,nums);
        if(segTree[1] == 0)return 0;
        for(int i = 0;i < queries.size();i++){
            RangeUpdate(0,n - 1,1,queries[i][0],queries[i][1],queries[i][2]);
            if(segTree[1] == 0){
                return i + 1;
            }
        }
        return -1;
    }
};



// class Solution {
// public:
//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size() , k = 0 , sum = 0;
//         vector<int>differenceArr(n + 1,0);
//         for(int numInd = 0;numInd < n;numInd++){
//             while(sum + differenceArr[numInd] < nums[numInd]){
//                 if(k == queries.size())return -1;
//                 int startq = queries[k][0] , endq = queries[k][1];
//                 int val = queries[k][2];
//                 if(numInd <= endq){
//                     differenceArr[max(startq,numInd)] += val;
//                     differenceArr[endq + 1] -= val;
//                 }
//                 k++;
//             }
//             sum += differenceArr[numInd];
//         }
//         return k;
//     }
// };


// class Solution {
// public:
//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         int left = 0,right = queries.size();
//         if(!canFormZeroArr(nums,queries,right))return -1;
//         while(left <= right){
//             int mid = left + (right - left) / 2;
//             if(canFormZeroArr(nums,queries,mid)){
//                 right = mid - 1;
//             }else{
//                 left = mid + 1;
//             }
//         }
//         return left;
//     }


//     bool canFormZeroArr(vector<int>&nums,vector<vector<int>>&queries,int k){
//         int n = nums.size() , sum = 0;
//         vector<int>differenceArr(n + 1);
//         for(int qInd = 0;qInd < k;qInd++){
//             int start = queries[qInd][0],end = queries[qInd][1];
//             int val = queries[qInd][2];
//             differenceArr[start] += val;
//             differenceArr[end + 1] -= val;
//         }
//         for(int numI = 0;numI < n;numI++){
//             sum += differenceArr[numI];
//             if(sum < nums[numI]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
