/*
*   Written By
*   Yifan Zhang
*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void initialize(map<string, string> &dic) {
    dic.insert(pair<string, string>("reset", "reset what"));
    dic.insert(pair<string, string>("reset board", "board fault"));
    dic.insert(pair<string, string>("board delete", "no board at all"));
    dic.insert(pair<string, string>("board add", "where to add"));
    dic.insert(pair<string, string>("reboot backplane", "impossible"));
    dic.insert(pair<string, string>("backplane abort", "install first"));
}

bool match(string &s, string &r) {
    size_t t = s.find(' ');
    size_t t1 = r.find(' ');
    if (t == string::npos && t1 == string::npos) {
        size_t n = min(s.size(), r.size());
        if (s.substr(0, n).compare(r.substr(0, n)) == 0) {
            return true;
        }
        return false;
    }
    else if (t != string::npos && t1 != string::npos) {
        string a, b, a1, b1;
        stringstream(s) >> a >> b;
        stringstream(r) >> a1 >> b1;
        return match(a, a1) && match(b, b1);
    }
    
    return false;
}

int main() {
    string s;
    map<string, string> dic;
    initialize(dic);
    while (getline(cin, s)) {
        vector<string> matched;
        
        for (auto it = dic.begin(); it != dic.end(); it++) {
            string b = it->first;
            if (match(s, b)) {
                matched.push_back(it->first);
            }
        }
        
        if (matched.size() > 1 || matched.size() == 0) {
            cout << "unknown command\n";
        }
        else if (matched.size() == 1) {
            cout << dic[matched.front()] << endl;
        }
    }
    return 0;
}