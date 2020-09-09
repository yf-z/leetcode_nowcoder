class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int index = 0;
        while (index < array.size()) {
          if (array[index] %2 == 0)
            break;
          index++;
        }
        
        if (index >= array.size())
          return;

        findNextOdd(array, index);
        while (index != -1) {
            moveForward(array, index);
            findNextOdd(array, index);
        }
    }
    
    void findNextOdd(vector<int> &array, int &index) {
        for (int i = index; i < array.size(); i++) {
            if (array[i]%2 != 0) {
                index = i;
                return;
            }
        }
        
        index = -1;
        return;
    }
    
    void moveForward(vector<int> &array, int &index) {
        int i = index-1;
        int j = index;
        while (i >= 0 && array[i] %2 == 0) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            j = i;
            i--;
        }
    }
};