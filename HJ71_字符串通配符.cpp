#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    string a;
    while (cin >> a) {
        string b;
        cin >> b;
        int m = (int)a.size();
        int n = (int)b.size();
        
        bool trace[n];
        
        for (int i = 0; i < n; i++)
            trace[i] = false;
        
        if (a[0] == b[0] || a[0] == '?' || a[0] == '*') {
            trace[0] = true;
            int i = 1;
            int j = 1;
            if ()
        }
        else {
            cout << false;
        }
        
        
    }
    return 0;
}