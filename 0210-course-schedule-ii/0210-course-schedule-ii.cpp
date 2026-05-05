#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    void bfs(vector<vector<int>> &adj, vector<int>& indegree, vector<int>& arr, queue<int>& q)
    {
        while(q.empty() == 0){

            int index = q.front();
            q.pop();

            arr.push_back(index);   // store topo order

            for(int j = 0 ; j < adj[index].size() ; j++){
                int neigh = adj[index][j];

                indegree[neigh]--;

                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;


        for(int i = 0 ; i < prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);   // b -> a
            indegree[a]++;
        }

        // push 0 indegree nodes
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> arr;

        bfs(adj, indegree, arr, q);

        // cycle check
        if(arr.size() != numCourses){
            return {};   // not possible
        }

        return arr;
    }
};