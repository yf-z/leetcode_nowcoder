/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// binary search woohoo

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if (mountainArr.length() == 0)
            return -1;
        
        int max_idx = binary_max(mountainArr, 0, mountainArr.length()-1);
        int max_num = mountainArr.get(max_idx);
        if (target > max_num)
            return -1;
        
        if (target == max_num)
            return max_idx;
        
        int left_idx = binary_left(mountainArr, 0, max_idx, target);
        int right_idx = binary_right(mountainArr, max_idx, mountainArr.length()-1, target);
        int res = min(left_idx, right_idx);
        if (res == INT_MAX)
            res = -1;
        
        return res;
    }
    
   int binary_max(MountainArray &mountainArr, int i, int j) {
        if (i == j) 
            return i;
        
        int middle = (i+j)/2+1;
        if (mountainArr.get(middle) > mountainArr.get(middle-1)) {
            return binary_max(mountainArr, middle, j);
        }
        
        return binary_max(mountainArr, i, middle-1);
    }
    
    int binary_left(MountainArray &mountainArr, int i, int j, int target) {
        if (i >= j) {
            if (mountainArr.get(j) == target)
                return j;
            return INT_MAX;
        }
        
        int middle = (i+j)/2+1;
        int cur = mountainArr.get(middle);
        if (cur == target)
            return middle;
        
        if (cur > target)
            return binary_left(mountainArr, i, middle-1, target);
        
        return binary_left(mountainArr, middle+1, j, target);
    }
    
    int binary_right(MountainArray &mountainArr, int i, int j, int target) {
        if (i >= j) {
            if (mountainArr.get(j) == target)
                return j;
            return INT_MAX;
        }
        
        int middle = (i+j)/2+1;
        int cur = mountainArr.get(middle);
        if (cur == target)
            return middle;
        
        if (cur > target)
            return binary_right(mountainArr, middle+1, j, target);
        
        return binary_right(mountainArr, i, middle-1, target);
    }
};