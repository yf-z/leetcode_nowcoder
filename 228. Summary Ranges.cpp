// Yifan Zhang
// 12/27/2020

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        
        if (nums.size() == 1)
            return {to_string(nums.front())};
        
        vector<string> res;
        int start = nums.front();
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums.at(i) != nums.at(i-1)+1) {
                string cur;
                    
                if (nums.at(i-1) != start) {
                     cur = to_string(start)+"->"+to_string(nums.at(i-1));
                }
                else {
                    cur = to_string(start);
                }
                
                res.push_back(cur);
                start = nums.at(i);
            }
        }
        
        if (start == nums.back())
            res.push_back(to_string(start));
        else
            res.push_back(to_string(start)+"->"+to_string(nums.back()));
        
        return res;
    }
};