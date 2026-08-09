class Solution {
public:

    int fact(const string& s1, const string& s2, int i, int j){

        vector<int> prev(s1.length() + 1, -1);

        // Out of Bound
        for(int n = 0 ; n <= i ; n++){
            prev[n] = 0;
        }

        for(int n = 1; n <= i; n++){
            
            vector<int> curr(s1.length() + 1, -1);
            curr[0] = 0;

            for(int m = 1; m <= j; m++){

            if(s1[n-1] == s2[m-1]){
                curr[m] = 1 + prev[m-1];
            }
            else{
                curr[m] = max(prev[m], curr[m-1]);
            }

            }

            prev = curr;
        }

        return prev[j];

    }

    int longestPalindromeSubseq(string s) {
        // The problem can be boiled down to finding the 
        // Longest Common Subsequence between a string
        // and its reverse.

        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        // Not subtracting by minus one as did in memoization
        // Due to base case of going negative cannot be done
        // In tabulation

        int i = s.length();
        int j = s.length();

        return fact(s1, s2, i, j);
    }
};