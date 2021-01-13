// Yifan Zhang
// 12/23/2020

class Solution {
public:
    void strip(string &s) {
        while (s.back() == ' ')
            s.pop_back();
        
        while (s.front() == ' ')
            s = s.substr(1);
        
        return;
    }
    
    int lengthOfLastWord(string s) {
        strip(s);
        size_t idx = s.rfind(' ');
        
        if (idx == string::npos)
            return s.size();

        s = s.substr(idx+1);
        return s.size();
    }
};