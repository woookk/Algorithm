//
//  9251 - LCS.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/23.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string a, b;
const int MAX = 1001;
int d[MAX][MAX];

int main(){
    FASTIO;
    cin >> a >> b;
    for(int i = 1; i <= a.length(); i++){
        for(int j = 1; j <= b.length(); j++){
            if(a[i - 1] == b[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
    cout << d[a.length()][b.length()];
    return 0;
}
