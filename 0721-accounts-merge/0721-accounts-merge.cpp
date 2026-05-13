class Solution {
public:

    // Finding Ultimate Parent
    int find(vector<int>& parent, int child){

        // If parent of child is itself,
        // then it is Ultimate Parent
        if(parent[child] == child){
            return child;
        }

        // Path Compression
        return parent[child] = find(parent, parent[child]);
    }

    // Union
    void union_find(vector<int>& parent, int u, int v){

        int p_u = find(parent, u);
        int p_v = find(parent, v);

        // Already in same component
        if(p_u == p_v){
            return;
        }

        // Connecting Components
        parent[p_v] = p_u;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();

        // DSU Parent Array
        vector<int> parent(n);

        // email -> account index
        map<string, int> mp;

        // Initially every node is parent of itself
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }

        // Traversing Accounts
        for(int i = 0 ; i < accounts.size() ; i++){

            // Traversing Emails
            // j = 1 because accounts[i][0] = Name
            for(int j = 1; j < accounts[i].size() ; j++){

                string email = accounts[i][j];

                // If email already exists,
                // then both accounts belong to same person
                if(mp.find(email) != mp.end()){

                    int key = mp[email];

                    // Union Both Accounts
                    union_find(parent, key, i);
                }

                else{

                    // Storing email -> account index
                    mp[email] = i;
                }
            }
        }

        // parent -> all emails
        map<int, vector<string>> merged;

        // Traversing Map
        for(auto it : mp){

            string email = it.first;
            int node = it.second;

            // Finding Ultimate Parent
            int parent_node = find(parent, node);

            // Storing Emails in Same Component
            merged[parent_node].push_back(email);
        }

        vector<vector<string>> ans;

        // Traversing Components
        for(auto it : merged){

            int node = it.first;
            vector<string> emails = it.second;

            // Sorting Emails
            sort(emails.begin(), emails.end());

            vector<string> temp;

            // Adding Name
            temp.push_back(accounts[node][0]);

            // Adding Emails
            for(int i = 0 ; i < emails.size() ; i++){
                temp.push_back(emails[i]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};