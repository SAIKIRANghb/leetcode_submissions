// Last updated: 11/25/2026, 3:39:25 PM
class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(auto &ch : s){
            if(ch <= '9' && ch >= '0' && !st.empty()){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

//class Solution {
// public:
//     string clearDigits(string s) {
//         // Iterate while there are digits in the string
//         while (true) {
//             int digitPos = -1;
            
//             // Find the first digit in the string
//             for (int i = 0; i < s.size(); ++i) {
//                 if (isdigit(s[i])) {
//                     digitPos = i;
//                     break;
//                 }
//             }
            
//             // If no digits found, break the loop
//             if (digitPos == -1) {
//                 break;
//             }
            
//             // Find the closest non-digit character to the left of the found digit
//             for (int j = digitPos - 1; j >= 0; --j) {
//                 if (!isdigit(s[j])) {
//                     s.erase(s.begin() + digitPos); // Remove the digit
//                     s.erase(s.begin() + j); // Remove the closest non-digit character
//                     break;
//                 }
//             }
//         }
        
//         return s;
//     }
// };