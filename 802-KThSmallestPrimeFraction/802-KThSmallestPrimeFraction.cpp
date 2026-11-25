// Last updated: 11/25/2026, 3:46:13 PM
//Binary search
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        
        double low = 0.0, high = 1.0;
        vector<int> ans(2, 0);
        
        while (low < high) {
            double mid = low + (high - low) / 2.0;
            vector<int> tmpAns(2, 0);
            int count = leCount(arr, mid, tmpAns);
            
            if (count == k) {
                ans = tmpAns;
                break;
            } else if (count < k) {
                low = mid; 
            } else {
                high = mid; 
            }
        }
        
        return ans;
    }
    
    int leCount(vector<int>& arr, double mid, vector<int>& ans) {
        int n = arr.size();
        int count = 0;
        
        double maxFraction = 0.0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] * 1.0 / arr[j] <= mid) {
                    double fraction = arr[i] * 1.0 / arr[j];
                    if (fraction >= maxFraction) {
                        maxFraction = fraction;
                        ans[0] = arr[i];
                        ans[1] = arr[j];
                    }
                    count++;
                }
            }
        }
        
        return count;
    }
};

//minHeap
// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         priority_queue<pair<double, pair<int, int>>> pq;
//         int n = arr.size();
        
//         // Initialize the priority queue with the first column of fractions
//         for (int i = 0; i < n - 1; ++i) {
//             pq.push({ -(double)arr[i] / arr[n - 1], {i, n - 1} });
//         }
        
//         // Process k-1 smallest fractions
//         for (int t = 1; t <= k - 1; ++t) {
//             auto top = pq.top();
//             pq.pop();
//             int i = top.second.first;
//             int j = top.second.second;
            
//             // Push the next smaller fraction from the same row
//             if (j - 1 > i) {
//                 pq.push({ -(double)arr[i] / arr[j - 1], {i, j - 1} });
//             }
//         }
        
//         // Now the top of the priority queue should be the k-th smallest fraction
//         auto top = pq.top();
//         return { arr[top.second.first], arr[top.second.second] };
//     }
// };
