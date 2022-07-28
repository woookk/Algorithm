//
//  9375 - 패션왕 신해빈.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/28.
//

#include <iostream>
#include <unordered_map>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int TC, n, ans;

int main(){
    FASTIO;
    cin >> TC;
    while(TC--){
        cin >> n;
        unordered_map<string, int> clothings;
        ans = 1;
        while(n--) {
            string item, kind;
            cin >> item >> kind;
            clothings[kind]++;
        }
        for(auto c: clothings) ans *= c.second + 1;
        cout << ans - 1 << "\n";
    }
    return 0;
}
