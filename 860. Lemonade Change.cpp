class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.empty())
            return true;
        
        if (bills.front() != 5)
            return false;
        
        int five = 0;
        int ten = 0;
        
        for (auto it = bills.begin(); it != bills.end(); ++it) {
            if (*it == 5) {
                ++five;
            }
            else if (*it == 10) {
                if (five > 0) {
                    --five;
                    ++ten;
                }
                else
                    return false;
            }
            else {
                if (ten > 0 && five > 0) {
                    --ten;
                    --five;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else
                    return false;
            }
        }
        
        return true;
    }
};