// https://www.nowcoder.com/practice/66ca0e28f90c42a196afd78cc9c496ea?tpId=37&&tqId=21256&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking

/*
*   Written By
*   Yifan Zhang
*/

#include <iostream>
#include <math.h>

using namespace std;

long long biToDec(string s) {
    long long n = (long long)s.size()-1;
    long long re = 0;
    for (char c:s) {
        if (c == '1') {
            re += pow(2, n);
        }
        n--;
    }
    
    return re;
}

string decToBi(long long n) {
    if (n == 1) {
        return "1";
    }
    
    if (n == 0) {
        return "0";
    }
    
    if (n%2 == 1) {
        return decToBi(n/2)+"1";
    }
    
    return decToBi(n/2)+"0";
}

string convert(string s) {
    string re;
    string t1;
    string t2;
    
    size_t t = s.find('.');
    t2 = decToBi(stoi(s.substr(0,t)));
    if (t2.size() < 8) {
        t2 = string(8-t2.size(), '0')+t2;
    }
    re += t2;
    s = s.substr(t+1);
    
    t = s.find('.');
    t2 = decToBi(stoi(s.substr(0,t)));
    if (t2.size() < 8) {
        t2 = string(8-t2.size(), '0')+t2;
    }
    re += t2;
    s = s.substr(t+1);
    
    t = s.find('.');
    t2 = decToBi(stoi(s.substr(0,t)));
    if (t2.size() < 8) {
        t2 = string(8-t2.size(), '0')+t2;
    }
    re += t2;
    s = s.substr(t+1);
    
    t2 = decToBi(stoi(s));
    if (t2.size() < 8) {
        t2 = string(8-t2.size(), '0')+t2;
    }
    re += t2;

    return re;
}

string reverse(string s) {
    string re;
    while (s.size() >= 8) {
        string t = s.substr(0, 8);
        re += to_string(biToDec(t));
        re += ".";
        s = s.substr(8);
    }
    
    re = re.substr(0, re.size()-1);
    return re;
}

int main() {
    string s;
    while (cin >> s) {
        long long r;
        cin >> r;
        
        string t = convert(s);
        //cout << t << endl;
        cout << biToDec(t) << endl;
        
        t = decToBi(r);
        if (t.size() < 32) {
            t = string(32-t.size(), '0') + t;
        }
        
        cout << reverse(t) << endl;
    }
    return 0;
}