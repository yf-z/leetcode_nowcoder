class Solution {
public:
    string makeGood(string s) {
        if (s.empty() || s.size() == 1)
            return s;
        
        process_str(s);
        return s;
    }
    
    void process_str(string &s) { 
        string t = "";
        bool contain = false;
        
        do {
            contain = false;
            for (char a = 'a'; a <= 'z'; ++a) {
                t = "";
                t += a;
                t += toupper(a);
                size_t pos = s.find(t);
                if (pos != string::npos) {
                    s = s.replace(pos, 2, "");
                    contain = true;
                }
                
                t = "";
                t += toupper(a);
                t += a;
                pos = s.find(t);
                if (pos != string::npos) {
                    s = s.replace(pos, 2, "");
                    contain = true;
                }
            }
        } while (contain && !s.empty());
    }
};


// two pointers
// string makeGood(string s, int p = 0) {
//     for (int i = 0; i < s.size(); ++i) {
//         if (p > 0 && abs(s[i] - s[p - 1]) == 32)
//             --p;
//         else
//             s[p++] = s[i];
//     }
//     return s.substr(0, p);
// }