class Solution {
public:
    string addBinary(string a, string b) {

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";

        char c = '0';
        int i = 0;

        while (i < a.length() && i < b.length()) {

            if (a[i] == '1' && b[i] == '1' && c == '1') {
                ans += '1';
                c = '1';
            }

            else if (a[i] == '1' && b[i] == '1' && c == '0') {
                ans += '0';
                c = '1';
            }

            else if (a[i] == '0' && b[i] == '0' && c == '1') {
                ans += '1';
                c = '0';
            } 
            
            else if (a[i] == '0' && b[i] == '0' && c == '0') {
                ans += '0';
                c = '0';
            }

            else if ((a[i] == '1' || b[i] == '1') && c == '1') {
                ans += '0';
                c = '1';
            }

            else if ((a[i] == '1' || b[i] == '1') && c == '0') {
                ans += '1';
                c = '0';
            }

            i++;
        }

        while (i < a.length()) {

            if (a[i] == '0' && c == '0') {
                ans += '0';
                c = '0';
            }

            else if (a[i] == '0' && c == '1') {
                ans += '1';
                c = '0';
            }

            else if (a[i] == '1' && c == '0') {
                ans += '1';
                c = '0';
            }

            else if (a[i] == '1' && c == '1') {
                ans += '0';
                c = '1';
            }

            i++;
        }

        while (i < b.length()) {

            if (b[i] == '0' && c == '0') {
                ans += '0';
                c = '0';
            }

            else if (b[i] == '0' && c == '1') {
                ans += '1';
                c = '0';
            }

            else if (b[i] == '1' && c == '0') {
                ans += '1';
                c = '0';
            }

            else if (b[i] == '1' && c == '1') {
                ans += '0';
                c = '1';
            }

            i++;
        }

        if (c == '1') {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};