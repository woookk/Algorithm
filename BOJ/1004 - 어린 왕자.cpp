//
//  1004 - 어린 왕자.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/27.
//

#include <iostream>
#include <cmath>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int T;

int main(){
    FASTIO
    cin >> T;
    while(T--){
        int x1, y1, x2, y2, n;
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int cx, cy, r;
            cin >> cx >> cy >> r;
            double d1 = sqrt(pow(cx - x1, 2) + pow(cy - y1, 2));
            double d2 = sqrt(pow(cx - x2, 2) + pow(cy - y2, 2));
            if(d1 < r && d2 > r) cnt++;
            else if (d1 > r && d2 < r) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
