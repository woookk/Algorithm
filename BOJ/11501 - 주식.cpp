//
//  11501 - 주식.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/31.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T;
int price[1000001];

int main(){
    FASTIO
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        long long ans = 0;
        for(int i = 0; i < N; i++){
            cin >> price[i];
        }
        int MX = price[N - 1];
        for(int i = N - 2; i >= 0; i--){
            if(price[i] > MX) MX = price[i];
            ans += MX - price[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
