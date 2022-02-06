//
//  17425 - 약수의 합.cpp
//  Cpp Algorithm
//
//  Created by 민병욱 on 2022/02/06.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int MX = 1000000;
long long g[1000001];
long long f[1000001];

void dp(){
    fill(f, f+1000001, 1);
    for (int i = 2; i <= MX; i++){
        for(int j = 1; i * j <= MX; j++)
            f[i*j] += i;
    }
}

int main(){
    FASTIO;
    int T;
    cin >> T;
    dp();
    for(int i=1; i <= MX; i++){
        g[i] = g[i-1] + f[i];
    }
    while(T--){
        int n;
        cin >> n;
        cout << g[n] << "\n";
    }
    return 0;
}
