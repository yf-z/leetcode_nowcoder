#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        map<string, vector<string>> dic;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            string r = s;
            sort(r.begin(), r.end());
            auto it = dic.find(r);
            if (it != dic.end()) {
                it->second.push_back(s);
            }
            else
                dic.insert(pair<string, vector<string>>(r, {s}));
        }
        
        for (auto it = dic.begin(); it != dic.end(); it++) {
            sort(it->second.begin(), it->second.end());
        }
        
        int m;
        string r;
        cin >> r;
        cin >> m;
        
        string t = r;
        sort(t.begin(), t.end());
        
        bool dup = false;
        auto it = dic.find(t);
        if (it == dic.end()) {
            cout << 0 << endl;
            //cout << "" << endl;
        }
        else {
            int dup1 = 0;
            for (auto iit = it->second.begin(); iit != it->second.end(); iit++) {
                if (*iit == r)
                    dup1++;
            }
            
            if (dup1 > 0) {
                cout << it->second.size()-dup1 << endl;
                if (m > it->second.size()-dup1) {
                    true;
                    //cout << "" << endl;
                }
                else {
                    int i = 0;
                    for (int j = 0; j < it->second.size(); j++) {
                        if (it->second.at(j) != r)
                            i++;
                        if (i == m) {
                            cout << it->second.at(j) << endl;
                            break;
                        }
                    }
                }
            }
            else {
                cout << it->second.size() << endl;
                if (m > it->second.size())
                    true;
                    //cout << "" << endl;
                else {
                    cout << it->second.at(m-1) << endl;
                }
            }
        }
    }
    return 0;
}