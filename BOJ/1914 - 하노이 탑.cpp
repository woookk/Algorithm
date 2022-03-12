//
//  1914 - 하노이 탑.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/03/13.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
string ans;

void func(int start, int end, long long n){
    if(n == 1){
        cout << start << " " << end << "\n";
        return;
    }
    func(start, 6 - start - end, n - 1);
    func(start, end, 1);
    func(6 - start - end, end, n - 1);
}

void power(int x, int n, char arr[]){
    
}

int main(){
    FASTIO;
    cin >> N;
    if(N <= 20){
        cout << (1 << N) - 1 << "\n";
        func(1, 3, N);
    }
    else {
        ans = to_string(pow(2, N));
        int idx = (int)ans.find('.');
        ans = ans.substr(0, idx);
        ans[ans.length() -1] -= 1;
        cout << ans << "\n";
    }
    return 0;
}
