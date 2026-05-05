class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited,
             vector<int>& path_visited, vector<int>& safe, int index) {

        // If already processed reusing the result
        if (visited[index] == 1) {
            return safe[index];
        }

        visited[index] = 1;
        path_visited[index] = 1;

        // Loop over neighbors
        for (int i = 0; i < graph[index].size(); i++) {

            int neighboor = graph[index][i];

            if (visited[neighboor] == 1 
            && path_visited[neighboor] == 1) {
                return false; // cycle
            }

            bool b = dfs(graph, visited, path_visited, safe, neighboor);
            if (b == false) {
                return false;
            }
        }

        // Backtracking
        path_visited[index] = 0;
        safe[index] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int m = graph.size();

        vector<int> visited(m, 0);
        vector<int> path_visited(m, 0);
        vector<int> safe(m, 0);
        vector<int> arr;

        // Run DFS for all nodes
        for (int i = 0; i < m; i++) {
            if (visited[i] == 0) {
                dfs(graph, visited, path_visited, safe, i);
            }
        }

        for (int i = 0; i < m; i++) {
            if (safe[i] == 1) {
                arr.push_back(i);
            }
        }

        return arr;
    }
};