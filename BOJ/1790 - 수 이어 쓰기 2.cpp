//
//  1790 - 수 이어 쓰기 2.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/08.
//

#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, K;
long long sum;

int main(){
    FASTIO
    cin >> N >> K;
    int cnt = 1;
    for(long long i = 1; i <= N; i *= 10){
        if(sum + cnt * i * 9 >= K){
            long long num = i + (K - sum - 1) / cnt;
            if(num > N){
                cout << -1;
                return 0;
            }
            string tmp = to_string(i + (K - sum - 1) / cnt);
            cout << tmp[(K - sum - 1) % cnt];
            return 0;
        }
        else {
            sum += cnt * i * 9;
        }
        cnt++;
    }
    cout << -1;
    return 0;
}
