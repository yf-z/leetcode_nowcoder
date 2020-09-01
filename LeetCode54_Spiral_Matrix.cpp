class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return {};
        }
        
        int n = matrix[0].size();
        
        if (n == 0) {
            return {};
        }
        
        vector<int> re;
        
        so(re, matrix, 0, m-1, 0, m, n);
        return re;
    }
    
    void so(vector<int> &re, vector<vector<int>>&matrix, int s, int e, int count, int &m, int &n) {
        //cout << s << " " << e << endl;
        if (re.size() == m*n) {
            return;
        }
        
        if (s > e) {
            return;
        }
        
        if (s == e) {
            for (int i = count; i < n-count; i++) {
                re.push_back(matrix[s][i]);
            }
            return;
        }
        
        for (int i = count; i < n-count-1; i++) {
            re.push_back(matrix[s][i]);
        }
        
        for (int i = s; i <= e; i++) {
            if (n-count-1 >= 0 && n-count-1 < n)
                re.push_back(matrix[i][n-count-1]);
        }
        
        for (int i = n-count-2; i>= count; i--) {
            re.push_back(matrix[e][i]);
        }
        
        for (int i = e-1; i > s; i--) {
            if (count != n-count-1)
                re.push_back(matrix[i][count]);
        }
        
        so(re, matrix, s+1, e-1, count+1, m, n);
    }
};