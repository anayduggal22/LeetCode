class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (st.empty()) {
                    return false;
                } else if (s[i] == ')' && st.top() == '(' ||
                           s[i] == '}' && st.top() == '{' ||
                           s[i] == ']' && st.top() == '[') {
                    st.pop();
                }

                else {
                    return false;
                }
            }
            i++;
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};