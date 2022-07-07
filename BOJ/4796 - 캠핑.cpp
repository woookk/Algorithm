//
//  4796 - 캠핑.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/07.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);


int main(){
    FASTIO
    int TC = 1;
    while(1){
        int L, P, V, ans;
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0){
            break;
        }
        ans = 0;
        if(V % P > L){
            ans += L;
        }
        else ans += V % P;
        ans += (V / P) * L;
        cout << "Case " << TC << ": " << ans << "\n";
        TC++;
    }
    return 0;
}
