//
//  11758 - CCW.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/27.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main(){
    FASTIO;
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int cross = x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
    if(cross == 0) cout << 0;
    else if (cross < 0) cout << -1;
    else cout << 1;
    return 0;
}
