/*
*   Written By
*   Yifan Zhang
*/

#include <math.h>
#include <iostream>

using namespace std;

void read() {
    long a;
    cin >> a;
    
    while (a % 2 == 0) {
        cout << 2 << " ";
        a = a/2;
    }
    
    for (long i = 3; i < (long)sqrt(a); i += 2) {
        while (a % i == 0) {
            cout << i << " ";
            a = a/i;
        }
    }
    
    if (a > 2) {
        cout << a << " ";
    }
    
    return;
}

int main() {
    read();
    return 0;
}