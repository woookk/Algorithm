//
//  2981 - 검문.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/21.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int arr[100];
int ans[501];

int GCD(int a, int b){
    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    FASTIO;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int M = abs(arr[1]-arr[0]);
    for(int i = 2; i < N; i++){
        M = GCD(abs(arr[i] - arr[i-1]), M);
    }
    int cnt = 0;
    for(int i = 2; i * i <= M; i++){
        if(M % i == 0){
            ans[cnt++] = i;
            if(i * i != M) ans[cnt++] = M / i;
        }
    }
    ans[cnt++] = M;
    sort(ans, ans + cnt);
    for(int i = 0; i < cnt; i++)
        cout << ans[i] << " ";
    return 0;
}
