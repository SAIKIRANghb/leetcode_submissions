// Last updated: 11/25/2026, 3:48:52 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// class Solution {
// public:
//     unordered_map<Node*,Node*>mp;
//     void mapNodes(Node* node){
//         if(node == NULL)return;
//         Node* currNew = new Node(node->val);
//         mp[node] = currNew;
//         for(Node *adj : node->neighbors){
//             if(!mp.count(adj)){
//                 mapNodes(adj);
//             }
//         }
//     }

//     Node* cloneGraph(Node* node) {
//         mapNodes(node);
//         for(auto [ori,clo] : mp){
//             for(Node *adj : ori->neighbors){
//                 clo->neighbors.push_back(mp[adj]);
//             }
//         }
//         return mp[node];
//     }
// };

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* ori, Node* clo) {
        if (ori == NULL) return NULL;

        mp[ori] = clo;  // Mark this node as visited
        vector<Node*> Adj;

        for (Node* adj : ori->neighbors) {
            if (mp.count(adj)) {
                Adj.push_back(mp[adj]);  // Already cloned
            } else {
                Node* newNode = new Node(adj->val);
                //below iam just marking as kinda vis but not created adjacents for this 
                //so in line number <x> we have to check for !cloneAdj->neighbors.size() 
                //not !mp.count(oriAdj) because if i have visited that doesnt mean i have populated it.
                mp[adj] = newNode;       // Store clone before recursion
                Adj.push_back(newNode);
            }
        }

        clo->neighbors = Adj;

        int n = ori->neighbors.size();
        for (int i = 0; i < n; ++i) {
            Node* oriAdj = ori->neighbors[i];
            Node* cloAdj = Adj[i];
            if (!cloAdj->neighbors.size()) {  // Avoid reprocessing  -- line <x>
                cloneGraph(oriAdj, cloAdj);
            }
        }

        return clo;
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node* clo = new Node(node->val);
        return cloneGraph(node, clo);
    }
};
