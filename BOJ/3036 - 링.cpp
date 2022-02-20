//
//  3036 - 링.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/20.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int ring[100];

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
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> ring[i];
    for(int i = 1; i < N; i++){
        int div = GCD(ring[0], ring[i]);
        cout << ring[0]/div << "/" << ring[i]/div << "\n";
    }
    return 0;
}
