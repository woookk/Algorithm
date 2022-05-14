//
//  11726 - 2×n 타일링.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/14.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int d[1001];

int main(){
    FASTIO;
    cin >> N;
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= N; i++){
        d[i] = (d[i - 1] + d[i - 2]) % 10007;
    }
    cout << d[N];
}
