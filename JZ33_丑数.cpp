class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;
        
        vector<int> ugly_nums;
        ugly_nums.push_back(1);
        
        int pointer2 = 0;
        int pointer3 = 0;
        int pointer5 = 0;
        while ((int)ugly_nums.size() < index) {
            int cur = min(ugly_nums[pointer2]*2, min(ugly_nums[pointer3]*3, ugly_nums[pointer5]*5));
            ugly_nums.push_back(cur);
            if (ugly_nums[pointer2]*2 ==  cur) pointer2++;
            if (ugly_nums[pointer3]*3 == cur) pointer3++;
            if (ugly_nums[pointer5]*5 == cur) pointer5++;
        }
        
        return ugly_nums[index-1];
    }
};