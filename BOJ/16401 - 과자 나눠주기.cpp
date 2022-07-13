//
//  16401 - 과자 나눠주기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/13.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int M, N;
vector<int> snack;

bool solve(int x){
    int cur = 0;
    for(int i = 0; i < N; i++){
        cur += snack[i] / x;
    }
    return cur >= M;
}

int main(){
    FASTIO
    cin >> M >> N;
    int len;
    for(int i = 0; i < N; i++){
        cin >> len;
        snack.push_back(len);
    }
    int st = 0;
    int en = 1e9;
    while(st < en){
        int mid = (st + en + 1) / 2;
        if(solve(mid)){
            st = mid;
        }
        else {
            en = mid - 1;
        }
    }
    cout << st;
    return 0;
}
