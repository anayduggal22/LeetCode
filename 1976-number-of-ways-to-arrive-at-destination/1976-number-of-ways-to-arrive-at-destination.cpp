class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < roads.size(); i++) {

            int r = roads[i][0];
            int c = roads[i][1];
            int w = roads[i][2];

            graph[r].push_back({c, w});
            graph[c].push_back({r, w});
        }

        vector<long long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);

        distance[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> p;

        // {distance,node}

        p.push({0, 0});

        while (!p.empty()) {

            long long d = p.top().first;
            int index = p.top().second;
            p.pop();

            for (int i = 0; i < graph[index].size(); i++) {

                int neigh = graph[index][i].first;
                int weigh = graph[index][i].second;

                if (weigh + d < distance[neigh]) {

                    distance[neigh] = weigh + d;
                    // First Time this node is found so the
                    // no. of ways initially is 0
                    ways[neigh] = ways[index];
                    p.push({distance[neigh], neigh});
                }

                else if (weigh + d == distance[neigh]) {

                    ways[neigh] =
                    (ways[neigh] + ways[index]) % 1000000007;
                    // Dont put in priority queue
                }
            }
        }

        return ways[n - 1];
    }
};