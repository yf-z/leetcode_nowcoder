// Yifan Zhang
// 12/27/2020

class Solution {
public:
    bool isValid(int x) {
        int t = x;
        while (t) {
            int digit = t % 10;
            if (digit == 0 || x % digit != 0)
                return false;
            
            t = t/10;
        }
        
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        
        for (int i = left; i <= right; ++i) {
            if (isValid(i)) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};