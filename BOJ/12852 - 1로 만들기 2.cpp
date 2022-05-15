//
//  12852 - 1로 만들기 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/15.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int d[1000001];
int pre[1000001];
int N;

int main(){
    FASTIO;
    cin >> N;
    d[1] = 0;
    for(int i = 2; i <= N; i++){
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;
        if(i % 2 == 0 && d[i] > d[i / 2] + 1){
            d[i] = d[i / 2] + 1;
            pre[i] = i / 2;
        }
        if(i % 3 == 0 && d[i] > d[i / 3] + 1){
            d[i] = d[i / 3] + 1;
            pre[i] = i / 3;
        }
    }
    cout << d[N] << "\n";
    int cur = N;
    while(1){
        cout << cur << ' ';
        if(cur == 1) break;
        cur = pre[cur];
    }
    return 0;
}
