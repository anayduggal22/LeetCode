class Solution {
public:

    bool check(string& a, string& b){

        // Next bigger string should have 1 more element than previous
        if(a.size() != b.size() + 1){
            return false;
        }

        int pa = 0; // Pointer for string a
        int pb = 0; // Pointer for string b

        while(pa < a.size()){

            if(pb < b.size() && a[pa] == b[pb]){
                pa++;
                pb++;
            }
            else{
                // a[pa] is different so we will only increment pa
                pa++;
            }
        }

        if(pa == a.size() && pb == b.size()){
            return true;
        }

        return false;
    }

    static bool comparator(string& a, string& b){

        return a.size() < b.size();
    }

    int longestStrChain(vector<string>& words) {
        
        // Sorting because we want sequences not subsequences
        sort(words.begin(), words.end(), comparator);

        // Every Chain initially of 1 size,i.e the element itself
        vector<int>dp(words.size(), 1);

        for(int i = 1; i < words.size(); i++){
            for(int j = 0 ; j < i ; j++){

                if(check(words[i],words[j]) && dp[i] < dp[j] + 1){

                    dp[i] = dp[j] + 1;
                }
            }
        }

        int m = -1;

        for(int i = 0 ; i < dp.size(); i++){
            m = max(m,dp[i]);
        }

        return m;
    }
};