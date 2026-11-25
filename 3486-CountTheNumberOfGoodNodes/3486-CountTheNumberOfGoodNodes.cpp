// Last updated: 11/25/2026, 3:39:06 PM
// class Solution {
// public:
//     vector<int>vis;
//     int count = 0;
//     int dfs(vector<vector<int>>Tree, int node){
//         int m = Tree[node].size();
//         if(m == 0){
//             count++;
//             return 1;
//         }
//         int maxH = dfs(Tree,Tree[node][0]);
//         int flag = 0;
//         for(int i = 1;i<m;i++){
//             int h = dfs(Tree,Tree[node][i]);
//             if(h != maxH){
//                 flag = 1;
//             }
//             maxH = max(maxH,h);
//         }
//         if(flag){
//             count++;
//         }
//         return maxH + 1;
//     }
    
//     int countGoodNodes(vector<vector<int>>& edges) {
//         int n = edges.size() + 1;
//         vector<vector<int>>Tree(n);
//         vis = vector<int>(n,0);
//         for(int i = 0;i < n - 1;i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             Tree[u].push_back(v);
//         }
//         dfs(Tree,0);
//         return count;
//     }
// };
class Solution {
public:
    int goodNodeCount = 0;   // To store the count of good nodes

    // DFS function to compute subtree sizes and count good nodes
    int dfs(const vector<vector<int>>& Tree, int node, int parent) {
        int size = 1; // Start with size 1 for the current node
        int expectedSize = -1; // To keep track of the expected subtree size for good nodes
        bool allChildrenSameSize = true;

        // Traverse all children
        for (int child : Tree[node]) {
            if (child == parent) continue; // Skip the parent node
            int childSize = dfs(Tree, child, node);
            if (expectedSize == -1) {
                expectedSize = childSize; // Set the expected size to the size of the first child
            } else if (childSize != expectedSize) {
                allChildrenSameSize = false; // If any child size does not match, set flag to false
            }
            size += childSize;
        }
        
        // Check if all children have the same subtree size
        if (allChildrenSameSize) {
            goodNodeCount++;
        }
        
        return size;
    }
    
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> Tree(n);

        // Build the tree from the edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            Tree[u].push_back(v);
            Tree[v].push_back(u);
        }
        
        dfs(Tree, 0, -1); // Start DFS from the root node (0) with no parent (-1)
        return goodNodeCount;
    }
};
