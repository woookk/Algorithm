//
//  2270 - 하노이 탑.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/17.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, ans;
int pole[3];
int num[100001], pos[100001];

void calc(int n){
    num[0] = 1;
    for(int i = 1; i <= n; i++){
        num[i] = (num[i - 1] * 2) % 1000000;
    }
}
void func(int N, int end){
    if(N == 0) return;
    
    int now = pos[N];
    int sub = 6 - now - end;
    
    if(now == end) func(N - 1, end);
    else {
        ans += num[N - 1];
        ans %= 1000000;
        func(N - 1, sub);
    }
}

int main(){
    FASTIO;
    cin >> n;
    for(int i = 0; i < 3; i++){
        cin >> pole[i];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < pole[i]; j++){
            int tmp;
            cin >> tmp;
            pos[tmp] = i + 1;
        }
    }
    calc(n);
    func(n, pos[n]);
    
    cout << pos[n] << "\n" << ans;
    return 0;
}
