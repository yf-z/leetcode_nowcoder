#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double bs(double n, double b, double e) {
    if (b - e > 0.001) {
        return b;
    }
    
    double middle = (b+e)/2;
    
    double t = pow(middle,3) - n;
    if (abs(t) < 0.001)
        return middle;
    
    if (pow(middle, 3) > n) {
        return bs(n, b, middle);
    }
    
    return bs(n, middle, e);
}

void read() {
    double n;
    while (cin >> n) {
        if (n > 9)
            cout << fixed << setprecision(1) <<  bs(n, 0, n/3) << endl;
        else
            cout << fixed << setprecision(1) <<  bs(n, 0, n/2) << endl;
        
    }
}

int main() {
    read();
    return 0;
}