#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int l = BSL(data, k, 0, data.size()), r = BSR(data, k, 0, data.size());
        if (data[l] != k || data[r] != k)
            return 0;
        
        return r-l+1;
    }
    
    int BSL(vector<int> &data, int &k, int b, int e) {
        cout << b << " " << e << endl;
        if (b >= e || b+1 == e){
              if (data[b] == k) 
                return b;
              else {
                return b+1;
              }
        }
        
        int middle = b+(e-b)/2;
        cout << middle << endl;
        
        if (data[middle] >= k)
            return BSL(data, k, b, middle-1);
        
        return BSL(data, k, middle, e);
    }
    
    int BSR(vector<int> &data, int &k, int b, int e) {
        if (b >= e || b+1 == e) {
            if (data[b] == k)
                return b;
              else {
                return b-1;
              }
        }
            
        
        int middle = b+(e-b)/2;
        
        if (data[middle] <= k) {
            return BSR(data, k, middle+1, e);
        }
        
        return BSR(data, k, b, middle);
    }
};

int main() {
  Solution test;
  cout << test.GetNumberOfK({1,2,3,3,3,3,4,5}, 3) << endl;
}