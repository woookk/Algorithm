//
//  2436 - 공약수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/21.
//

#include <iostream>
#include <math.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int func(int a, int b){
    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    FASTIO;
    int GCD, LCM, num;
    cin >> GCD >> LCM;
    num = LCM / GCD;
    int a = 0, b = 0;
    for(int i = 1; i <= sqrt(num); i++){
        if(num % i) continue;
        if(func(i, num/i) == 1){
            a = i; b = num/i;
        }
    }
    cout << GCD * a << " " << GCD * b;
}
