//
//  1153 - 네 개의 소수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
bool prime[1000001];

void Sieve(){
    for(int i = 2; i <= N; i++){
        prime[i] = true;
    }
    for(int i = 2; i <= N; i++){
        if(prime[i] == 0) continue;
        for(int j = i * 2; j <= N; j += i){
            prime[j] = 0;
        }
    }
}

int main(){
    cin >> N;
    Sieve();
   
    vector<int> ans;
    if(N < 8) {
        cout << -1;
        return 0;
    }
    else{
        if(N % 2){
            ans.push_back(2);
            ans.push_back(3);
            N -= 5;
        }
        else{
            ans.push_back(2);
            ans.push_back(2);
            N -= 4;
        }
        for(int i = 2; i <= N; i++){
            if(prime[i] && prime[N - i]){
                ans.push_back(i);
                ans.push_back(N - i);
                break;
            }
        }
    }
    for(auto v : ans){
        cout << v << " ";
    }
}
