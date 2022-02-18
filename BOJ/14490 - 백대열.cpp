//
//  14490 - 백대열.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/18.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int GCD(int a, int b){
    while(b != 0){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    FASTIO;
    int n, m;
    char tmp;
    cin >> n >> tmp >> m;
    int dv = GCD(n, m);
    cout << n/dv << tmp << m/dv;
    return 0;
}
