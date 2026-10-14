class Solution {
public:
    void longestprefixsuffix(vector<int>& lps, string b) {
        int n = b.size();
        int l = 0;
        int i = 1;

        while (i < n) {
            if (b[i] == b[l]) {
                l++;
                lps[i] = l;
                i++;
            } else {
                if (l != 0) {
                    l = lps[l - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int kmp(string a, string b, vector<int>& lps) {
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;

        while (i < n) {
            if (a[i] == b[j]) {
                i++;
                j++;

                if (j == m) {
                    return 1;
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        vector<int> lps(b.size(), 0);
        longestprefixsuffix(lps, b);

        string ans = a;
        int count = 1;

        while (ans.size() < b.size()) {
            ans += a;
            count++;
        }

        if (kmp(ans, b, lps) == 1) {
            return count;
        }

        ans += a;
        count++;

        if (kmp(ans, b, lps) == 1) {
            return count;
        }

        return -1;
    }
};