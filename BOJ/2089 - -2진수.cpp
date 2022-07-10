//
//  2089 - -2진수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;
vector<int> v;

int main(){
    FASTIO
    cin >> N;
    if (N == 0) {
        cout << 0;
        return 0;
    }
    while (N) {
        if (N < 0) {
            if (-N % 2 == 0) {
                N = -N / 2;
                v.push_back(0);
            }
            else {
               N = -N / 2 + 1;
               v.push_back(1);
            }
        }
        else {
            v.push_back(N % 2);
            N = -(N / 2);
        }
    }
    reverse(v.begin(), v.end());
    for (int i : v) cout << i;
    return 0;
}
