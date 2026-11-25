// Last updated: 11/25/2026, 3:40:00 PM
    class TrieNode {
        public:
        int count;
        unordered_map<int, TrieNode*> children;

        // Constructor
        TrieNode() {
            count = 0;
        }
    };

class Solution{    

    TrieNode* root;
    public:
    Solution() {
        root = new TrieNode();
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        TrieNode* curr = root;

        for(string word : words){
            int n = word.size();
            curr = root;
            for(int i = 0;i < n;i++){
                int node  = word[i]*128 + word[n - 1 - i];
                if(!curr->children.count(node)){
                    curr->children[node] = new TrieNode();
                }
                curr = curr->children[node];
                ans += curr->count;
            }
            curr->count++;
        }
        return ans;
    }
};
