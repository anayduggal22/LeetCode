class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        // IMPORTANT
        sort(cuts.begin(), cuts.end());

        // INITIALIZE TO 0
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        // Doing reverse of memoization
        // i=1 to c -> c to 1
        // j = c to 1 -> 1 to c

        for (int i = c; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {

                // Base Case
                if (i > j) {
                    continue;
                }

                int m = INT_MAX;

                for (int k = i; k <= j; k++) {

                    int cost = (cuts[j + 1] - cuts[i - 1]) 
                    + dp[i][k - 1] 
                    + dp[k + 1][j];

                    m = min(m, cost);
                }

                dp[i][j] = m;
            }
        }

        return dp[1][c];
    }
};