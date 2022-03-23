//
//  10819 - 차이를 최대로.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/23.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, ans;
int num[8], A[8];
bool isused[8];

void func(int k){
    if(k == N){
        int sum = 0;
        for(int i = 0; i < N - 1; i++){
            sum += abs(A[i + 1] - A[i]);
        }
        ans = max(sum, ans);
        return;
    }
    for(int i = 0; i < N; i++){
        if(!isused[i]){
            A[k] = num[i];
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
    
}
int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    func(0);
    cout << ans;
    return 0;
}
