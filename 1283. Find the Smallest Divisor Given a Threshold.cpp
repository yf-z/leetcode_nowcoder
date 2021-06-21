class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        return bs(nums, threshold, 1, nums.back()+1);
    }
    
    int bs(vector<int>&nums, int threshold, int i, int j) {
        if (i >= j) 
            return i;
        
        int middle = (i+j)/2;
        // cout << i << " " << middle << " " << j << " " << sum_v(nums, middle) << endl;
        
        if (sum_v(nums, middle) <= threshold) {           
            return bs(nums, threshold, i, middle);
        }
        
        return bs(nums, threshold, middle+1, j);
    }
    
    int sum_v(vector<int>&nums, int divisor) {
        int s = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            s += *it/divisor;
            s += (*it%divisor > 0);
        }
        
        return s;
    }
};