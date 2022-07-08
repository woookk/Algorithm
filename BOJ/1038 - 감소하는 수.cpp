//
//  1038 - 감소하는 수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/08.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N;

int main(){
    FASTIO
    cin >> N;
    vector<long long> dec_num;
    for(int i = 1; i <= 1023; i++){
        long long num = 0;
        int tmp_i = i;
        for(int idx = 9; idx >= 0; idx--){
            if(tmp_i % 2 == 1)
                num = 10 * num + idx;
            tmp_i /= 2;
        }
        dec_num.push_back(num);
    }
    sort(dec_num.begin(), dec_num.end());
    if(N > 1022){
        cout << -1;
    }
    else {
        cout << dec_num[N];
    }
    return 0;
}
