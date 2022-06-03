//
//  5582 - 공통 부분 문자열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/03.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string a, b;
const int MAX = 4001;
int d[MAX][MAX];
int ans;

int main(){
    FASTIO
    cin >> a >> b;
    for(int i = 1; i <= a.length(); i++){
        for(int j = 1; j <= b.length(); j++){
            if(a[i - 1] == b[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans;
    return 0;
}
