class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        vector<vector<int>> distance(heights.size(),
        vector<int>(heights[0].size(), INT_MAX));

        distance[0][0] = 0;

        // MIN HEAP PRIORITY QUEUE
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> p;

        // {diff,{row,col}}
        p.push({0,{0,0}});

        while(!p.empty()){

            int diff = p.top().first;
            int row = p.top().second.first;
            int col = p.top().second.second;
            p.pop();

            int r[] = {0,-1,0,1};
            int c[] = {-1,0,1,0};

            for(int i = 0 ; i < 4 ; i++){

                int nrow = row + r[i];
                int ncol = col + c[i];

                if(nrow >= 0 && nrow < heights.size()
                && ncol >= 0 && ncol < heights[0].size()){

                    int newEffort = max(diff,
                    abs(heights[nrow][ncol] - heights[row][col]));

                    if(newEffort < distance[nrow][ncol]){

                        distance[nrow][ncol] = newEffort;

                        p.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }

        return distance[heights.size()-1][heights[0].size()-1];
    }
};