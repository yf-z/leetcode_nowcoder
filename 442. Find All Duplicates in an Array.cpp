class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.empty())
            return {};
        
        vector<int> res;
        int a[nums.size()];
        
        for (int i = 0; i < nums.size(); ++i)
            a[i] = 0;
        
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            a[*it-1]++;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (a[i] > 1) {
                res.push_back(i+1);
            }
        }
        
        return res;
    }
};


// mark by negative nums
// vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> res;
//         for(int i = 0; i < nums.size(); i ++){
//             nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
//             if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums [i]));
//         }
//         return res;
//     }