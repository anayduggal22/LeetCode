class Solution {
public:

    int fact(string word1, string word2){
        // In tabulation/SpaceOptimisation, we dont subtract the
        // below with 1, cos we need extra space for base case
        // when there string subsequence becomes empty

        int i = word1.length();
        int j = word2.length();

        vector<int> prev(j + 1, -1);

        // Base Case
        for(int n = 0 ; n <= j ; n++){
            prev[n] = 0;
        }

        for(int n = 1; n <= i; n++){
            vector<int> curr(j + 1, -1);
            curr[0] = 0; // IMP Base Case

            for(int m = 1; m <= j ; m++){

                if(word1[n-1] == word2[m-1]){
                    curr[m] = 1 + prev[m-1];
                }

                else{
                    curr[m] = max(curr[m-1], prev[m]);
                }
            }

            prev = curr;

        }

        return prev[j];
    }

    int minDistance(string word1, string word2) {
        
        int common_length = fact(word1, word2);

        int deletion = word1.length() - common_length;
        int insertion = word2.length() - common_length;

        return deletion + insertion;
    }
};