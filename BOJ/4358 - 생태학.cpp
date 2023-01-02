//
//  4358 - 생태학.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/01/02.
//

#include <iostream>
#include <map>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

map<string, int> mp;
int cnt;

int main() {
    FASTIO
    string s;
    while(getline(cin, s)) {
        mp[s] += 1;
        cnt++;
    }
    
    cout.precision(4);
    cout << fixed;
    
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second * 100.0 / cnt << "\n";
        
    }
    return 0;
}
