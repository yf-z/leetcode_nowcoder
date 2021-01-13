class Solution {
public:
    // O(n)
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() == 1)
            return array.at(0);
        
        int trace[array.size()];
        for (int i = 0; i < (int)array.size(); i++) {
            trace[i] = array[i];
        }
        
        for (int i = 1; i < array.size() ; i++) {
            trace[i] = max(trace[i], trace[i]+trace[i-1]);
        }
        
        int max = INT_MIN;
        for (int i = 0; i < array.size(); i++) {
            if (trace[i] > max)
                max = trace[i];
        }
        
        return max;
    }
};