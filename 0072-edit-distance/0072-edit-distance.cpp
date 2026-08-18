class Solution {
public:

    int fact(string word1, string word2, int i, int j){

        // Base Case
        vector<int>prev(word2.length() + 1, -1);

        for(int n = 0; n <= j ; n++){
            prev[n] = n;
        }

        for(int n = 1; n <= i ; n++){

            vector<int>curr(word2.length() + 1, -1);
            curr[0] = n; // Base Case

            for(int m = 1; m <= j ; m++){

                // 1 based indexing, thats why -1
                if(word1[n-1] == word2[m-1]){
                    // Here 0 operations will be done
                    curr[m] = 0 + prev[m-1];
                }

                else{
                    int insert = curr[m-1];
                    int del = prev[m];
                    int replace = prev[m-1];

                    curr[m] = 1 + min(insert,min(del,replace));
                }

            }

            prev = curr;
        }

        return prev[j];

    }

    int minDistance(string word1, string word2) {

        // For 1base indexing, done for easy base case
        int i = word1.length();
        int j = word2.length();

        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));

        return fact(word1,word2,i,j);
    }
};