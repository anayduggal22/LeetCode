class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {

        set<vector<int>> s;

        for (int l = 0; l < circles.size(); l++) {

            int x = circles[l][0];
            int y = circles[l][1];
            int r = circles[l][2];

            for (int i = x - r; i <= x + r; i++) {
                for (int j = y - r; j <= y + r; j++) {

                    int d = (x - i) * (x - i) + (y - j) * (y - j);

                    if (d <= r * r) {
                        s.insert({i, j});
                    }
                }
            }
        }
        return s.size();
    }
};