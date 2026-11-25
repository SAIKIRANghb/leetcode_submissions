// Last updated: 11/25/2026, 3:44:47 PM
// class Solution {
// public:
//     bool parseBoolExpr(string expression) {
//         stack<char>st; 
//         unordered_map<char,bool>mp;
//         mp['f'] = false;
//         mp['t'] = true;

//         int n = expression.size();
//         int i = 0;
//         stack<char>Ops;
//         bool ans;
//         while(i < n){
//             if(expression[i] == ','){
//                 i++;
//                 continue;
//             }
//             if(expression[i] != '&' && expression[i] != '|' && expression[i] != '!'){
//                 if(!st.empty() && st.top()==')'){
//                     ans = mp[st.top()];
//                     st.pop();
//                     while(st.top() != '('){
//                         char top = st.top();
//                         if(Ops.top() == '&'){
//                             ans = ans &&  mp[top];
//                         }else if(Ops.top() == '|'){
//                             ans = ans || mp[top];
//                         }else{
//                             ans = !ans;
//                         }
//                         st.pop();
//                     }
//                     st.pop();
//                     if(!st.empty() && (st.top() == '&' || st.top() == '|' || st.top() == '!')){
//                         st.pop();
//                     }
//                 }else  st.push(expression[i]);
//             }else{
//                 Ops.push(expression[i]);
//             }
//             i++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st; 
        unordered_map<char,bool>mp;
        mp['f'] = false;
        mp['t'] = true;

        int n = expression.size();
        int i = 0;
        stack<char>Ops;
        bool ans = false;
        
        while(i < n){
            if(expression[i] == ','){
                i++;
                continue;
            }
            if(expression[i] == ')'){
                ans = mp[st.top()];
                st.pop();
                while(st.top() != '('){
                    char top = st.top();
                    if(Ops.top() == '&'){
                        ans = ans && mp[top];
                    }else if(Ops.top() == '|'){
                        ans = ans || mp[top];
                    }
                    st.pop();
                }
                st.pop();  // Remove '('
                char op = Ops.top();
                Ops.pop();
                if(op == '!') {
                    ans = !ans;  // Apply NOT after evaluating inner expression
                }
                st.push(ans ? 't' : 'f');
            }
            else if(expression[i] != '&' && expression[i] != '|' && expression[i] != '!'){
                st.push(expression[i]);
            }else{
                Ops.push(expression[i]);
            }
            i++;
        }
        return mp[st.top()];
    }
};