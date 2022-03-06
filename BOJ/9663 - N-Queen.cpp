//
//  9663 - N-Queen.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/06.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int cnt = 0;
bool isused1[16];
bool isused2[32];
bool isused3[32];

void func(int cur) {
    if (cur == N){
        cnt++;
        return;
    }
    for(int i = 0; i < N; i++) {
        if(isused1[i] || isused2[i + cur] || isused3[cur - i + N - 1]) continue;
        isused1[i] = 1;
        isused2[i + cur] = 1;
        isused3[cur - i + N -1] = 1;
        func(cur + 1);
        isused1[i] = 0;
        isused2[i + cur] = 0;
        isused3[cur - i + N -1] = 0;
    }
}
int main(){
    FASTIO;
    cin >> N;
    func(0);
    cout << cnt;
}
