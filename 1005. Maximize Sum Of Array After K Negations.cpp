class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if (A.empty())
            return 0;
        
        sort(A.begin(), A.end());
        
        for (auto it = A.begin(); it != A.end(); ++it) {
            if (*it < 0 && K > 0) {
                *it = -(*it);
                K--;
            }
            else
                break;
        }
        
        K = K % 2;
        if (K > 0) {
            sort(A.begin(), A.end());
            A[0] = -A[0];
        }
        
        int res = 0;
        for (auto it = A.begin(); it < A.end(); it++) {
            res += *it;
        }
        
        return res;
    }
};