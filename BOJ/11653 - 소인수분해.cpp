//
//  11653 - 소인수분해.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/06.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n;

int main(){
    FASTIO;
    cin >> n;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            cout << i << "\n";
            n /= i;
        }
    }
    if(n != 1) cout << n;
    return 0;
}
