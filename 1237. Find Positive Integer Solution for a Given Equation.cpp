/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        fS(customfunction, z, 1, z, res);
        
        return res;
    }
    
    void fS(CustomFunction& customfunction, int z, int x, int y, vector<vector<int>> &res) {
        if (x > z)
            return;
        
        int j = y;
        
        for (j = y; j > 0; --j) {
            if (customfunction.f(x, j) == z) {
                res.push_back({x, j});
            }
            
            if (customfunction.f(x, j) <= z) {
                y = j;
                break;
            }
        }
        
        if (j == 0) {
            return;
        }
        
        fS(customfunction, z, x+1, y, res);
    }
};