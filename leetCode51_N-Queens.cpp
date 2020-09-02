/*
*   Written By
*   Yifan Zhang
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> re;
        n = n-1;
        backTracking(re, {}, 0, n);
        return re;
    }
    
    bool underAttack(vector<pair<int, int>>& locs, int x, int y) {
        for (auto it = locs.begin(); it != locs.end(); it++) {
            if (it->first == x || it ->second == y) {
                return true;
            }
            
            if (abs(y-it->second) == abs(x-it->first)) {
                return true;
            }
        }
        
        return false;
    }
    
    void backTracking(vector<vector<string>> &re, vector<pair<int, int>> cur, int row, int &n) {
        if (row > n) {
            return;
        }
        
        for (int i = 0; i <= n; i++) {
            if (!underAttack(cur, row, i)) {
                pair<int, int> curLoc (row, i);
                cur.push_back(curLoc);
                if (row == n) {
                    pushInRe(re, cur, n);
                }
                
                backTracking(re, cur, row+1, n);
                cur.pop_back();
            }
        }
        
        return;
    }
    
    void pushInRe(vector<vector<string>> &re, vector<pair<int, int>> loc, int &n) {
        vector<string> temp;
        for (auto it = loc.begin(); it != loc.end(); it++) {
            string s(n+1, '.');
            s[it->second] = 'Q';
            temp.push_back(s);
        }
        re.push_back(temp);
        return;
    }
};