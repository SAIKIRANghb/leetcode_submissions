// Last updated: 11/25/2026, 3:46:20 PM
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk = 0;
        int n = arr.size();
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i] > max){
                max = arr[i];
            }
            if(max == i){
                chunk++;
            }
        }
        if(chunk == 0)return 1;

        return chunk;
    }
};