//
//  소수 찾기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

bool prime[10000001];

void Sieve(int N){
    for(int i = 2; i <= N; i++){
        prime[i] = true;
    }
    for(int i = 2; i <= N; i++){
        if(prime[i] == 0) continue;
        for(int j = i * 2; j <= N; j += i){
            if(prime[j] == 0) continue;
            prime[j] = 0;
        }
    }
}

int solution(int n) {
    int answer = 0;
    Sieve(n);
    for(int i = 1; i <= n; i++){
        if(prime[i]) answer++;
    }
    return answer;
}
