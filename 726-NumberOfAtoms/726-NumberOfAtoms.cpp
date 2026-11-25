// Last updated: 11/25/2026, 3:46:29 PM
class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<int> st;
        vector<int> mulNum(n, 1);
        int mul = 1;
        for (int i = n - 1; i >= 0; i--) {
            char ch = formula[i];
            if (ch == ')') {
                string numStr;
                for (int j = i + 1; j < n; j++) {
                    ch = formula[j];
                    if (!isdigit(ch))
                        break;
                    numStr += ch;
                }
                int num = 1; // Default to 1 if numStr is empty
                if (!numStr.empty()) {
                    try {
                        num = stoi(numStr);
                    } catch (const std::invalid_argument& e) {
                    }
                }

                mul *= num;
                st.push(num);
            } else if (ch == '(') {
                int top = st.top();
                st.pop();
                mul /= top;
            }
            mulNum[i] = mul;
        }
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            char ch = formula[i];
            if (isupper(ch)) {
                int mul = mulNum[i];
                string el = "";
                el += ch;
                int j;
                for (j = i + 1; j < n; j++) {
                    ch = formula[j];
                    if (!islower(ch))
                        break;
                    el += ch;
                }
                string sdigit = "";
                int k;
                for (k = j; k < n; k++) {
                    ch = formula[k];
                    if (!isdigit(ch))
                        break;
                    sdigit += ch;
                }
                if (sdigit == "")
                    sdigit = "1";
                int digit = stoi(sdigit);
                mp[el] += mul * digit;
                i = k - 1;
            }
        }
        string ans = "";
        for (auto [el, freq] : mp) {
            string sdigit = to_string(freq);
            if (sdigit == "1")
                sdigit = "";
            ans += (el + sdigit);
        }
        return ans;
    }
};
