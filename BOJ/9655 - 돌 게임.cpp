//
//  9655.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/30.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main(){
    FASTIO
    cin >> N;
    if(N % 2 == 0) cout << "CY";
    else cout << "SK";
    return 0;
}
