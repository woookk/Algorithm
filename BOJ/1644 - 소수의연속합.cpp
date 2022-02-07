//
//  1644 - 소수의연속합.cpp
//  Cpp Algorithm
//
//  Created by 민병욱 on 2022/02/07.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

#define MX 4000000
bool prime[MX + 1];
vector<int> v;

void sieve(){
    for(int i = 2; i <= MX; i++)
        prime[i] = 1;
    for(int i = 2; i <= MX; i++){
        if(prime[i] == 0) continue;
        v.push_back(i);
        
        for(int j = 2 * i; j <= MX; j += i){
            if(prime[j] == 0) continue;
            else prime[j] = 0;
        }
    }
}

int main(){
    FASTIO;
    sieve();
    int N;
    cin >> N;
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(N < v[i])
            break;
        int tmp = i;
        int sum = 0;
        while(sum < N && tmp < v.size())
            sum += v[tmp++];
        if(sum == N)
            cnt++;
    }
    cout << cnt;
    return 0;
}
