// Last updated: 11/25/2026, 3:45:13 PM

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> Ch_map(26, 0);  // Initialize to max value to ensure correct min operation
        vector<string> ans;

        // Initialize Ch_map with the frequency of each character in the first word
        for (char letter : words[0]) {
            Ch_map[letter - 'a']++;
        }

        // Iterate over the remaining words to find the common minimum frequency of each character
        for (int i = 1; i < words.size(); i++) {
            vector<int> Comp_map(26, 0);
            for (char letter : words[i]) {
                Comp_map[letter - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                Ch_map[j] = min(Ch_map[j], Comp_map[j]);
            }
        }

        // Construct the result based on the frequencies in Ch_map
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < Ch_map[i]; j++) {
                ans.push_back(string(1, i + 'a'));
            }
        }

        return ans;
    }
};
