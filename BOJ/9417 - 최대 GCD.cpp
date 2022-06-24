//
//  9417 - 최대 GCD.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T;
string s;

int GCD(int a, int b){
    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    FASTIO
    cin >> T;
    getline(cin, s);
    while(T--){
        getline(cin, s);
        vector<int> num;
        int tmp = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                num.push_back(tmp);
                tmp = 0;
            }
            else {
                tmp = tmp * 10 + (s[i] - '0');
            }
        }
        num.push_back(tmp);
        
        int ans = -1;
        for(int i = 0; i < num.size() - 1; i++){
            for(int j = i + 1; j < num.size(); j++){
                ans = max(ans, GCD(num[i], num[j]));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
