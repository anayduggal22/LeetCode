class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> low(26, -1);
        vector<int> up(26, -1);

        for (int i = 0; i < word.length(); i++) {

            if (word[i] >= 'a' && word[i] <= 'z') {
                low[word[i] - 'a'] = i;
            } else if (word[i] >= 'A' && word[i] <= 'Z') {

                // This done because we only need the first occurance
                // of uppercase
                if (up[word[i] - 'A'] == -1) {
                    up[word[i] - 'A'] = i;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (low[i] == -1 || up[i] == -1) {
                continue;
            }
            if (low[i] < up[i]) {
                count++;
            }
        }

        return count;
    }
};