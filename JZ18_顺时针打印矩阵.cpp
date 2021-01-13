class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.size() == 0)
            return {};
        
        if (matrix.at(0).size() == 0)
            return {};
        
        int row2 = matrix.size()-1, col = matrix.at(0).size()-1;
        vector<int> re;
        reconstructMatrix(matrix, re, 0, row2, 0, col);
        return re;
    }
    
    void reconstructMatrix(vector<vector<int>> &matrix, vector<int> &re, int row1, int row2, int col1, int col2) {
        if (col2 < col1) 
            return;
        
        if (row1 > row2)
            return;
        
        if (row1 == row2) {
            for (int i = col1; i <= col2; i++) {
                re.push_back(matrix[row1][i]);
            }  
            
            return;
        }
        
        for (int i = col1; i <= col2; i++) {
            re.push_back(matrix[row1][i]);
        } 
        
        for (int i = row1+1; i < row2; i++) {
            re.push_back(matrix[i][col2]);
        }
            
        for (int i = col2; i >= col1; i--) {
            re.push_back(matrix[row2][i]);
        } 
        
        if (col1 != col2) {
            for (int i = row2-1; i > row1; i--) {
                re.push_back(matrix[i][col1]);
            }
        }
        
        return reconstructMatrix(matrix, re, row1+1, row2-1, col1+1, col2-1);
    }
};