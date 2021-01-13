class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0)
            return 0;
        
        map<int, int> dic;
        int threshold = numbers.size()/2;
        
        for (auto it = numbers.begin(); it != numbers.end(); it++) {
            auto i = dic.find(*it);
            if (i != dic.end()) {
                i->second++;
                if (i->second > threshold)
                    return *it;
            }
            else {
                dic.insert(pair<int, int>(*it, 1));
                if (1 > threshold)
                    return *it;
            }
        }
        
        return 0;
    }
};