//
//  11053 - 가장 긴 증가하는 부분 수열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/19.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
int A[1001], d[1001];

int main(){
    FASTIO;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        d[i] = 1;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            if(A[j] < A[i]) d[i] = max(d[i], d[j] + 1);
        }
    }
    cout << *max_element(d + 1, d + N + 1);
    return 0;
}
