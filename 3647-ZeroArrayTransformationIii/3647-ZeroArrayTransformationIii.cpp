// Last updated: 11/25/2026, 3:38:09 PM
class Solution {
private:
    vector<int> seg;
    vector<int> lseg;
public:
    void buildTree(int index, int low, int high, vector<int>& nums){
        if(low==high){
            seg[index] = nums[low];
            return;
        }
        int mid = (low+high)/2;
        buildTree(2*index+1, low, mid, nums);
        buildTree(2*index+2, mid+1, high, nums);
        seg[index] = max(seg[2*index+1], seg[2*index+2]);
    }
    void lazyupdate(int index, int low, int high){
        if(lseg[index]!=0){
            seg[index] -= lseg[index];
            if(low!=high){
                lseg[2*index+1] += lseg[index];
                lseg[2*index+2] += lseg[index];
            }
            lseg[index]=0;
        }
    }
    void update(int index, int low, int high, int ll, int hh){
        lazyupdate(index, low, high);
        if(ll>high || hh<low) return;
        if(low==high){
            seg[index] = seg[index]-1;
            return;
        }
        if(low>=ll && high<=hh){
            seg[index]-=1;
            lseg[2*index+1]+=1;
            lseg[2*index+2]+=1;
            return;
        }
        int mid = (low+high)/2;
        update(2*index+1, low, mid, ll, hh);
        update(2*index+2, mid+1, high, ll, hh);
        seg[index] = max(seg[2*index+1], seg[2*index+2]);
        return;
    }
    int val(int index, int low, int high, int idx){
        lazyupdate(index, low, high);
        if(idx<low || idx>high) return INT_MAX;
        if(low==high && low==idx){
            return seg[index];
        }
        int mid = (low+high)/2;
        int left = val(2*index+1, low, mid, idx);
        int right = val(2*index+2, mid+1, high, idx);
        return right==INT_MAX ? left : right;
    }
    int numVal(int idx, int n){
        return val(0, 0, n-1, idx);
    }
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        seg = vector<int>(4*n + 1, 0);
        lseg = vector<int>(4*n + 1, 0);
        buildTree(0, 0, n-1, nums);
        sort(q.begin(), q.end());
        priority_queue<int> pq;
        int count = q.size();
        int index = 0;
        int qi = 0;
        cout<<"qsize"<<q.size()<<endl;
        while(index<nums.size()){
            while(qi<q.size() && q[qi][0]<=index){
                pq.push(q[qi][1]);
                qi++;
            }
            while(numVal(index, n)>0){
                if(pq.empty()) return -1;
                int r = pq.top(); pq.pop();
                if(r<index){
                    continue;
                }
                update(0, 0, n-1, index, r);
                // for(int i=0; i<n; i++){
                //     cout<<numVal(i, n)<<" ";
                // }
                // cout<<endl;
                count--;
            }
            index++;
        }
        return count;
    }
};