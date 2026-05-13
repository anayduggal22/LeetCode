class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // 1-based indexing, thats why (n+1)
        vector<vector<pair<int, int>>> graph(n+1); 

        for (int i = 0; i < times.size(); i++) {
            int r = times[i][0];
            int c = times[i][1];
            int w = times[i][2];

            // Adjacency List, Directed Graph
            graph[r].push_back({c, w});
        }

        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0; // Distance of Source is 0 only

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            p; // MIN HEAP

        p.push({0, k});
        // {distance, node}

        while(!p.empty()){
            int d = p.top().first;
            int index = p.top().second;
            p.pop();

            // Outdated
            if(d > distance[index]) {
                continue;
            }

            // Checking all connected components of index
            for(int i = 0 ; i < graph[index].size() ; i++){
                
                int neigh = graph[index][i].first;
                int edge_weight = graph[index][i].second;

                // Relaxing
                if(distance[neigh] > d + edge_weight){

                    distance[neigh] = d + edge_weight;
                    p.push({distance[neigh], neigh});
                }
            }
        }

        int m = -1;

        // 1-based indexing, thats why i = 1
        for(int i = 1 ; i < distance.size() ; i++){
            if(distance[i] == INT_MAX){
                return -1;
            }

            m = max(m,distance[i]);
        }

        return m;
    }
};