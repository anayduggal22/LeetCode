class Solution {
public:
    int climbStairs(int n) {
        
        int prev = 1; // For 1 stair
        int prev2 = 1; // For 0 stair

        for(int i = 2 ; i <= n ; i++){

            int curr = prev + prev2;

            prev2 = prev;
            prev = curr;

        }

        return prev;
    }
};