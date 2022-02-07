//
//  1016 - 제곱 ㄴㄴ 수.cpp
//  Cpp Algorithm
//
//  Created by 민병욱 on 2022/02/07.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

bool square[1000001];

void sieve(long long mn, long long mx){
    for(long long i = 2; i * i <= mx; i++){
        long long n = mn / (i * i);
        if(mn % (i * i)) n++;
        while(n * i * i <= mx){
            square[n * i * i - mn] = 1;
            n++;
        }
    }
}

int main(){
    FASTIO;
    long long mn, mx;
    cin >> mn >> mx;
    sieve(mn, mx);
    int cnt = 0;
    for(int i = 0; i <= mx-mn; i++)
        if(!square[i]) cnt++;
    cout << cnt;
    return 0;
}
