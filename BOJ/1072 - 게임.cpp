//
//  1072 - 게임.cpp
//  Cpp
//
//  Created by 민병욱 on 2023/05/30.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

ll X, Y, Z;
int ans = -1;

int main() {
    FASTIO
    cin >> X >> Y;
    Z = Y * 100 / X;

    if (Z >= 99) {
        cout << ans;
        return 0;
    }
    
    int left = 0, right = 1e9;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        int curZ = (Y + mid) * 100 / (X + mid);
        if (Z < curZ) right = mid - 1;
        else left = mid + 1;
    }
    
    cout << left;
    return 0;
}
