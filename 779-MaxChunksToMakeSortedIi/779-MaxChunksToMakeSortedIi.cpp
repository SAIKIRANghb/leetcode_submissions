// Last updated: 11/25/2026, 3:46:22 PM
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int leftMax[n];
        int rightMin[n];
        // int Lmax=arr[0],Rmin=arr[n-1];
        int chunks=1;
        leftMax[0] = arr[0];
        rightMin[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],arr[i]);
            // if(Lmax < arr[i]){
            //     Lmax = arr[i];
            //     leftMax[i] = Lmax;
            // }
            //     leftMax[i] = Lmax;
        }
        for(int i=n-2;i>=0;i--){
            rightMin[i] = min(rightMin[i+1],arr[i]); 
            // if(Rmin > arr[i]){
            //     Rmin = arr[i];
            //     rightMin[i] = Rmin;
            // }
            //     rightMin[i] = Rmin;
        }
        for(int i=0;i<n-1;i++){
            if(leftMax[i] <= rightMin[i+1]){
                chunks++;
            }
        }
        return chunks;
    }
};