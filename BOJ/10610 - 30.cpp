//
//  10610 - 30.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/25.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

string N;

bool cmp(char &a, char &b){
    return a > b;
}

int main(){
    FASTIO;
    cin >> N;
    
    int sum = 0;
    for(int idx = 0; idx < N.length(); idx++){
        sum += N[idx] - '0';
    }
    sort(N.begin(), N.end(), cmp);
    if(N[N.length() - 1] != '0' || sum % 3 != 0)
        cout << -1;
    else {
        cout << N;
    }
    return 0;
}
