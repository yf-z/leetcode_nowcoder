class Solution {
public:
    string convertPosDecToBi(int n) {
        if (n == 1)
            return "1";
        
        if (n == 0)
            return "0";
        
        if (n%2 == 0)
            return convertPosDecToBi(n/2)+"0";
        
        return convertPosDecToBi(n/2)+"1";
    }
    
    void add1(string &s) {
        int digit = 1;
        std::reverse(s.begin(), s.end());
        int i = 0;
        
        while (i < (int)s.size()) {
            int cur = s[i]+digit;
            if (cur >= 50) {
                digit = 1;
                cur -= 2;
            }
            else
                digit = 0;
            
            s[i] = cur;
            i++;
        }
        
        std::reverse(s.begin(), s.end());
    }
    
    string convertNegDecToBi(int n) {
        string s = convertPosDecToBi(-n);

        if (s.size() < 32) {
          s = string(32-s.size(), '0')+s;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }
        
        add1(s);
        return s;
    }
    
    int count1s(string &s) {
        int count = 0;
        for (char c:s) {
            if (c == '1')
                count++;
        }
        
        return count;
    }
    
     int  NumberOf1(int n) {
         if (n == 0)
             return 0;
         
         if (n == INT_MIN)
             return 1;
         
         if (n > 0) {
             string s = convertPosDecToBi(n);
             return count1s(s);
         }
         
         string s = convertNegDecToBi(n);
         return count1s(s);
     }
};