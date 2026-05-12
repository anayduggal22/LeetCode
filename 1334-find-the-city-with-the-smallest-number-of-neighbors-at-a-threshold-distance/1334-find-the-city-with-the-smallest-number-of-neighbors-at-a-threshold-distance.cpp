class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // Adjacency Matrix for FLOYD's WARSHALL ALGORITHM
        vector <vector<int>> graph(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < edges.size(); i++) {

            int r = edges[i][0];
            int c = edges[i][1];
            int w = edges[i][2];

            graph[r][c] = w; // Undirected
            graph[c][r] = w; // Graph
        }

        for(int i = 0 ; i < n ; i++){
            graph[i][i] = 0;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    // If either path does not exist, we skip to avoid overflow
                    if (graph[i][via] == INT_MAX 
                    || graph[via][j] == INT_MAX) {
                        continue;
                    }

                    // Relaxation
                    if (graph[i][j] > graph[i][via] + graph[via][j]) {

                        graph[i][j] = graph[i][via] + graph[via][j];
                    }
                }
            }
        }

        int count = INT_MAX;
        int city = -1;

        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {

                if(graph[i][j] <= distanceThreshold){
                    temp++;
                }
            }

            if(temp <= count){
                count = temp;
                city = i;
            }
        }

        return city;
    }
};