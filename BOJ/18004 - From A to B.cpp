//
//  18004 - From A to B.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/12/20.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int a, b;
int cnt;

int main() {
    FASTIO
    cin >> a >> b;
    
    while (a != b) {
        if (a == b) {
            cout << 0;
            return 0;
        }
        else if (a < b) {
            a++;
            cnt++;
        }
        else {
            if (a % 2 == 1) {
                a++;
                cnt++;
            }
            else {
                a /= 2;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
