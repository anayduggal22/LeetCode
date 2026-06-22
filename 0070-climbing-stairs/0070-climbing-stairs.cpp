class Solution {
public:

    int fact(int n, vector<int>& arr){

        if(n <= 1){
            return 1; // Only 1 way to climb
        }

        if(arr[n] != -1){
            // Its value was already stored so return that
            return arr[n];
        }

        int x = fact(n-1,arr);

        int y = fact(n-2,arr);

        return arr[n] = x + y;
    }

    int climbStairs(int n) {
        
        vector<int> arr(n+1,-1);

        return fact(n,arr);
    }
};