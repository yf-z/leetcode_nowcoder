bool compare_func(vector<int> a, vector<int> b) {
        return a[0]<b[0];
    }

class Solution {
public:    
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty())
            return 0;
        
        if (pairs.size() == 1)
            return 1;
        
        sort(pairs.begin(), pairs.end(), compare_func);
        
        // dp
        vector<int> trace;
        
        for (int i = 0; i < pairs.size(); ++i) {
            trace.push_back(1);
        }
        
        int max_len = 1;
        for (int i = 1; i < trace.size(); ++i) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    trace[i] = max(trace[i], 1+trace[j]);
                    if (trace[i] > max_len)
                        max_len = trace[i];
                }
            }
        }
        
        return max_len;
    }
};


// greedy
// by alexander
// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(), pairs.end(), cmp);
//         int cnt = 0;
//         for (int i = 0, j = 0; j < pairs.size(); j++) {
//             if (j == 0 || pairs[i][1] < pairs[j][0]) {
//                 cnt++;
//                 i = j;
//             }
//         }
//         return cnt;
//     }

// private:
//     static bool cmp(vector<int>& a, vector<int>&b) {
//         return a[1] < b[1];
//     }
// };