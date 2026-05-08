class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> graph(n);

        for(int i = 0 ; i < flights.size() ; i++){
            
            int r = flights[i][0];
            int c = flights[i][1];
            int w = flights[i][2];

            graph[r].push_back({c,w});
        }

        vector<int> distance(n,INT_MAX);

        distance[src] = 0;

        // Priority Queue Not needed as the stops are increasing 
        // Linearly

        queue<pair<int,pair<int,int>>> q;
        // {Stops,{Distance,Node}}

        q.push({0,{0,src}});

        while(!q.empty()){

            int s = q.front().first;
            int d = q.front().second.first; 
            int index = q.front().second.second; 
            q.pop();

            if(s + 1 > k + 1){
                continue;
            }

            // Looking At nodes connected components
            for(int i = 0 ; i < graph[index].size() ; i++){

                int neigh = graph[index][i].first;
                int wiegh = graph[index][i].second;

                if(distance[neigh] > d + wiegh){
                    distance[neigh] = d + wiegh;

                    q.push({s+1,{distance[neigh],neigh}});
                }
            }
        }

        if(distance[dst] == INT_MAX){
            return -1;
        }

        return distance[dst];
    }
};