class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int m = -1;
        int s = 0;

        for (int i = 0; i < weights.size(); i++) {
            m = max(m, weights[i]);
            s += weights[i];
        }

        int low = m; // Largets Number in the Array will be the minimum capacity
        int high = s; // Sum of all elements in the Array will be the maximum capacity

        int trips = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int d = 1; // If if never exceeds,thats why initialized with 1, not 0.
            int w = 0;

            for (int i = 0; i < weights.size(); i++) {
                
                if(weights[i] + w > mid){ // Capacity Exceded
                    d++;
                    w = weights[i];
                }
                else{
                    w += weights[i];
                }
            }

            if (d <= days) {
                trips = mid;
                high = mid - 1; // Can be a more smaller than this
            }

            else {
                low = mid + 1; // Not found
            }
        }

        return trips;
    }
};