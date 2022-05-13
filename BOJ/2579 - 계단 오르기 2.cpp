//
//  2579 - 계단 오르기 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/13.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int s[305];
int n;
int d[305];

int main(){
    FASTIO;
    cin >> n;
    int tot = 0;
    for(int i =  1; i <= n; i++){
        cin >> s[i];
        tot += s[i];
    }
    if(n <= 2) {
        cout << tot;
        return 0;
    }
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    for(int i = 4; i <= n - 1; i++){
        d[i] = min(d[i - 2], d[i - 3]) + s[i];
    }
    cout << tot - min(d[n - 1], d[n - 2]);
}
