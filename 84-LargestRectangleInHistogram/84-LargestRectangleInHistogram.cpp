// Last updated: 11/25/2026, 3:49:30 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        
        vector<int> nextSmall(n, n); // Initially set to n for elements that don't have a smaller element to the right
        vector<int> prevSmall(n, -1); // Initially set to -1 for elements that don't have a smaller element to the left
        stack<int> st;

        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                nextSmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty())st.pop();
        int maxArea = INT_MIN;
        for(int i = n-1;i >= 0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                prevSmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0;i<n;i++){
            int H = heights[i];
            int W = nextSmall[i] - prevSmall[i] - 1;
            maxArea = max(maxArea,H*W);
        }
        return maxArea;
    }
};
