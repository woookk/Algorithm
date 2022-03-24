//
//  14888 - 연산자 끼워넣기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/24.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int A[11];
int MX = -100000000, MN = 100000000;
int oper[4];
int choosed[10];

void calc(int k){
    if(k == N - 1){
        int ans = A[0];
        for(int i = 0; i < N - 1; i++){
            if(choosed[i] == 0){
                ans += A[i + 1];
            }
            else if(choosed[i] == 1){
                ans -= A[i + 1];
            }
            else if(choosed[i] == 2){
                ans *= A[i + 1];
            }
            else {
                ans /= A[i + 1];
            }
        }
        MX = max(ans, MX);
        MN = min(ans, MN);
        return;
    }
    for(int i = 0; i < 4; i++){
        if(oper[i] != 0){
            choosed[k] = i;
            oper[i]--;
            calc(k + 1);
            oper[i]++;
        }
    }
}

int main(){
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> oper[i];
    }
    calc(0);
    cout << MX << "\n" << MN;
    return 0;
}
