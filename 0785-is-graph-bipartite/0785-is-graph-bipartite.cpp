class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& colour, int index, int c) {

        colour[index] = c;

        for (int j = 0; j < graph[index].size(); j++) {

            int i = graph[index][j]; // its neighbour

            if (colour[i] == 0) {

                bool b = dfs(graph, colour, i, -c);
                if (b == false) {
                    return false;
                }

            } else if (colour[i] == colour[index]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int m = graph.size();

        vector<int> colour(m, 0);

        for (int i = 0; i < m; i++) {
            if (colour[i] == 0) {
                if (dfs(graph, colour, i, 1) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};