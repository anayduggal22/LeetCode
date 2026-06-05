class Solution {
public:
    bool checkValidString(string s) {
        // Using Range Instead of checking one-by-one
        int mn = 0;
        int mx = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                mn++;
                mx++;
            } else if (s[i] == ')') {
                mn--;
                mx--;
            }
            // * can be '(', '_', ')' wjich here is [-1,0,1]
            else if (s[i] == '*') {
                mn--; // min of [-1,0,1] is -1
                mx++; // max of [-1,0,1] is 1
            }

            // Here the min will be 0 then
            if (mn < 0) {
                mn = 0;
            }

            // If the max range is negative, then there is no valid parenthesis
            // possible
            if (mx < 0) {
                return false;
            }
        }

        if (mn != 0) {
            return false;
        }
        return true;
    }
};