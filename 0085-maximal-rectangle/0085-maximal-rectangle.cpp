class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // For finding PREVIOUS smaller elements on left
        vector<int> premin(heights.size(), 0);
        stack<int> s1;

        for (int i = 0; i < heights.size(); i++) {

            // Pop until smaller element found
            while (s1.empty() == 0 && heights[s1.top()] >= heights[i]) {
                s1.pop();
            }

            // At starting of the hieght array
            if (s1.empty() == 1) {
                premin[i] = -1;
            } else {
                premin[i] = s1.top();
            }

            s1.push(i);
        }

        // For finding NEXT smaller elements on right
        vector<int> sucmin(heights.size(), 0);
        stack<int> s2;

        for (int i = heights.size() - 1; i >= 0; i--) {

            // Pop until smaller element found
            while (s2.empty() == 0 && heights[s2.top()] >= heights[i]) {
                s2.pop();
            }

            // At end of the hieght array
            if (s2.empty() == 1) {
                sucmin[i] = sucmin.size();
            } else {
                sucmin[i] = s2.top();
            }

            s2.push(i);
        }

        // Max area
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {

            int area = heights[i] * (sucmin[i] - premin[i] - 1);

            max_area = max(max_area, area);
        }

        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int max_rectangle = 0;

        vector<int> heights(matrix[0].size(), 0);

        for(int i = 0; i < matrix.size(); i++){

            for(int j = 0 ; j < matrix[0].size(); j++){

                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }

            int area = largestRectangleArea(heights);

            max_rectangle = max(max_rectangle,area);
        }

        return max_rectangle;
    }
};