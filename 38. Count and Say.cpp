// Yifan Zhang
// 12/23/2020

class Solution {
public:
    string say(string s) {
        if (s.empty())
            return "";
        
        string re;
        char c = s[0];
        int count = 0;
        
        for (auto it = s.begin(); it != s.end(); it++) {
            if (*it != c) {
                re += to_string(count);
                re += c;
                c = *it;
                count = 1;
            }
            else {
                count ++;
            }
        }
        
        if (count != 0) {
            re += to_string(count);
            re += c;
        }
        
        return re;
    }
    
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        return say(countAndSay(n-1));
    }
};