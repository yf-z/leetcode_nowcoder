// Yifan Zhang
// 12/27/2020

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        if (n == 0 || m == 0)
            return 0;
        
        int mat[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mat[i][j] = 0;
            }
        }
        
        for (auto it = indices.begin(); it != indices.end(); ++it) {
            for (int j = 0; j < m; ++j) {
                mat[(*it)[0]][j] ++;
            }
            
            for (int i = 0; i < n; ++i) {
                mat[i][(*it)[1]] ++;
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] % 2 != 0) {
                    count ++;
                }
            }
        }
        
        return count;
    }
};