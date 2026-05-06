class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        set<string> s(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        s.erase(beginWord);

        int level = 0;
        int done = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int k = 0; k < size; k++) {

                string temp = q.front();
                q.pop();

                if (temp == endWord) {
                    return level + 1;
                }

                for (int i = 0; i < temp.length(); i++) {

                    char original = temp[i];

                    for (int j = 0; j < 26; j++) {
                        temp[i] = j + 'a';

                        if (s.find(temp) != s.end()) {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }

                    temp[i] = original;
                }
            }
            level++;
        }

        return 0;
    }
};