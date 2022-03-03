//
//  11729 - 하노이 탑 이동 순서.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/03.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

void func(int a, int b, int n){
    if(n == 1){
        cout << a << " " << b << "\n";
        return;
    }
    func(a, 6 - a - b, n - 1);
    cout << a << " " << b << "\n";
    func(6 - a - b, b, n - 1);
}
int main(){
    FASTIO;
    int N;
    cin >> N;
    cout << (1 << N) - 1 << "\n";
    func(1, 3, N);
    return 0;
}
