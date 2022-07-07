//
//  1456 - 거의 소수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/07.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

long long A, B, ans;
const int MAX = 10000001;
vector<bool> prime(MAX, 1);


void sieve(){
    prime[1] = 0;
    for(long long i = 2; i * i < MAX; i++){
        if(prime[i] == 0) continue;
        for(long long j = i * i; j < MAX; j += i){
            prime[j] = 0;
        }
    }
}


int main(){
    FASTIO
    cin >> A >> B;
    sieve();
    for(long long i = 2; i * i <= B; i++){
        if(prime[i]){
            long long num = i * i;
            while(num <= B){
                if(num >= A)
                    ans++;
                num *= i;
                if(num % i != 0)
                    break;
            }
        }
    }
    cout << ans;
    return 0;
}
