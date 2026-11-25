// Last updated: 11/25/2026, 3:46:42 PM
class Solution {
public:
    struct trieNode {
        struct trieNode* child[26];
        bool endOfWord;

        trieNode() {
            for (int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
            endOfWord = false;
        }
    };

    typedef struct trieNode node;

    node* buildPrefixTrie(node* root, const string& word, int n, int i) {
        if (i == n) {
            root->endOfWord = true;
            return root;
        }
        if(i<n && root->endOfWord == true){
            return root;
        }
        if (root->child[word[i] - 'a'] == nullptr) {
            root->child[word[i] - 'a'] = new node();
        }
        root->child[word[i] - 'a'] = buildPrefixTrie(root->child[word[i] - 'a'], word, n, i + 1);
        return root;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        node* root = new node();
        for (const auto& word : dictionary) {
            buildPrefixTrie(root, word, word.size(), 0);
        }
        stringstream ss(sentence);
        string word;
        string result;
        while (ss >> word) {
            node* p = root;
            int i = 0;
            int n = word.size();
            string temp = "";
            while (i < n) {
                if (p->endOfWord) {
                    result += temp;
                    break;
                }
                if (p->child[word[i] - 'a'] == nullptr) {
                    result += word;
                    break;
                }
                temp += word[i];
                p = p->child[word[i] - 'a'];
                i++;
            }
            if (i == n) { // means we went through the entire word without finding a shorter prefix
                result += word;
            }
            result += " ";
        }
        if (!result.empty()) {
            result.pop_back(); // Remove the last space
        }
        return result;
    }
};
