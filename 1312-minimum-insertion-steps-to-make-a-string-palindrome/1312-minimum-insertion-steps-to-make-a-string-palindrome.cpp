class Solution {
public:

    int fact(string s){

        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<int> prev(s.length() + 1, -1);

        // Base Case, for 0-length subsequence
        for(int i = 0 ; i < prev.size() ; i++){
            prev[i] = 0;
        }

        for(int i = 1 ; i <= s.length(); i++){
            vector<int> curr(s.length() + 1, -1);
            curr[0] = 0; // IMPORTANT

            for(int j = 1; j <= s.length(); j++){

                if(s1[i - 1] == s2[j - 1]){
                    curr[j] = 1 + prev[j - 1];
                }
                
                else{
                    curr[j] = max(curr[j-1], prev[j]);
                }
            }

            prev = curr;
            
        }

        return prev[s.length()];
    }


    int minInsertions(string s) {

        int longest_palindromic_sequence = fact(s);

        return s.length() - longest_palindromic_sequence;
    }
};