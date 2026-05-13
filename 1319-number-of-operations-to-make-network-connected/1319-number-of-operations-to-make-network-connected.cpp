class Solution {
public:
    int global_parent(vector<int>& parent, int x) {

        if (parent[x] == x) {
            return x;
        }

        return parent[x] = global_parent(parent, parent[x]);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1) {
            return -1;
        }

        vector<int> parent(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < connections.size(); i++) {
            int x = connections[i][0];
            int y = connections[i][1];

            int parent_x = global_parent(parent, x);
            int parent_y = global_parent(parent, y);

            if (parent_x != parent_y) {
                parent[parent_y] = parent_x;
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                components++;
            }
        }

        int cables = components - 1;

        return cables;
    }
};