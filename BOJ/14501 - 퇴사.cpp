//
//  14501 - 퇴사.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/19.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int T[17], P[17];
int d[17];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> T[i] >> P[i];
    }
    d[0] = 0;
    for(int i = 1; i <= N; i++){
        d[i] = max(d[i], d[i - 1]);
        if(i + T[i] > N + 1) continue;
        d[i + T[i]] = max(d[i + T[i]], d[i] + P[i]);
    }
    cout << *max_element(d + 1, d + N + 2);
    return 0;
}
