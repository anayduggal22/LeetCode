class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for (int i = 0; i < bills.size(); i++) {

            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                if (five - 1 < 0) {
                    return false;
                }
                five--;
                ten++;
            }

            else if (bills[i] == 20) {
                twenty++;
                if (ten - 1 >= 0 && five - 1 >= 0) {
                    ten--;
                    five--;
                } else if (five - 3 >= 0) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};