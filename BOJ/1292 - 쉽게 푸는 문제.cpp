//
//  1292 - 쉽게 푸는 문제.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/02/12.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int main(){
    FASTIO;
    int A, B;
    cin >> A >> B;
    int idx = 1, cnt = 0, sum = 0;
    for(int i = 1; i<= B; i++){
        if(i >= A)
            sum += idx;
        cnt++;
        if(cnt == idx){
            cnt = 0;
            idx++;
        }
    }
    cout << sum;
    return 0;
}
