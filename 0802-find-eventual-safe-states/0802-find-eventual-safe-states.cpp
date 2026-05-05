
class Solution
{
public:
    void bfs(vector<vector<int>> &rev, vector<int>& indegree,
             vector<int>& arr, queue<int>& q)
    {
        while(q.empty() == 0){
            int node = q.front();
            q.pop();

            arr.push_back(node);   // safe node

            for(int j = 0 ; j < rev[node].size() ; j++){
                int neigh = rev[node][j];

                indegree[neigh]--;

                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();

        vector<vector<int>> rev(n);   // reversed graph
        vector<int> indegree(n, 0);
        queue<int> q;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < graph[i].size() ; j++){

                int neigh = graph[i][j];

                rev[neigh].push_back(i); // reverse edge

                indegree[i]++; // count outgoing edges of original
            }
        }

        // push terminal nodes
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> arr;

        bfs(rev, indegree, arr, q);

        // Return Sorted Array
        sort(arr.begin(),arr.end());

        return arr;
    }
};