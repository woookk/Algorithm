//
//  17087 - 숨바꼭질 6.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/20.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int GCD(int a, int b){
    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    FASTIO;
    int N, S;
    cin >> N >> S;
    int A[100001];
    for(int i = 0; i < N; i++)
        cin >> A[i];
    int ans = abs(A[0] - S);
    for(int i = 1; i < N; i++){
        ans = GCD(ans, abs(A[i] - S));
    }
    cout << ans;
    return 0;
}
