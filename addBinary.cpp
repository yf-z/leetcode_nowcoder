#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string re;
    int digit = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
      int cur = a[i]-'0'+b[i]-'0'+digit;

      if (cur > 1) {
        re += to_string(cur-2);
        digit = 1;
      }
      else {
        re += cur;
        digit = 0;
      }

      i++;
      j++;

      cout << re << endl;
    }

    reverse(re.begin(), re.end());
    
    return re;
  }
};

int main() {
  Solution test;
  cout << test.addBinary("11", "1") << endl;
  return 0;
}