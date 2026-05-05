class Solution
{
public:
    void bfs(vector<vector<int>> &adj, vector<int>& indegree, int &count, queue<int>& q)
    {
        while(q.empty() == 0){

            int index = q.front();
            q.pop();

            count++;   // count nodes

            for(int j = 0 ; j < adj[index].size() ; j++){
                int neigh = adj[index][j];

                indegree[neigh]--;

                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        // build graph
        for(int i = 0 ; i < prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);   // b -> a
            indegree[a]++;
        }

        // push all 0 indegree nodes
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        bfs(adj, indegree, count, q);

        // check if all nodes processed
        if(count == numCourses){
            return true;
        }

        return false;
    }
};