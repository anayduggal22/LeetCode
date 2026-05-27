class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> low(26, 0);
        vector<int> up(26, 0);

        for (int i = 0; i < word.length(); i++) {

            if (word[i] >= 'a' && word[i] <= 'z') {
                low[word[i] - 'a']++;
            } else if (word[i] >= 'A' && word[i] <= 'Z') {
                up[word[i] - 'A']++;
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (low[i] != 0 && up[i] != 0) {
                count++;
            }
        }

        return count;
    }
};