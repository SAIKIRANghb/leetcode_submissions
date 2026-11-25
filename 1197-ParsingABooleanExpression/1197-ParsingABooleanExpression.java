// Last updated: 11/25/2026, 3:44:55 PM
class Solution {
    public static char solve(List<Character> values, char op) {
        if (op == '!') {
            return values.get(0) == 't' ? 'f' : 't';
        }

        boolean res = true;
        if (op == '&') {
            for (int i = 0; i < values.size(); i++) {
                char c = values.get(i);
                if (c == 'f') {
                    return 'f';
                }
            }
            res = true;
        } else {
            for (int i = 0; i < values.size(); i++) {
                char c = values.get(i);
                if (c == 't') {
                    return 't';
                }
            }
            res = false;
        }

        return res ? 't' : 'f';
    }

    public boolean parseBoolExpr(String expression) {
        Stack<Character> st = new Stack<>();
        boolean res = true;
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == ',') {
                continue;
            } else if (c == ')') {
                List<Character> values = new ArrayList<>();
                while (st.peek() != '(') {
                    values.add(st.pop());
                }
                st.pop();
                st.push(solve(values, st.pop()));
            } else {
                st.push(c);
            }
        }
        return st.peek() == 't';
    }
}