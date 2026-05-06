class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        // For easy finding and removing
        set<string> s(wordList.begin(), wordList.end());

        // if the endword does not exist in the list
        if (s.find(endWord) == s.end()) {
            return 0;
        }

        queue<string> q;
        // Push the beginword in a queue and remove form list
        q.push(beginWord);
        s.erase(beginWord);

        // For the number of words, that is the levels
        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            // For each level
            for (int k = 0; k < size; k++) {

                string temp = q.front();
                q.pop();

                // If we reached the endWord
                if (temp == endWord) {

                    // Return the number of words
                    return level + 1;
                }

                // For all combinations of this word
                for (int i = 0; i < temp.length(); i++) {
                    // To store the original character
                    char original = temp[i];

                    // For all combinations of that char
                    for (int j = 0; j < 26; j++) {
                        temp[i] = j + 'a';

                        // If word found, add to queue and remove
                        // from list
                        if (s.find(temp) != s.end()) {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }

                    // Change the word to its orignal form
                    temp[i] = original;
                }
            }
            // Increment the level(number of words)
            level++;
        }

        // Return 0 if found none
        return 0;
    }
};