//
//  1120 - 문자열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/26.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string a, b;
int mn = 51;

int main(){
    FASTIO
    cin >> a >> b;
    int lenA = (int)a.length();
    int lenB = (int)b.length();
    for(int i = 0; i < lenB - lenA + 1; i++){
        int cnt = 0;
        for(int j = 0; j < lenA; j++){
            if(a[j] != b[i + j]) cnt++;
        }
        mn = min(mn, cnt);
    }
    cout << mn;
    return 0;
}
