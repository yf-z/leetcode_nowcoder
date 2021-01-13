// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Yifan Zhang
// 12/23/2020

class Solution {
public:
    string convertNum(char c) {
        switch (c) {
            case '2':
                return "abc";
                break;
            case '3':
                return "def";
                break;
            case '4':
                return "ghi";
                break;
            case '5':
                return "jkl";
                break;
            case '6':
                return "mno";
                break;
            case '7':
                return "pqrs";
                break;
            case '8':
                return "tuv";
                break;
            case '9':
                return "wxyz";
                break;
            default:
                return "";
        }
        
        return "";
    }
    
    string processStr(string digits) {
        if (digits.empty()) {
            return "";
        }
        
        string re;
        for (auto it = digits.begin(); it != digits.end(); it++) {
            if (*it != '1') {
                re += *it;
            }
        }
        
        return re;
    }
    
    void bt(string digits, vector<string> &re, string cur) {
        if (digits.empty()) {
            re.push_back(cur);
            return;
        }
        
        string cur_choice = convertNum(digits[0]);
        for (auto it = cur_choice.begin(); it != cur_choice.end(); ++it) {
            cur.push_back(*it);
            bt(digits.substr(1), re, cur);
            cur.pop_back();
        }
        
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        digits = processStr(digits);
        
        if (digits.empty()) {
            return {};
        }
        
        vector<string> re;
        bt(digits, re, "");
        return re;
    }
};