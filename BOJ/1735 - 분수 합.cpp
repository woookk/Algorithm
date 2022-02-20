//
//  1735 - 분수 합.cpp
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
    int A[2], B[2];
    for(int i = 0; i < 2; i++){
        cin >> A[i] >> B[i];
    }
    int a = A[0] * B[1] + A[1] * B[0];
    int b = B[0] * B[1];
    int dv = GCD(a, b);
    cout << a/dv << " " << b/dv;
    return 0;
}
