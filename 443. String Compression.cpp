// Yifan Zhang
// 01/12

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty())
            return 0;
        
        int count = 0;
        char cur = chars.front();
        int idx = 0;
        
        for (auto it = chars.begin(); it != chars.end(); ++it) {
            if (*it != cur) {
                if (count > 1) {
                    if (idx < chars.size())
                        chars[idx] = cur;
                    else
                        chars.push_back(cur);
                    
                    
                    string s = to_string(count);
                    for (int i = 0; i < s.size(); ++i ){
                        if (idx+1+i < chars.size())
                            chars[idx+1+i] = s[i];
                        else
                            chars.push_back(s[i]);
                    }
                    idx ++;
                    idx += s.size();
                }
                else {
                    if (idx < chars.size())
                        chars[idx] = cur;
                    else
                        chars.push_back(cur);
                    idx += 1;
                }
                
                cur = *it;
                count = 1;
            }
            else {
                count ++;
            }
            
        }
        
        if (count > 1) {
            if (idx < chars.size())
                chars[idx] = cur;
            else
                chars.push_back(cur);


            string s = to_string(count);
            for (int i = 0; i < s.size(); ++i ){
                if (idx+1+i < chars.size())
                    chars[idx+1+i] = s[i];
                else
                    chars.push_back(s[i]);
            }
            idx ++;
            idx += s.size();
        }
        else {
            if (idx < chars.size())
                chars[idx] = cur;
            else
                chars.push_back(cur);
            idx += 1;
        }
        
        return idx;
    }
};