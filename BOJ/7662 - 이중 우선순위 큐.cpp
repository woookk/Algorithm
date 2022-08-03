//
//  7662 - 이중 우선순위 큐.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/08/04.
//

#include <iostream>
#include <set>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int TC;

int main(){
    FASTIO
    cin >> TC;
    while(TC--){
        int k;
        cin >> k;
        multiset<int> s;
        while(k--){
            char cmd;
            int n;
            cin >> cmd >> n;
            if(cmd == 'I'){
                s.insert(n);
            }
            else {
                if(s.empty()) continue;
                if(n == 1) s.erase(prev(s.end()));
                else s.erase(s.begin());
            }
        }
        if(s.empty()) cout << "EMPTY\n";
        else cout << *prev(s.end()) << " " << *s.begin() << "\n";
    }
    return 0;
}
