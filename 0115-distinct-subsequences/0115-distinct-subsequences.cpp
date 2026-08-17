class Solution {
public:

    int fact(string s, string t, int i , int j ){

        vector<double>prev(j+1, 0); // IMP, intialized with 0

        // Base Case
        prev[0] = 1;

        for(int n = 1; n <= i ; n++ ){
            for(int m = j; m >=1 ; m--){

                // 1-indexed i and j, so
                if(s[n-1] == t[m-1]){
                    // Two things we can do now, take this char and go to new char of s and t, OR dont take this char and only go to new char of s;
                    prev[m] = prev[m-1] + prev[m];
                }
            }
        }



        return (int)prev[j];
    }

    int numDistinct(string s, string t) {
        // Making it 1-indexed for easier base case
        int i = s.length();
        int j = t.length();

        return fact(s, t, i, j);
    }
};