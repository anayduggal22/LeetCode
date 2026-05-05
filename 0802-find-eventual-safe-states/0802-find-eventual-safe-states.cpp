class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited,
             vector<int>& path_visited, int index) {

        visited[index] = 1;
        path_visited[index] = 1;

        // Looping over connected nodes of index
        for (int i = 0; i < graph[index].size(); i++) {
            int neighboor = graph[index][i];

            if (visited[neighboor] == 0) {
                bool b = dfs(graph, visited, path_visited, neighboor);

                // Cycle Detected
                if (b == false) {
                    return false;
                }
            }

            else if (visited[neighboor] == 1 && path_visited[neighboor] == 1) {
                return false;
            }
        }

        // Backtracking
        path_visited[index] = 0;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int m = graph.size();

        vector<int> visited(m, 0);
        vector<int> path_visited(m, 0);
        vector<int> arr;

        for (int i = 0; i < m; i++) {
            bool b = dfs(graph, visited, path_visited, i);

            if (b == true) {
                arr.push_back(i);
            }
        }

        return arr;
    }
};