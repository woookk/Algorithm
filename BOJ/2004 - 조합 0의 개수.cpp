//
//  2004 - 조합 0의 개수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/03.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, m, ans[2];

int amount2(int a) {
    int val = a;
    int cnt = 0;
    while (val > 0) {
        val /= 2;
        cnt += val;
    }
    return cnt;
}
int amount5(int a) {
    int val = a;
    int cnt = 0;
    while (val > 0) {
        val /= 5;
        cnt += val;
    }
    return cnt;
}

int main(){
    FASTIO;
    cin >> n >> m;
    ans[0] = amount2(n) - amount2(m) - amount2(n - m);
    ans[1] = amount5(n) - amount5(m) - amount5(n - m);
    cout << min(ans[0], ans[1]);
    return 0;
}
