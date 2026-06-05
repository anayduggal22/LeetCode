class Solution {
public:
    int jump(vector<int>& nums) {

        // Number of jumps taken
        int jumps = 0;

        // Current reachable range [l, r]
        int l = 0;
        int r = 0;

        // Continue until last index becomes reachable
        while (r < nums.size() - 1) {

            // Farthest index reachable from current range
            int farthest = 0;

            // Explore all positions in current range
            for (int i = l; i <= r; i++) {

                // Maximum reachable index
                farthest = max(farthest, i + nums[i]);
            }

            // Next range starts after current range
            l = r + 1;

            // Next range ends at farthest reachable index
            r = farthest;

            // One more jump used
            jumps++;
        }

        return jumps;
    }
};