// Last updated: 11/25/2026, 3:44:28 PM
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string res = "";
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int n = res.size();
            // Check if the last two characters are the same
            if (n >= 2 && res[n-1] == top.second && res[n-2] == top.second) {
                if (pq.empty()) {
                    break;  // No more characters to choose from
                }
                auto secondTop = pq.top();
                pq.pop();
                
                // Add the second most frequent character
                res += secondTop.second;
                secondTop.first--;
                
                // Re-add secondTop to the priority queue if it still has occurrences
                if (secondTop.first > 0) {
                    pq.push(secondTop);
                }
                
                // Re-add the original top element
                pq.push(top);
            } else {
                // Add the most frequent character
                res += top.second;
                top.first--;
                
                // Re-add top to the priority queue if it still has occurrences
                if (top.first > 0) {
                    pq.push(top);
                }
            }
        }
        
        return res;
    }
};
