#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void move(string s, int &x, int &y) {
    if (s.front() == 'A') {
        x -= stoi(s.substr(1));
    }
    
    if (s.front() == 'S') {
        y -= stoi(s.substr(1));
    }
    
    if (s.front() == 'D') {
        x += stoi(s.substr(1));
    }
    
    if (s.front() == 'W') {
        y += stoi(s.substr(1));
    }
    
    //cout << s << " --> ";
    //cout << x << " " << y << endl;
    return;
}

bool isnumber(string s) {
    for (char c:s) {
        if (!isdigit(c))
            return false;
    }
    
    return true;
}

bool islegal(string s) {
    if (s.size() > 3 || s.size() < 2) {
        return false;
    }
    
    if ((s.front() == 'A' || s.front() == 'W' || s.front() == 'S' || s.front() == 'D') && isnumber(s.substr(1))) {
        return true;
    }
    
    return false;
}

pair<int, int> calc(string &s, int x, int y) {
    size_t t = s.find(';');
    while (t != string::npos) {
        if (islegal(s.substr(0,t))) {
            move(s.substr(0, t), x, y);
        }
        
        s = s.substr(t+1);
        t = s.find(';');
    }
    
    if (islegal(s)) {
        move(s, x, y);
    }
    
    return pair<int, int>(x, y);
}

int main() {
    string s;
    while (getline(cin, s)) {
        pair<int, int> re = calc(s, 0, 0);
        cout << re.first << "," << re.second << endl;
    }
    return 0;
}