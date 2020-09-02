/*
*   Written By
*   Yifan Zhang
*/

#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int shortest(vector<vector<int>> &map, int &n, int &m, int i, int j) {
    //cout << i << " " << j << endl;
    if (i < 0 || j < 0) {
        return n*m;
    }
    
    if (i == 0 && j == 0) {
        return 1;
    }
    if (map[i][j] == -1) {
        return n*m;
    }
    
    map[i][j] = 1 + min(shortest(map, n, m, i-1, j), shortest(map, n, m, i, j-1));
    return map[i][j];
}

int main() {
    int n;
    while (cin >> n) {
        int m;
        cin >> m;
        vector<vector<int>> map;
        
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int t;
                cin >> t;
                if (t == 1)
                    temp.push_back(-1);
                else
                    temp.push_back(t);
            }
            map.push_back(temp);
        }
        
        map[0][0] = 1;
        vector<string> route;
        int max = shortest(map, n, m, n-1, m-1);
        string temp =   "(" + to_string(n-1) + "," + to_string(m-1) + ")";
        route.push_back(temp);
        int x = n-1;
        int y = m-1;
        for (int i = max-1; i > 0; i--) {
            if (x-1 >= 0 && map[x-1][y] == i) {
                x--;
                temp =   "(" + to_string(x) + "," + to_string(y) + ")";
                route.push_back(temp);
            }
            else if (y-1 >= 0 && map[x][y-1] == i) {
                y --;
                temp =   "(" + to_string(x) + "," + to_string(y) + ")";
                route.push_back(temp);
            }
        }
      
        for (auto it = route.rbegin(); it != route.rend(); it++) {
            cout << *it << endl;
        }
    }
    return 0;
}