class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        
        auto it = s.begin();
        
        while (it != s.end()) {
//             if not )
            if (*it != ')') {
                res += *it;
            }
//             if ) reverse
            else {
                string temp;
                while (res.back() != '(') {
                    temp += res.back();
                    res.pop_back();
                }
                res.pop_back();
                res += temp;
            }
            
            ++it;
        }
        
        return res;
    }
};