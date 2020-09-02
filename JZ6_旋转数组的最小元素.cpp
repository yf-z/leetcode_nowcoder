/*
*   Written By
*   Yifan Zhang
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        return binarySearch(rotateArray, 0, rotateArray.size()-1);
    }
    
    int binarySearch(vector<int> &rotateArray, int s, int e) {
        if (s >= e) {
            return min(rotateArray[s], rotateArray[0]);
        }
        
        int middle = s + (e-s)/2;
        
        if (rotateArray[middle] > rotateArray[0]) {
            return binarySearch(rotateArray, middle+1, e);
        }
        
        if (rotateArray[middle] < rotateArray[0])
            return binarySearch(rotateArray, s, middle);
        
        return min(binarySearch(rotateArray, middle+1, e), binarySearch(rotateArray, s, middle));
    }
};